#include "pch.h"
#include "Capsule.h"


Capsule::Capsule(int _bufferLenght)
{
	buffer = new char[_bufferLenght];
	_bufferLenght = _bufferLenght;
}


Capsule::~Capsule()
{

}

bool  Capsule::AddSerialize(SerializedType _type, char* _data)
{
	char* serialyseTypeData = Serializer::Serialize(&_type);
	unsigned int typeByteLenght = strlen(serialyseTypeData);

	if (typeByteLenght + strlen(_data) >= bufferLenght) return false;

	strcat(buffer, serialyseTypeData);
	offset += typeByteLenght;
	strcat(buffer, _data);
	offset += strlen(_data);

	return true;
}

SerializedType* Capsule::Unserialize(int offset)
{
	//SerializedType mdr = Serializer::UnSerialize(buffer, intST);
	//char*
	//return mdr;
}

