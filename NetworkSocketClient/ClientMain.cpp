
#include "pch.h"
#include "Client.h"
#include "Serializer.h"

int main()
{
	//192.168.1.15
	//133.133.2.52

	Client* client = new Client();
	Serializer* sz;
	string lol = "ptdrmdrlolxD";
	char text[25] = "je suis une licorne";
	int mdr[4] = { 32,64,128,154 };

	//double mdr = 853563.66456;
	//int* lol = new int[10];


	if (client->Connect("192.168.1.15", 25648))
	{
		sz = new Serializer(client->sock);

		while (client->IsConnected())
		{
			if (sz->Send(mdr))
			{
				Sleep(300);
			}
		}

		delete client;
		return 0;
	}
	else
	{
		cout << "INITIALIZATION ERROR !" << endl;

		system("pause");

		return -1;
	}
}

