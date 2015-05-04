#include <exception>

#include "NetDataSender.h"
#include "CompressedData.h"

#include <iostream>

using namespace std;

void NetDataSender::init()
{
	int result = WSAStartup(MAKEWORD(2, 2 ), &wsaData);
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

	if(bind( mainSocket,( SOCKADDR * ) & service, sizeof( service ) ) == SOCKET_ERROR)
	{
		closesocket(mainSocket);
		WSACleanup();
		throw new exception("Socket bind failed.");
	}

	if( listen( mainSocket, 1 ) == SOCKET_ERROR )
	{
		closesocket(mainSocket);
		WSACleanup();
		throw new exception("Error listening on socket.");
	}
    
	SOCKET acceptSocket = SOCKET_ERROR;
	while(acceptSocket == SOCKET_ERROR)
		acceptSocket = accept( mainSocket, NULL, NULL );
	mainSocket = acceptSocket;
}

void NetDataSender::done()
{
	closesocket(mainSocket);
	WSACleanup();
}

void NetDataSender::setData(ProcessedData* processedData)
{
	int bytesSent = send(mainSocket, (const char*)((CompressedData*)processedData)->buffer, 5/*((CompressedData*)processedData)->length*/, 0);
	cout << bytesSent << endl;
}