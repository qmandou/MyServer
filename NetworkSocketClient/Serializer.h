#ifndef SERIALIZER__H
#define SERIALIZER__H

#define EOM '\0'

#include <WinSock2.h>
#include <type_traits>

class Serializer
{
	SOCKET sock;
	char* resvBuffer = nullptr;

public:
	Serializer(SOCKET& _sock);
	~Serializer();

	template<typename T>
	bool Send(T& _toSend, UINT sizeArray = 1)
	{
		char* toSend = reinterpret_cast<char*>(&_toSend);
		return send(sock, toSend, sizeof(T) * sizeArray, 0) < 0 ? false : true;
	}

	bool Receive(int _sizeofBuffer)
	{
		return recv(sock, resvBuffer, _sizeofBuffer, 0) < 0 ? false : true;
	}

	template<typename T>
	T* UnSerializeBuffer()
	{
		return reinterpret_cast<T*>(resvBuffer);
	}


	bool resvBufferIsNull()
	{
		return resvBuffer == nullptr ? true : false;
	}
};
#endif // !SERIALIZER__H


