#pragma once

#include "FeatureVector.h"
#include "Result.h"

class Classifier
{
public:
	virtual void init() = 0;
	virtual void done() = 0;
	virtual Result* classify(FeatureVector* featureVector) = 0;
};

