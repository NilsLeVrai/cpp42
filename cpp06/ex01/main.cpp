#include "Serializer.hpp"

int main() {

	Data data;
	data.n = 42;

	std::cout << "Original address: " << &data << std::endl;
	std::cout << "Original value: " << data.n << std::endl;
	std::cout << std::endl;

	uintptr_t raw = Serializer::serialize(&data);
	std::cout << "Serialized (uintptr_t): " << raw << std::endl;
	std::cout << std::endl;

	Data* deserialized = Serializer::deserialize(raw);
	std::cout << "Deserialized address: " << deserialized << std::endl;
	std::cout << "Deserialized value: " << deserialized->n << std::endl;
	std::cout << std::endl;

	if (deserialized == &data) {
		std::cout << "Success :)" << std::endl;
	} else {
		std::cout << "Error :(" << std::endl;
	}
}
