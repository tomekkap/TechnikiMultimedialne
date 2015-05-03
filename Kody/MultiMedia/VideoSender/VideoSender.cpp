// VideoSender.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <MultiMediaSystem.h>
#include <OCVCamera.h>
#include <ImageCompressor.h>
#include <NetDataSender.h>
#include <MockFeatureExtractor.h>
#include <MockClassifier.h>
#include <MockEffector.h>

int _tmain(int argc, _TCHAR* argv[])
{
	MultiMediaSystem* multiMediaSystem = new MultiMediaSystem(new OCVCamera(0), new ImageCompressor(), 
		new NetDataSender(), new MockFeatureExtractor(), new MockClassifier(), new MockEffector());
	multiMediaSystem->init();
	multiMediaSystem->run();
	multiMediaSystem->done();
	delete multiMediaSystem;
	return 0;
}

