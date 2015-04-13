#pragma once

#include "RawData.h"

class DataProducer
{
public:
	virtual void init() = 0;
	virtual void done() = 0;
	virtual RawData* getData() = 0;
	virtual bool dataAvailable() = 0;
};

