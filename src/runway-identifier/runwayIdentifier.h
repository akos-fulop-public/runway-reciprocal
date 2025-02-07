#pragma once

#include <string>

class RunwayIdentifier {
public:
	static bool isValid(std::string id);

private:
	std::string id;
	static constexpr int MIN_NUMBER_COMPONENT = 1;
	static constexpr int MAX_NUMBER_COMPONENT = 36;
};
