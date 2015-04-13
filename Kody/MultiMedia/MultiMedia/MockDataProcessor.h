#pragma once

#include "DataProcessor.h"
#include "MockProcessedData.h"

class MockDataProcessor: public DataProcessor
{
public:
	virtual void init();
	virtual void done();
	virtual ProcessedData* processData(RawData* rawData);
private:
	MockProcessedData* processedData;
};

