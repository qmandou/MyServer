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

	Client();
	~Client();
	
	bool Connect(bool isSchool, int port);
	bool IsConnected();
	bool CloseSocket(); 
	
	bool Receive();
	bool SendBuffer();

	void DebugBuffer();

	inline SOCKET GetClientSocket() { return socketClient; };
	inline unsigned int GetSizeOfBuffer() { return sizeof(buffer); }

private:
	WSAData data;
	char ipAdr[13];

	SOCKET socketClient;
	SOCKADDR_IN sin;
};


#endif // !CLIENT__H

