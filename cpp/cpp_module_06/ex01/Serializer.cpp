#include "Serializer.hpp"

Serializer::Serializer()
{
}

Serializer::Serializer(const Serializer &other)
{
	(void)other;
}

Serializer::~Serializer()
{
}

Serializer &Serializer::operator=(const Serializer &other)
{
	(void)other;

	return (*this);
}

uintptr_t Serializer::serialize(Data *ptr)
{
	return uintptr_t(ptr);
}

Data *Serializer::deserialize(uintptr_t raw)
{
	return (Data *)(raw);
}
