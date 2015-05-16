#include <exception>

#include "ImageCompressor.h"
#include "RawImage.h"

using namespace std;

void ImageCompressor::init()
{
	compressedData = new CompressedData();
	if(!compressedData)
		throw new exception("Cannot allocate memory for the compressed data.");
	compressedData->length = 0;
	compressedData->buffer = NULL;
	grayImage.empty();
}

void ImageCompressor::done()
{
	if(compressedData)
	{
		if(compressedData->buffer)
			delete[] compressedData->buffer;
		delete compressedData;
	}
}

ProcessedData* ImageCompressor::processData(RawData* rawData)
{
	// refaktoryzacja tego fragmentu
	if(grayImage.size().width == 0)
		grayImage.create(((RawImage*)rawData)->image.size().width, ((RawImage*)rawData)->image.size().height, CV_8UC1);

	if(((RawImage*)rawData)->image.type() != CV_8UC1)
		cvtColor(((RawImage*)rawData)->image, grayImage, CV_BGR2GRAY);
	else
		((RawImage*)rawData)->image.copyTo(grayImage);

	if(NULL == compressedData->buffer)
	{
		compressedData->length = grayImage.size().width*grayImage.size().height/4;
		compressedData->buffer = new unsigned char[compressedData->length];
		if(!compressedData->buffer)
			throw new exception("Cannot allocate memory for the compressed data.");
	}

	unsigned char* bufferPtr = compressedData->buffer;

	for(int j=0; j<grayImage.size().height; j+=4)
		for(int i=0; i<grayImage.size().width; i+=4)
		{
			SmallWindow smallWindow = extractWindow(grayImage, i, j);
			unsigned char mean = calculateMean(smallWindow);
			SmallWindow maskWindow = buildMask(smallWindow, mean);
			unsigned char meanHi = calculateMeanHi(smallWindow, maskWindow);
			unsigned char meanLo = calculateMeanLo(smallWindow, maskWindow);
			unsigned short binaryMask = createBinaryMask(maskWindow);
			*bufferPtr++ = meanHi;
			*bufferPtr++ = meanLo;
			*bufferPtr++ = (binaryMask >> 8) & 0x00FF;
			*bufferPtr++ = binaryMask & 0x00FF;
		}

	//memcpy(compressedData->buffer, ((RawImage*)rawData)->image.data, compressedData->length);

	return (ProcessedData*)compressedData;
}

SmallWindow ImageCompressor::extractWindow(Mat image, int leftX, int topY)
{
	SmallWindow window;
	int counter = 0;
	for(int j=0; j<4; j++)
		for(int i=0; i<4; i++)
			window.data[counter++] = *(image.data + (topY+j)*image.size().width+(leftX+i));
	return window;
}

unsigned char ImageCompressor::calculateMean(SmallWindow window)
{
	double sum = 0.0;
	for(int i=0; i<16; i++)
		sum += window.data[i];
	return (unsigned char)(sum/16+0.5);
}

SmallWindow ImageCompressor::buildMask(SmallWindow window, unsigned char mean)
{
	SmallWindow mask;
	for(int i=0; i<16; i++)
		mask.data[i] = (window.data[i] > mean)?1:0;
	return mask;
}

unsigned char ImageCompressor::calculateMeanHi(SmallWindow window, SmallWindow mask)
{
	double sum = 0.0;
	int counter = 0;
	for(int i=0; i<16; i++)
		if(mask.data[i] > 0)
		{
			sum += window.data[i];
			counter++;
		}
	if(counter == 0)
		return 0;
	return (unsigned char)(sum/counter+0.5);
}

unsigned char ImageCompressor::calculateMeanLo(SmallWindow window, SmallWindow mask)
{
	double sum = 0.0;
	int counter = 0;
	for(int i=0; i<16; i++)
		if(mask.data[i] == 0)
		{
			sum += window.data[i];
			counter++;
		}
	if(counter == 0)
		return 0;
	return (unsigned char)(sum/counter+0.5);
}

unsigned short ImageCompressor::createBinaryMask(SmallWindow mask)
{
	unsigned short binaryMask = 0x0000;
	unsigned short bitMask = 0x8000;
	for(int i=0; i<16; i++)
	{
		if(mask.data[i] > 0)
			binaryMask |= bitMask;
		bitMask /= 2;
	}
	return binaryMask;
}