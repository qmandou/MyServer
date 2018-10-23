// Main.cpp : définit le point d'entrée pour l'application console.
//

#include "pch.h"
#include "Server.h"

int main()
{
	//192.168.1.15
	//133.133.2.52

	srand((unsigned)time(NULL));

	Server* server = new Server("192.168.1.15", 25648);
	server->Accept();

	while (server->isConnect())
	{
		/*if (server->PlusOuMoins())
		{
			server->CloseSocket();
		}*/

		server->CloseSocket();
	}

	delete server;

	return 0;
}
