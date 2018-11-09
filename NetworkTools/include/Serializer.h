#ifndef SERIALIZER__H
#define SERIALIZER__H

#define EOM '\0'
#define BUFFER_LENGHT 512

#include <WinSock2.h>
#include <type_traits>

class Serializer
{

private:
	SOCKET sock;
	char* resvBuffer = nullptr;

public:
	Serializer(SOCKET& _sock);
	~Serializer();

	template<typename T>
	bool Send(T _toSend)
	{
		if (is_pointer<T>())
		{
			char* toSend = reinterpret_cast<char*>(_toSend);
			return send(sock, toSend, sizeof(T) * sizeof(_toSend), 0) < 0 ? false : true;
		}
		else
		{
			char* toSend = reinterpret_cast<char*>(&_toSend);
			return send(sock, toSend, sizeof(T), 0) < 0 ? false : true;
		}

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


