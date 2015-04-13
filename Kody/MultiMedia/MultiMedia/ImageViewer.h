#pragma once

#include "DataConsumer.h"

class ImageViewer: public DataConsumer
{
public:
	virtual void init();
	virtual void done();
	virtual void setData(ProcessedData* processedData);
};

