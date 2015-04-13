#pragma once

#include "ProcessedData.h"
#include "FeatureVector.h"

class FeatureExtractor
{
public:
	virtual void init() = 0;
	virtual void done() = 0;
	virtual FeatureVector* extractFeature(ProcessedData* ProcessedData) = 0;
};

