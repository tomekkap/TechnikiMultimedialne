#include "ColorImageProcessor.h"
#include "RawImage.h"

void ColorImageProcessor::init()
{
	processedImage = new ProcessedImage();
}

void ColorImageProcessor::done()
{
	if(processedImage)
		delete processedImage;
}

ProcessedData* ColorImageProcessor::processData(RawData* rawData)
{
	((RawImage*)rawData)->image.copyTo(processedImage->image);
	return (ProcessedData*)processedImage;
}