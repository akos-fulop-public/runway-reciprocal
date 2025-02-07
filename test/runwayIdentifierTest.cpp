#include <gtest/gtest.h>

#include <runwayIdentifier.h>

TEST(Validate, EmptyString) {
	EXPECT_FALSE(RunwayIdentifier::isValid(std::string()));
}

TEST(Validate, TwoDigitNumber) {
	EXPECT_TRUE(RunwayIdentifier::isValid(std::string("13")));
}

TEST(Validate, LargeNumber) {
	EXPECT_FALSE(RunwayIdentifier::isValid(std::string("37")));
}

TEST(Validate, Zero) {
	EXPECT_FALSE(RunwayIdentifier::isValid(std::string("0")));
}

TEST(Validate, PaddedSingleDigitNumber) {
	EXPECT_TRUE(RunwayIdentifier::isValid(std::string("06")));
}

TEST(Validate, DoublePaddedSingleDigitNumber) {
	EXPECT_FALSE(RunwayIdentifier::isValid(std::string("006")));
}

TEST(Validate, PaddedTwoDigitNumber) {
	EXPECT_FALSE(RunwayIdentifier::isValid(std::string("017")));
}

TEST(Validate, SingleDigitLetter) {
	EXPECT_TRUE(RunwayIdentifier::isValid(std::string("7L")));
}

TEST(Validate, TwoDigitsLetter) {
	EXPECT_TRUE(RunwayIdentifier::isValid(std::string("18R")));
}

TEST(Validate, SingleDigitInvalidLetter) {
	EXPECT_FALSE(RunwayIdentifier::isValid(std::string("8M")));
}

TEST(Validate, PaddedSingleDigitInvalidLetter) {
	EXPECT_FALSE(RunwayIdentifier::isValid(std::string("09X")));
}

TEST(Validate, WhitespaceSingleDigit) {
	EXPECT_FALSE(RunwayIdentifier::isValid(std::string(" 7")));
}
