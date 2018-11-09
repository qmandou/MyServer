#include "pch.h"
#include "Server.h"

#define SEPARATOR cout << "--------------------" << endl
#define PAUSE system("pause")
#define ERASE system("erase")

#pragma region Constructor

Server::Server()
{
	cout << "Server Launched" << endl;
	SEPARATOR;
}

Server::~Server()
{
	CloseSocket();
}

#pragma endregion

#pragma region Public Function

bool Server::Connect(const char* _ip, int _port)
{
	if (WSAStartup(MAKEWORD(2, 2), &WSAData) != 0)
	{
		WSACleanup();

		return false;
	}

	sock = socket(AF_INET, SOCK_STREAM, 0);
	if (sock == INVALID_SOCKET) return false;

	sin.sin_addr.s_addr = inet_addr(_ip);
	sin.sin_family = AF_INET;
	sin.sin_port = htons(_port);
	bind(sock, (SOCKADDR *)&sin, sizeof(sin));
	listen(sock, 0);
	return true;
}

bool Server::isConnect()
{
	return csock != INVALID_SOCKET ? true : false;
}

bool Server::Accept()
{
	int sinsize = sizeof(csin);
	csock = accept(sock, (SOCKADDR *)&csin, &sinsize);
	return csock != INVALID_SOCKET ? true : false;
}

bool Server::CloseSocket()
{
	SEPARATOR;
	cout << "Server Close" << endl;
	return (closesocket(sock) < 0 || WSACleanup()) ? false : true;
}

#pragma endregion

//bool Server::PlusOuMoins()
//{
//	char* buffer = nullptr;
//	buffer = Receive(512);
//
//	if (buffer != nullptr)
//	{
//		int result = atoi(buffer);
//		cout << result << endl;
//
//		if (result > random)
//		{
//			char toSend[8] = "Moins !";
//			Send(toSend, 8);
//		}
//		else if (result < random)
//		{
//			char toSend[7] = "Plus !";
//			Send(toSend, 7);
//		}
//		else
//		{
//			char toSend[11] = "Tu gagne !";
//			Send(toSend, 11);
//			return true;
//		} 
//
//		SEPARATOR;
//		return false;
//	}
//}
