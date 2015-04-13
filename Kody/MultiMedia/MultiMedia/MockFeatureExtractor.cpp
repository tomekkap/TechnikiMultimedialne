#include <iostream>

#include "MockFeatureExtractor.h"

using namespace std;

void MockFeatureExtractor::init()
{
	cout << "MockFeatureExtractor::init" << endl;
	featureVector = new MockFeatureVector();
}

void MockFeatureExtractor::done()
{
	cout << "MockFeatureExtractor::done" << endl;
	if(featureVector)
		delete featureVector;
}

FeatureVector* MockFeatureExtractor::extractFeature(ProcessedData* processedData)
{
	cout << "MockFeatureExtractor::extractFeature" << endl;
	return (FeatureVector*)featureVector;
}