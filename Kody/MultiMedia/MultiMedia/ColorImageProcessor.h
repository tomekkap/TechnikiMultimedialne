#pragma once

#include "DataProcessor.h"
#include "ProcessedImage.h"

class ColorImageProcessor: public DataProcessor
{
public:
	virtual void init();
	virtual void done();
	virtual ProcessedData* processData(RawData* rawData);
private:
	ProcessedImage* processedImage;
	int HMin;
	int HMax;
	int SMin;
	int SMax;
	int VMin;
	int VMax;
};

