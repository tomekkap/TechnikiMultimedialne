#include <iostream>

#include "MockClassifier.h"

using namespace std;

void MockClassifier::init()
{
	cout << "MockClassifier::init" << endl;
	result = new MockResult();
}

void MockClassifier::done()
{
	cout << "MockClassifier::done" << endl;
	if(result)
		delete result;
}

Result* MockClassifier::classify(FeatureVector* featureVector)
{
	cout << "MockClassifier::classify" << endl;
	return (Result*)result;
}
