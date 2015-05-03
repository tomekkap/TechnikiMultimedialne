// VideoReceiver.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <MultiMediaSystem.h>
#include <NetDataReceiver.h>
#include <ImageDecompressor.h>
#include <ImageViewer.h>
#include <MockFeatureExtractor.h>
#include <MockClassifier.h>
#include <MockEffector.h>

int _tmain(int argc, _TCHAR* argv[])
{
	MultiMediaSystem* multiMediaSystem = new MultiMediaSystem(new NetDataReceiver(), new ImageDecompressor(), 
		new ImageViewer(), new MockFeatureExtractor(), new MockClassifier(), new MockEffector());
	multiMediaSystem->init();
	multiMediaSystem->run();
	multiMediaSystem->done();
	delete multiMediaSystem;
	return 0;
}

