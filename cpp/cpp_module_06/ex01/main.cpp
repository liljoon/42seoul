#include "Serializer.hpp"
#include <iostream>

int main()
{
	Data dt;
	uintptr_t temp_uint;

	dt.data = 123;

	temp_uint = Serializer::serialize(&dt);
	std::cout << temp_uint << std::endl;
	std::cout << Serializer::deserialize(temp_uint) << std::endl;

	return 0;
}
