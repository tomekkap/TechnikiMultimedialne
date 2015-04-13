#pragma once

#include <opencv2\opencv.hpp>

#include "RawData.h"

using namespace cv;

class RawImage: public RawData
{
public:
	Mat image;
};

