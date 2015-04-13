#pragma once

#include "RawData.h"
#include "ProcessedData.h"

class DataProcessor
{
public:
	virtual void init() = 0;
	virtual void done() = 0;
	virtual ProcessedData* processData(RawData* rawData) = 0;
};

