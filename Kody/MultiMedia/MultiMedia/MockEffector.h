#pragma once

#include "Effector.h"

class MockEffector: public Effector
{
public:
	virtual void init();
	virtual void done();
	virtual void apply(Result* result);
};

