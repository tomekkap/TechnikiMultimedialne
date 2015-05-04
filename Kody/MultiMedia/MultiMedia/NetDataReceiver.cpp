#include <exception>

#include "NetDataReceiver.h"

#include <iostream>

using namespace std;

void NetDataReceiver::init()
{
	compressedData = new CompressedDataRead();
	if(!compressedData)
		throw new exception("Cannot allocate memory for the compressed data.");

	int result = WSAStartup(MAKEWORD(2, 2), &wsaData);
	if( result != NO_ERROR )
		throw new exception("Initialization error.");

	mainSocket = socket( AF_INET, SOCK_STREAM, IPPROTO_TCP );
	if( mainSocket == INVALID_SOCKET )
	{
		WSACleanup();
		throw new exception("Error creating socket.");
	}

	sockaddr_in service;
	memset(&service, 0, sizeof(service));
	service.sin_family = AF_INET;
	service.sin_addr.s_addr = inet_addr("127.0.0.1");
	service.sin_port = htons(27015);

	if(connect(mainSocket,( SOCKADDR * ) & service, sizeof( service ) ) == SOCKET_ERROR)
	{
		WSACleanup();
		throw new exception("Failed to connect.");
	}
}

void NetDataReceiver::done()
{
	closesocket(mainSocket);
	WSACleanup();
	if(compressedData)
		delete compressedData;
}

RawData* NetDataReceiver::getData()
{
	int bytesReceived = 0;
	bytesReceived = recv(mainSocket, (char*)compressedData->buffer, compressedData->length, 0);
	cout << bytesReceived << endl;
	return (RawData*)compressedData;
}

bool NetDataReceiver::dataAvailable()
{
	return true;
}
