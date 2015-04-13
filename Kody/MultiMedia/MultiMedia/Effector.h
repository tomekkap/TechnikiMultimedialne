#pragma once

#include "Result.h"

class Effector
{
public:
	virtual void init() = 0;
	virtual void done() = 0;
	virtual void apply(Result* result) = 0;
};

