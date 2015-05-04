#pragma once

#include "ProcessedData.h"

class CompressedData: public ProcessedData
{
public:
	int length;
	unsigned char* buffer;
};

