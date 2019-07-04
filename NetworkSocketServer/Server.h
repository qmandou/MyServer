#ifndef SERVER__H
#define SERVER__H

#define EOMSG '\0' // END OF MESSAGE
#define SEPARATOR std::cout << "--------------------" << std::endl
#define PAUSE system("pause")
#define ERASE system("erase")
#define PRINT(x) std::cout << x << std::endl

#include <vector>
#include <mutex>

#include <WinSock2.h>
#pragma comment(lib, "ws2_32.lib")

#include "Serializer.h"

class ClientData
{
public :
	Serializer* sz;
	SOCKADDR_IN csin;

	ClientData(SOCKET _socket, SOCKADDR_IN _csin)
	{
		sz = new Serializer(_socket);
		csin = _csin;
	}

	~ClientData()
	{
		delete sz;
	}
};

class Server
{

public:
	SOCKET sock;

	std::vector<ClientData*> clients;

	Server();
	~Server();

	bool Connect(char* _ip, int _port);
	bool CloseSocket();
	inline bool isConnect() { return m_IsRunning; }

	// thread Accept
	void Accept(std::mutex* _mutex);

private:

	bool m_IsRunning;

	WSADATA WSAData;
	SOCKADDR_IN sin;

};


#endif // !SERVER__H ma grosse bite
