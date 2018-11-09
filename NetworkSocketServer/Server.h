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
	SOCKET sock;
	SOCKET csock;

	Server();
	~Server();

	bool Connect(const char* _ip, int _port);
	bool isConnect();
	bool Accept();
	bool CloseSocket();

private:

	WSADATA WSAData;
	SOCKADDR_IN sin;
	SOCKADDR_IN csin;

};


#endif // !SERVER__H ma grosse bite
