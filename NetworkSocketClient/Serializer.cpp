#include "pch.h"
#include "Serializer.h"


Serializer::Serializer(SOCKET& _sock)
{
	sock = _sock;
}

Serializer::~Serializer()
{

}

