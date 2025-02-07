#include <iostream>

#include <runwayIdentifier.h>

int main(int argc, char* argv[]) {
	if (argc != 2) {
		std::cout << "Enter exactly one argument!" << std::endl;
		return 1;
	}
	std::string id{argv[1]};
	if (!isValidRunwayId(id)) {
		std::cout << "Argument provided is not a valid runway number!" << std::endl;
		return 1;
	}
	std::cout << getReciprocalRunwayId(id) << std::endl;
	return 0;
}
