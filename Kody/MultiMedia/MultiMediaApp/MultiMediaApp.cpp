// MultiMediaApp.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <opencv2\opencv.hpp>

#include "MultiMediaSystem.h"
#include "MockDataProducer.h"
#include "MockDataProcessor.h"
#include "MockDataConsumer.h"
#include "MockFeatureExtractor.h"
#include "MockClassifier.h"
#include "MockEffector.h"

#include "OCVCamera.h"
#include "ColorImageProcessor.h"
#include "ImageViewer.h"

int _tmain(int argc, _TCHAR* argv[])
{
	MultiMediaSystem* multiMediaSystem = new MultiMediaSystem(new OCVCamera(), new ColorImageProcessor(), 
		new ImageViewer(), new MockFeatureExtractor(), new MockClassifier(), new MockEffector());
	multiMediaSystem->init();
	multiMediaSystem->run();
	multiMediaSystem->done();
	delete multiMediaSystem;
	return 0;
}

