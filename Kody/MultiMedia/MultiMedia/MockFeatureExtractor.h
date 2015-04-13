#pragma once

#include "FeatureExtractor.h"
#include "MockFeatureVector.h"

class MockFeatureExtractor: public FeatureExtractor
{
public:
	virtual void init();
	virtual void done();
	virtual FeatureVector* extractFeature(ProcessedData* ProcessedData);
private:
	MockFeatureVector* featureVector;
};

