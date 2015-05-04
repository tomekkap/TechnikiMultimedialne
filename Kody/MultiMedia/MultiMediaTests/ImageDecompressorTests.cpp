#include <exception>

#include "ImageDecompressorTests.h"

#include <ImageDecompressor.h>
#include <CompressedDataRead.h>
#include <ProcessedImage.h>

using namespace std;

void ImageDecompressorTests::processDataTest()
{
	ImageDecompressor imageDecompressor;
	CompressedDataRead compressedDataRead;
	compressedDataRead.length = 16;
	compressedDataRead.buffer = new unsigned char[16];
	
	compressedDataRead.buffer[0] = 9;
	compressedDataRead.buffer[1] = 3;
	compressedDataRead.buffer[2] = 4;
	compressedDataRead.buffer[3] = 139;

	compressedDataRead.buffer[4] = 44;
	compressedDataRead.buffer[5] = 9;
	compressedDataRead.buffer[6] = 16;
	compressedDataRead.buffer[7] = 14;

	compressedDataRead.buffer[8] = 44;
	compressedDataRead.buffer[9] = 6;
	compressedDataRead.buffer[10] = 0;
	compressedDataRead.buffer[11] = 247;

	compressedDataRead.buffer[12] = 46;
	compressedDataRead.buffer[13] = 8;
	compressedDataRead.buffer[14] = 7;
	compressedDataRead.buffer[15] = 2;

	ProcessedImage* processedImage  = (ProcessedImage*)imageDecompressor.processData(&compressedDataRead);

	_ASSERT(processedImage->image.size().width == 8);
	_ASSERT(processedImage->image.size().height == 8);

	_ASSERT(processedImage->image.data[0] == 3);
	_ASSERT(processedImage->image.data[1] == 3);
	_ASSERT(processedImage->image.data[2] == 3);
	_ASSERT(processedImage->image.data[3] == 3);
	_ASSERT(processedImage->image.data[4] == 9);
	_ASSERT(processedImage->image.data[5] == 9);
	_ASSERT(processedImage->image.data[6] == 9);
	_ASSERT(processedImage->image.data[7] == 44);

	_ASSERT(processedImage->image.data[8] == 3);
	_ASSERT(processedImage->image.data[9] == 3);
	_ASSERT(processedImage->image.data[10] == 9);
	_ASSERT(processedImage->image.data[11] == 3);
	_ASSERT(processedImage->image.data[12] == 9);
	_ASSERT(processedImage->image.data[13] == 9);
	_ASSERT(processedImage->image.data[14] == 9);
	_ASSERT(processedImage->image.data[15] == 9);

	_ASSERT(processedImage->image.data[16] == 9);
	_ASSERT(processedImage->image.data[17] == 3);
	_ASSERT(processedImage->image.data[18] == 3);
	_ASSERT(processedImage->image.data[19] == 3);
	_ASSERT(processedImage->image.data[20] == 9);
	_ASSERT(processedImage->image.data[21] == 9);
	_ASSERT(processedImage->image.data[22] == 9);
	_ASSERT(processedImage->image.data[23] == 9);

	_ASSERT(processedImage->image.data[24] == 9);
	_ASSERT(processedImage->image.data[25] == 3);
	_ASSERT(processedImage->image.data[26] == 9);
	_ASSERT(processedImage->image.data[27] == 9);
	_ASSERT(processedImage->image.data[28] == 44);
	_ASSERT(processedImage->image.data[29] == 44);
	_ASSERT(processedImage->image.data[30] == 44);
	_ASSERT(processedImage->image.data[31] == 9);

	_ASSERT(processedImage->image.data[32] == 6);
	_ASSERT(processedImage->image.data[33] == 6);
	_ASSERT(processedImage->image.data[34] == 6);
	_ASSERT(processedImage->image.data[35] == 6);
	_ASSERT(processedImage->image.data[36] == 8);
	_ASSERT(processedImage->image.data[37] == 8);
	_ASSERT(processedImage->image.data[38] == 8);
	_ASSERT(processedImage->image.data[39] == 8);

	_ASSERT(processedImage->image.data[40] == 6);
	_ASSERT(processedImage->image.data[41] == 6);
	_ASSERT(processedImage->image.data[42] == 6);
	_ASSERT(processedImage->image.data[43] == 6);
	_ASSERT(processedImage->image.data[44] == 8);
	_ASSERT(processedImage->image.data[45] == 46);
	_ASSERT(processedImage->image.data[46] == 46);
	_ASSERT(processedImage->image.data[47] == 46);

	_ASSERT(processedImage->image.data[48] == 44);
	_ASSERT(processedImage->image.data[49] == 44);
	_ASSERT(processedImage->image.data[50] == 44);
	_ASSERT(processedImage->image.data[51] == 44);
	_ASSERT(processedImage->image.data[52] == 8);
	_ASSERT(processedImage->image.data[53] == 8);
	_ASSERT(processedImage->image.data[54] == 8);
	_ASSERT(processedImage->image.data[55] == 8);

	_ASSERT(processedImage->image.data[56] == 6);
	_ASSERT(processedImage->image.data[57] == 44);
	_ASSERT(processedImage->image.data[58] == 44);
	_ASSERT(processedImage->image.data[59] == 44);
	_ASSERT(processedImage->image.data[60] == 8);
	_ASSERT(processedImage->image.data[61] == 8);
	_ASSERT(processedImage->image.data[62] == 46);
	_ASSERT(processedImage->image.data[63] == 8);
	
	delete[] compressedDataRead.buffer;
}
