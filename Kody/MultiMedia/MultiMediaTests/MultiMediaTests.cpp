// MultiMediaTests.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>

#include "ImageCompressorTests.h"
#include "ImageDecompressorTests.h"

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	try
	{
	ImageCompressorTests imageCompressorTests;
	imageCompressorTests.processDataTest();

	ImageDecompressorTests imageDecompressorTests;
	imageDecompressorTests.processDataTest();
	}
	catch(exception* ex)
	{
		cout << ex->what();
		delete ex;
	}

	return 0;
}

