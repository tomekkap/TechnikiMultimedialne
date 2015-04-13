#pragma once

#include <opencv2\opencv.hpp>

#include "ProcessedData.h"

using namespace cv;

class ProcessedImage: ProcessedData
{
public:
	Mat image;
};

