#include "pch.h"
#include "Client.h"


Client::Client()
{
	
}

Client::~Client()
{

}

bool Client::Connect(const char* adr, int port)
{
	if (WSAStartup(MAKEWORD(2, 2), &data) != 0)
	{
		WSACleanup();

		return false;
	}

	socketClient = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

	sin.sin_addr.s_addr = inet_addr(adr);
	sin.sin_family = AF_INET;
	sin.sin_port = htons(port); 

	if (connect(socketClient, (SOCKADDR *)&sin, sizeof(sin)) < 0) return false;
	return socketClient == INVALID_SOCKET ? false : true;
}

bool Client::IsConnected()
{
	return socketClient == INVALID_SOCKET ? false : true;
}

bool Client::CloseSocket()
{
	if (closesocket(socketClient) < 0 || WSACleanup() < 0) return false;
	return true;
}

bool Client::Receive()
{
	return recv(socketClient, buffer, sizeof(buffer), 0) < 0 ? false : true;
}

bool Client::SendBuffer()
{
	return send(socketClient, buffer, GetSizeOfBuffer(), 0) < 0 ? false : true;
}

bool Client::Send(char* _buffer)
{
	return send(socketClient, _buffer, sizeof(_buffer), 0) < 0 ? false : true;
}

void Client::DebugBuffer()
{
	cout << buffer << endl;
}

//192.168.1.15
//133.133.2.52