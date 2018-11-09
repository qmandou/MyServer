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

bool Client::Connect(const char* adr, int port)
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

	if (connect(sock, (SOCKADDR *)&sin, sizeof(sin)) < 0) return false;
	return sock == INVALID_SOCKET ? false : true;
}

bool Client::IsConnected()
{
	return sock != INVALID_SOCKET ? true : false;
}

bool Client::CloseSocket()
{
	if (closesocket(sock) < 0 || WSACleanup() < 0) return false;
	return true;
}

//192.168.1.15
//133.133.2.52