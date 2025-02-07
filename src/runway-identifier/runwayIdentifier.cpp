#include "runwayIdentifier.h"

bool RunwayIdentifier::isValid(const std::string &id) {
	if (id.length() > 2) {
		return false;
	}
	int number_component = std::stoi(id);
	if (number_component < MIN_NUMBER_COMPONENT) {
		return false;
	}
	if (number_component > MAX_NUMBER_COMPONENT) {
		return false;
	}
	return true;
}
