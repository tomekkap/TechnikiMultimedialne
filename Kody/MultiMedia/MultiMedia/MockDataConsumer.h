#pragma once

#include "DataConsumer.h"

class MockDataConsumer: public DataConsumer
{
public:
	virtual void init();
	virtual void done();
	virtual void setData(ProcessedData* processedData);
};

