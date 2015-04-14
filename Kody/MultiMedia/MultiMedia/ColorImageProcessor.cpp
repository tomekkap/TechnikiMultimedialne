#include "ColorImageProcessor.h"
#include "RawImage.h"

void ColorImageProcessor::init()
{
	processedImage = new ProcessedImage();
	HMin = 0;
	HMax = 255;
	SMin = 0;
	SMax = 255;
	VMin = 0;
	VMax = 255;
	namedWindow("Settings");
	createTrackbar("HMin", "Settings", &HMin, HMax);
	createTrackbar("HMax", "Settings", &HMax, 255);
	createTrackbar("SMin", "Settings", &SMin, SMax);
	createTrackbar("SMax", "Settings", &SMax, 255);
	createTrackbar("VMin", "Settings", &VMin, VMax);
	createTrackbar("VMax", "Settings", &VMax, 255);
}

void ColorImageProcessor::done()
{
	if(processedImage)
		delete processedImage;
	destroyWindow("Settings");
}

ProcessedData* ColorImageProcessor::processData(RawData* rawData)
{
	Mat temp, temp1;
	cvtColor(((RawImage*)rawData)->image, temp, CV_RGB2HSV);
	inRange(temp, Scalar(HMin, SMin, VMin), Scalar(HMax, SMax, VMax), temp1);
	erode(temp1, processedImage->image, Mat());
	return (ProcessedData*)processedImage;
}