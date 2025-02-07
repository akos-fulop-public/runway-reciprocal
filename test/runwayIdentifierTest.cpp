#include <gtest/gtest.h>

#include <runwayIdentifier.h>

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
