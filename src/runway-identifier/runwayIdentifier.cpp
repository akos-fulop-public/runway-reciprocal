#include "runwayIdentifier.h"

bool isValidRunwayId(std::string id) {
	if (id.empty()) {
		return false;
	}
	if (std::find_if(id.begin(), id.end(), [](unsigned char c){ return !std::isalnum(c); }) != id.end()) {
		return false;
	}
	char letter_component;
	if (std::isalpha(id.back())) {
		letter_component = id.back();
		id.pop_back();
		if (letter_component != 'C' && letter_component != 'L' && letter_component != 'R') {
			return false;
		}
	}

	if (id.length() > 2) {
		return false;
	}
	std::size_t pos{};
	int number_component = std::stoi(id, &pos);
	if (pos != id.length()) {
		return false;
	}
	if (number_component < MIN_NUMBER_COMPONENT || number_component > MAX_NUMBER_COMPONENT) {
		return false;
	}
	return true;
}

std::string getReciprocalRunwayId(std::string id) {
	if (!isValidRunwayId(id)) {
		return std::string();
	}
	std::string letter_component;
	if (std::isalpha(id.back())) {
		letter_component = id.back();
		id.pop_back();
	}

	int number_component = std::stoi(id);
	int reciprocal_number_component = number_component + 18;
	if (reciprocal_number_component > MAX_NUMBER_COMPONENT) {
		reciprocal_number_component -= 36;
	}
	std::string reciprocal = std::to_string(reciprocal_number_component);
	if (reciprocal.length() == 1) {
		reciprocal = "0" + reciprocal;
	}
	if (!letter_component.empty()) {
		if (letter_component == "R") {
			reciprocal += "L";
		} else if (letter_component == "L") {
			reciprocal += "R";
		} else {
			reciprocal += "C";
		}
	}
	return reciprocal;
}
