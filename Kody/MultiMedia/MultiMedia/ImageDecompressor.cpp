#include <exception>

#include "ImageDecompressor.h"
#include "CompressedDataRead.h"

using namespace std;

void ImageDecompressor::init()
{
	processedImage = new ProcessedImage();
	if(!processedImage)
		throw new exception("Cannot allocate memory for the processed image.");
}

void ImageDecompressor::done()
{
	if(processedImage)
		delete processedImage;
}

ProcessedData* ImageDecompressor::processData(RawData* rawData)
{
	processedImage->image.create(480, 640, CV_8UC3);
	memcpy(processedImage->image.data, ((CompressedDataRead*)rawData)->buffer, ((CompressedDataRead*)rawData)->length);
	return (ProcessedData*)processedImage;
}