#include "Serializer.hpp"

Serializer::Serializer() {
	//std::cout << "constucteur\n";
}

Serializer::~Serializer() {
	//std::cout << "destucteur\n";
}

Serializer::Serializer(const Serializer &src) {
	//std::cout << "copieur\n";
	*this = src;
}

Serializer &Serializer::operator=(const Serializer &src) {

	if (this == &src)
		return (*this);
	//truc
	return (*this);
}

uintptr_t Serializer::serialize(Data* ptr) {
	return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw) {
	return reinterpret_cast<Data*>(raw);
}