#pragma once

#include "DataProcessor.h"

class ImageDecompressor: public DataProcessor
{
public:
	virtual void init();
	virtual void done();
	virtual ProcessedData* processData(RawData* rawData);
};

