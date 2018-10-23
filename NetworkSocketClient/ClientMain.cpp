
#include "pch.h"
#include "Client.h"

int main()
{
	//192.168.1.15
	//133.133.2.52

	Client* client = new Client();

	if (client->Connect(true, 25648))
	{
		while (client->IsConnected())
		{
			cout << "Found the number : ";
			cin >> client->buffer;

			if (!client->SendBuffer()) cout << "Sending Error" << endl;
			if (!client->Receive()) cout << "Receive Error" << endl;

			client->DebugBuffer();
		}

		client->CloseSocket();
		return 0;
	}
	else
	{
		cout << "INITIALIZATION ERROR !" << endl;

		system("pause");

		return -1;
	}
}

