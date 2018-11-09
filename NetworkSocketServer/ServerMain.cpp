// Main.cpp : définit le point d'entrée pour l'application console.
//

#include "pch.h"
#include "Server.h"
#include "Serializer.h"


int main()
{
	//192.168.1.15
	//133.133.2.52

	srand((unsigned)time(NULL));
	Server* server = new Server();

	if (server->Connect("192.168.1.15", 25648))
	{
		server->Accept();
		Serializer* sz = new Serializer(server->csock);

		while (server->isConnect())
		{
			if (sz->Receive(BUFFER_LENGHT))
			{
				int* mdr = sz->UnSerializeBuffer<int>();
				cout << mdr[0] << " " << mdr[1] << " " << mdr[2] << " " << mdr[3] << endl;
			}
		}

		delete sz;
	}

	delete server;

	return 0;
}	
