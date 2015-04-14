#include "OCVCamera.h"

OCVCamera::OCVCamera(int cameraIndex)
{
	this->cameraIndex = cameraIndex;
}

void OCVCamera::init()
{
	camera = new VideoCapture(cameraIndex);
	rawImage = new RawImage();
}

void OCVCamera::done()
{
	if(camera)
		delete camera;
	if(rawImage)
		delete rawImage;
}

RawData* OCVCamera::getData()
{
	*camera >> rawImage->image;
	return (RawData*)rawImage;
}

bool OCVCamera::dataAvailable()
{
	return true;
}