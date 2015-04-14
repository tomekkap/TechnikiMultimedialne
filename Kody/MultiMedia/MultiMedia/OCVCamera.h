#pragma once

#include <opencv2\opencv.hpp>

#include "DataProducer.h"
#include "RawImage.h"

using namespace cv;

class OCVCamera: public DataProducer
{
public:
	OCVCamera(int cameraIndex);
	virtual void init();
	virtual void done();
	virtual RawData* getData();
	virtual bool dataAvailable();
private:
	VideoCapture* camera;
	RawImage* rawImage;
	int cameraIndex;
};

