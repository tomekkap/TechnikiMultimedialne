#pragma once

#include <WinSock2.h>

#include "DataProducer.h"
#include "CompressedDataRead.h"

class NetDataReceiver: public DataProducer
{
public:
	virtual void init();
	virtual void done();
	virtual RawData* getData();
	virtual bool dataAvailable();
private:
	WSADATA wsaData;
	SOCKET mainSocket;
	CompressedDataRead* compressedData;
};

