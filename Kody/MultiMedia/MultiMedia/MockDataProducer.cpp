#include <iostream>

#include "MockDataProducer.h"

using namespace std;

void MockDataProducer::init()
{
	cout << "MockDataProducer::init" << endl;
	rawData = new MockRawData();
}

void MockDataProducer::done()
{
	cout << "MockDataProducer::done" << endl;
	if(rawData)
		delete rawData;
}

RawData* MockDataProducer::getData()
{
	cout << "MockDataProducer::getData" << endl;
	return (RawData*)rawData;
}

bool MockDataProducer::dataAvailable()
{
	cout << "MockDataProducer::dataAvailable" << endl;
	static int counter = 0;
	return (counter++ < 1)?true:false;
}
