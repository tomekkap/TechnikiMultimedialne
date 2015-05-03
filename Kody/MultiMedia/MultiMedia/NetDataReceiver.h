#pragma once

#include "DataProducer.h"

class NetDataReceiver: public DataProducer
{
public:
	virtual void init();
	virtual void done();
	virtual RawData* getData();
	virtual bool dataAvailable();
};

