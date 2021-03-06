
#include "pch.h"
#include "Client.h"
#include "Serializer.h"
#include <windows.h>

//192.168.1.15

int main()
{
	Client* client = new Client();
	Serializer* sz;
	string message = "Test";
	char ip[128];

	cout << "Enter your ipv4 : " << endl;
	cin >> ip;

	if (client->Connect(ip, 6000))
	{
		sz = new Serializer(client->sock);

		while (client->IsConnected())
		{
			if (sz->Send(message))
			{
				std::cout << "Send " << message << std::endl;
				Sleep(800);
			}
		}

		delete sz;
		delete client;
		return 0;
	}
	else
	{
		std::cout << "INITIALIZATION ERROR !" << std::endl;

		system("pause");

		return -1;
	}
}

