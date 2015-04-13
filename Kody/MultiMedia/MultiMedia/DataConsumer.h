#pragma once

#include "ProcessedData.h"

class DataConsumer
{
public:
	virtual void init() = 0;
	virtual void done() = 0;
	virtual void setData(ProcessedData* processedData) = 0;
};

