#include "pch.h"
#include "Client.h"


Client::Client()
{
	cout << "Client Launched" << endl;

	SEPARATOR;
}

Client::~Client()
{
	CloseSocket();
}

// Try to connect the client at the server and return true if is ok 
// or clean up and return false
bool Client::Connect(char* adr, int port)
{
	if (WSAStartup(MAKEWORD(2, 2), &data) != 0)
	{
		WSACleanup();

		return false;
	}

	sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

	sin.sin_addr.s_addr = inet_addr(adr);
	sin.sin_family = AF_INET;
	sin.sin_port = htons(port); 
	int connectError = connect(sock, (SOCKADDR *)&sin, sizeof(sin));
	cout << connectError << endl;

	if (connectError < 0) 
		return false;
	else 
		return sock == INVALID_SOCKET ? false : true;
}

// Check if client is connected to the server
bool Client::IsConnected()
{
	return sock != INVALID_SOCKET ? true : false;
}

// Stop Client
bool Client::CloseSocket()
{
	if (closesocket(sock) < 0 || WSACleanup() < 0) return false;
	return true;
}