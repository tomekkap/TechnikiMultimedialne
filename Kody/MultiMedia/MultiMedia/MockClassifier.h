#pragma once

#include "Classifier.h"
#include "MockResult.h"

class MockClassifier: public Classifier
{
public:
	virtual void init();
	virtual void done();
	virtual Result* classify(FeatureVector* featureVector);
private:
	MockResult* result;
};

