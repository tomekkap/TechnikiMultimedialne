#include <iostream>

#include "MockDataConsumer.h"

using namespace std;

void MockDataConsumer::init()
{
	cout << "MockDataConsumer::init" << endl;
}

void MockDataConsumer::done()
{
	cout << "MockDataConsumer::done" << endl;
}

void MockDataConsumer::setData(ProcessedData* processedData)
{
	cout << "MockDataConsumer::setData" << endl;
}
