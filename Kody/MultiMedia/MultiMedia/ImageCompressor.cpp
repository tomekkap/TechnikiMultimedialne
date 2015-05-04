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
	if(NULL == compressedData->buffer)
	{
		compressedData->length = ((RawImage*)rawData)->image.size().width*((RawImage*)rawData)->image.size().height*3;
		compressedData->buffer = new unsigned char[compressedData->length];
		if(!compressedData->buffer)
			throw new exception("Cannot allocate memory for the compressed data.");
	}
	memcpy(compressedData->buffer, ((RawImage*)rawData)->image.data, compressedData->length);
	return (ProcessedData*)compressedData;
}