#pragma once

#include <opencv2\opencv.hpp>

#include "DataProcessor.h"
#include "CompressedData.h"
#include "SmallWindow.h"

using namespace cv;

class ImageCompressor: public DataProcessor
{
public:
	virtual void init();
	virtual void done();
	virtual ProcessedData* processData(RawData* rawData);
private:
	SmallWindow extractWindow(Mat image, int leftX, int topY);
	unsigned char calculateMean(SmallWindow window);
	SmallWindow buildMask(SmallWindow window, unsigned char mean);
	unsigned char calculateMeanHi(SmallWindow window, SmallWindow mask);
	unsigned char calculateMeanLo(SmallWindow window, SmallWindow mask);
	unsigned short createBinaryMask(SmallWindow mask);
	CompressedData* compressedData;
	Mat grayImage;
};

