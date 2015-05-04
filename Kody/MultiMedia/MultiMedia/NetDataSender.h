#pragma once

#include <WinSock2.h>

#include "DataConsumer.h"

class NetDataSender: public DataConsumer
{
public:
	virtual void init();
	virtual void done();
	virtual void setData(ProcessedData* processedData);
private:
	WSADATA wsaData;
	SOCKET mainSocket;
};

