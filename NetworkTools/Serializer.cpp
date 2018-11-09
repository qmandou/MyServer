#include "stdafx.h"
#include "Serializer.h"


Serializer::Serializer(SOCKET& _sock)
{
	sock = _sock;
	resvBuffer = new char[BUFFER_LENGHT];
}

Serializer::~Serializer()
{
	if (resvBuffer != nullptr) delete[] resvBuffer;
}

