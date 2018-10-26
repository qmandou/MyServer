#ifndef SERIALIZER__H
#define SERIALIZER__H

class Serializer
{
private:
	char buffer[512];

public:
	Serializer();
	~Serializer();


	template<typename T> void Serialize(T toSerialize)
	{
		buffer = reinterpret_cast<char*>(toSerialize);
	}

	template<typename T> T Unserialize()
	{
		return reinterpret_cast<T>(buffer);
	}

	inline char* GetBuffer() { return buffer; }
	inline void SetBuffer(char* _value) { buffer = _value; }

	template<typename T> inline T GetBuffer() { return Unserialize<T>(); }
};
#endif // !SERIALIZER__H


