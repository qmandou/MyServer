// Main.cpp : définit le point d'entrée pour l'application console.
//

#include "pch.h"
#include "Server.h"
#include "Serializer.h"

#include <thread>
#include <mutex>
#include <iostream>

void AcceptThread(Server* _server, std::mutex*_locker);

int main()
{
	srand((unsigned)time(NULL));

	Server* server = new Server();
	char ip[128];

	std::cout << "Enter your ipv4 : " << std::endl;
	std::cin >> ip;

	if (server->Connect(ip, 6000))
	{
		std::mutex locker;

		std::thread aThread(AcceptThread, server, &locker);

		while (server->isConnect())
		{
			PRINT(server->clients.size());
			if (server->clients.size() > 0 && locker.try_lock())
			{
				for (std::vector<ClientData*>::iterator it = server->clients.begin(); it != server->clients.end(); it++)
				{
					if ((*it)->sz->Receive(512))
					{
						std::string str = *(*it)->sz->UnSerializeBuffer<std::string>();
						std::cout << str.c_str() << std::endl;
					}
				}
				locker.unlock();
			}
		}

		aThread.join();
	}
	delete server;

	return 0;
}	

void AcceptThread(Server* _server, std::mutex*_locker)
{
	_server->Accept(_locker);
}
