#ifndef SERIALIZER__H
#define SERIALIZER__H

#define EOM '\0'
#define BUFFER_LENGHT 512

#include <WinSock2.h>
#include <type_traits>

/*
	Le Serializer permet de cast n'importe quelle classe en un char*
	que l'on pourra envoyer sur le réseau
	Le même code est aussi présent sur le serveur.
*/

class Serializer
{
	SOCKET sock;
	char* recvBuffer = nullptr;

public:
	Serializer(SOCKET& _sock);
	~Serializer();

	// Take any class in input and return send function result
	// if sizeArray is > 1 , _toSend is an array
	template<typename T>
	bool Send(T _toSend, UINT sizeArray = 1)
	{
		char* toSend = reinterpret_cast<char*>(&_toSend);
		return send(sock, toSend, sizeof(T) * sizeArray, 0) < 0 ? false : true;
	}

	bool Receive(int _sizeofBuffer)
	{
		if (recvBuffer != nullptr) delete recvBuffer;
		recvBuffer = new char[_sizeofBuffer];

		int returnValue = recv(sock, recvBuffer, _sizeofBuffer, 0);
		return  returnValue < 0 ? false : true;
	}

	template<typename T>
	T* UnSerializeBuffer()
	{
		return reinterpret_cast<T*>(recvBuffer);
	}


	bool resvBufferIsNull()
	{
		return recvBuffer == nullptr ? true : false;
	}
};
#endif // !SERIALIZER__H


