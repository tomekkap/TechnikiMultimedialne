#pragma once

#include "DataProducer.h"
#include "MockRawData.h"

class MockDataProducer: public DataProducer
{
public:
	virtual void init();
	virtual void done();
	virtual RawData* getData();
	virtual bool dataAvailable();
private:
	MockRawData* rawData;
};

