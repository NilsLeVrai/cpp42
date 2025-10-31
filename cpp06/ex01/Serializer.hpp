#pragma once

#include <iomanip>
#include <iostream>
#include "Data.hpp"

class Serializer {

	private:
		Serializer();
		~Serializer();
		Serializer(const Serializer &src);
		Serializer &operator=(const Serializer &src);

	public:
	
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);

};
