#include "runwayIdentifier.h"

bool RunwayIdentifier::isValid(std::string id) {
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
