#ifndef CAPSULE__H
#define CAPSULE__H

// _CRT_SECURE_NO_WARNINGS

// _CRT_SECURE_NO_WARNINGS
#define BUFFER_CAPACITY 512

enum SerializedType
{
	charST,
	stringST,
	intST,
	floatST,
	doubleST
};

struct SerializedValue
{
	char* buffer;
	SerializedType type;
};

class Capsule
{

public:

	Capsule(int _bufferLenght);
	~Capsule();

	bool AddSerialize(SerializedType _type, char* _data);
	SerializedType* Unserialize(int offset);
private:
	char* buffer;
	unsigned int offset;
	unsigned int bufferLenght;

};



#endif // !CAPSULE__H
