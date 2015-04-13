#include <iostream>

#include "MockEffector.h"

using namespace std;

void MockEffector::init()
{
	cout << "MockEffector::init" << endl;
}

void MockEffector::done()
{
	cout << "MockEffector::done" << endl;
}

void MockEffector::apply(Result* result)
{
	cout << "MockEffector::apply" << endl;
}
