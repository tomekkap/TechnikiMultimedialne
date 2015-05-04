#pragma once

#include "DataProcessor.h"
#include "CompressedData.h"

class ImageCompressor: public DataProcessor
{
public:
	virtual void init();
	virtual void done();
	virtual ProcessedData* processData(RawData* rawData);
private:
	CompressedData* compressedData;
};

