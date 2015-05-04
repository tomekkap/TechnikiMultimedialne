#include <exception>

#include "ImageCompressorTests.h"

#include <ImageCompressor.h>
#include <RawImage.h>
#include <CompressedData.h>

#include <opencv2\opencv.hpp>

using namespace std;
using namespace cv;

void ImageCompressorTests::processDataTest()
{
	ImageCompressor imageCompressor;
	RawImage rawImage;
	rawImage.image.create(8, 8, CV_8UC1);
	unsigned char* dataPtr = rawImage.image.data;

	*dataPtr++ = 1;
	*dataPtr++ = 2;
	*dataPtr++ = 3;
	*dataPtr++ = 4;
	*dataPtr++ = 0;
	*dataPtr++ = 5;
	*dataPtr++ = 17;
	*dataPtr++ = 36;

	*dataPtr++ = 3;
	*dataPtr++ = 2;
	*dataPtr++ = 8;
	*dataPtr++ = 5;
	*dataPtr++ = 5;
	*dataPtr++ = 7;
	*dataPtr++ = 9;
	*dataPtr++ = 11;

	*dataPtr++ = 7;
	*dataPtr++ = 3;
	*dataPtr++ = 5;
	*dataPtr++ = 4;
	*dataPtr++ = 12;
	*dataPtr++ = 8;
	*dataPtr++ = 10;
	*dataPtr++ = 11;

	*dataPtr++ = 8;
	*dataPtr++ = 2;
	*dataPtr++ = 11;
	*dataPtr++ = 12;
	*dataPtr++ = 36;
	*dataPtr++ = 50;
	*dataPtr++ = 55;
	*dataPtr++ = 11;

	*dataPtr++ = 1;
	*dataPtr++ = 2;
	*dataPtr++ = 2;
	*dataPtr++ = 1;
	*dataPtr++ = 5;
	*dataPtr++ = 7;
	*dataPtr++ = 8;
	*dataPtr++ = 9;

	*dataPtr++ = 3;
	*dataPtr++ = 4;
	*dataPtr++ = 12;
	*dataPtr++ = 13;
	*dataPtr++ = 12;
	*dataPtr++ = 36;
	*dataPtr++ = 50;
	*dataPtr++ = 61;

	*dataPtr++ = 55;
	*dataPtr++ = 53;
	*dataPtr++ = 50;
	*dataPtr++ = 61;
	*dataPtr++ = 2;
	*dataPtr++ = 4;
	*dataPtr++ = 8;
	*dataPtr++ = 6;

	*dataPtr++ = 17;
	*dataPtr++ = 30;
	*dataPtr++ = 34;
	*dataPtr++ = 25;
	*dataPtr++ = 7;
	*dataPtr++ = 17;
	*dataPtr++ = 36;
	*dataPtr++ = 15;
	
	imageCompressor.init();
	CompressedData* compressedData = (CompressedData*)imageCompressor.processData(&rawImage);

	_ASSERT(compressedData->length == 16);

	_ASSERT(compressedData->buffer[0] == 9);
	_ASSERT(compressedData->buffer[1] == 3);
	_ASSERT(compressedData->buffer[2] == 4);
	_ASSERT(compressedData->buffer[3] == 139);

	_ASSERT(compressedData->buffer[4] == 44);
	_ASSERT(compressedData->buffer[5] == 9);
	_ASSERT(compressedData->buffer[6] == 16);
	_ASSERT(compressedData->buffer[7] == 14);

	_ASSERT(compressedData->buffer[8] == 44);
	_ASSERT(compressedData->buffer[9] == 6);
	_ASSERT(compressedData->buffer[10] == 0);
	_ASSERT(compressedData->buffer[11] == 247);

	_ASSERT(compressedData->buffer[12] == 46);
	_ASSERT(compressedData->buffer[13] == 8);
	_ASSERT(compressedData->buffer[14] == 7);
	_ASSERT(compressedData->buffer[15] == 2);

	imageCompressor.done();
}
