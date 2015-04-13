#include <opencv2\opencv.hpp>

#include "ImageViewer.h"
#include "ProcessedImage.h"

using namespace cv;

void ImageViewer::init()
{
	namedWindow("Processed Image");
}

void ImageViewer::done()
{
	destroyWindow("Processed Image");
}

void ImageViewer::setData(ProcessedData* processedData)
{
	imshow("Processed Image", ((ProcessedImage*)processedData)->image);
	waitKey(10);
}
