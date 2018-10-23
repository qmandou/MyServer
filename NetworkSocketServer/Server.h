#ifndef SERVER__H
#define SERVER__H

#define EOMSG '\0' // END OF MESSAGE
#define SEPARATOR cout << "--------------------" << endl
#define PAUSE system("pause")
#define ERASE system("erase")

#include <WinSock2.h>
#pragma comment(lib, "ws2_32.lib")

class Server
{

public:
	Server(const char* _ip, int _port);
	~Server();

	bool isConnect();
	bool Accept();
	bool PlusOuMoins();

	void Send(const char* buffer, int _bufferLenght);
	char* Receive(int _size);
	void CloseSocket();

private:

	WSADATA WSAData;
	SOCKET sock;
	SOCKET csock;
	SOCKADDR_IN sin;
	SOCKADDR_IN csin;

	char* buffer;
	int random;
};


#endif // !SERVER__H ma grosse bite
