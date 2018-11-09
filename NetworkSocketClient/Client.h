#ifndef CLIENT__H
#define CLIENT__H

#include "pch.h"

#define EOMSG '\0' // END OF MESSAGE
#define SEPARATOR cout << "--------------------" << endl
#define PAUSE system("pause")
#define ERASE system("erase")


class Client
{

public:
	char buffer[512];
	SOCKET sock;

	Client();
	~Client();
	
	bool Connect(const char* adr, int port);
	bool IsConnected();
	bool CloseSocket(); 

	inline SOCKET GetClientSocket() { return sock; };
	inline unsigned int GetSizeOfBuffer() { return sizeof(buffer); }

private:
	WSAData data;
	char ipAdr[13];

	SOCKADDR_IN sin;
};


#endif // !CLIENT__H

