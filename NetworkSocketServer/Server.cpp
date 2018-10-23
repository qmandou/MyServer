#include "pch.h"
#include "Server.h"

#define SEPARATOR cout << "--------------------" << endl
#define PAUSE system("pause")
#define ERASE system("erase")

#pragma region Constructor

Server::Server(const char* _ip, int _port)
{
	WSAStartup(MAKEWORD(2, 0), &WSAData);
	sock = socket(AF_INET, SOCK_STREAM, 0);
	sin.sin_addr.s_addr = inet_addr(_ip);
	sin.sin_family = AF_INET;
	sin.sin_port = htons(_port);
	bind(sock, (SOCKADDR *)&sin, sizeof(sin));
	listen(sock, 0);
	cout << "Server Launched" << endl; 

	random = rand() % 100;
	SEPARATOR;
}

Server::~Server()
{
	closesocket(sock);
	WSACleanup();
}

#pragma endregion

#pragma region Public Function

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

void Server::CloseSocket()
{
	SEPARATOR;
	cout << "Server Close" << endl;
	closesocket(csock);
	csock = INVALID_SOCKET;
	WSACleanup();
}

void Server::Send(const char* buffer, int _bufferLenght)
{
	send(csock, buffer, _bufferLenght, 0);
}

char* Server::Receive(int _size)
{
	buffer = new char[_size];
	if (recv(csock, buffer, _size, 0) < 0) return nullptr;
	return buffer;
}

bool Server::PlusOuMoins()
{
	char* buffer = nullptr;
	buffer = Receive(512);

	if (buffer != nullptr)
	{
		int result = atoi(buffer);
		cout << result << endl;

		if (result > random)
		{
			char toSend[8] = "Moins !";
			Send(toSend, 8);
		}
		else if (result < random)
		{
			char toSend[7] = "Plus !";
			Send(toSend, 7);
		}
		else
		{
			char toSend[11] = "Tu gagne !";
			Send(toSend, 11);
			return true;
		} 

		SEPARATOR;
		return false;
	}
}


