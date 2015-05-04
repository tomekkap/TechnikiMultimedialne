#pragma once

#include "RawData.h"

class CompressedDataRead: public RawData
{
public:
	int length;
	unsigned char* buffer;
};

