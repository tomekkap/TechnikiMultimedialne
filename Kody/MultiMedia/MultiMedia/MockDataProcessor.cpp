#include <iostream>

#include "MockDataProcessor.h"

using namespace std;

void MockDataProcessor::init()
{
	cout << "MockDataProcessor::init" << endl;
	processedData = new MockProcessedData();
}

void MockDataProcessor::done()
{
	cout << "MockDataProcessor::done" << endl;
	if(processedData)
		delete processedData;
}

ProcessedData* MockDataProcessor::processData(RawData* rawData)
{
	cout << "MockDataProcessor::processData" << endl;
	return (ProcessedData*)processedData;
}