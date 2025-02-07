#include <gtest/gtest.h>

#include <runwayIdentifier.h>

TEST(Validate, EmptyString) {
	EXPECT_FALSE(isValidRunwayId(std::string()));
}

TEST(Validate, TwoDigitNumber) {
	EXPECT_TRUE(isValidRunwayId(std::string("13")));
}

TEST(Validate, LargeNumber) {
	EXPECT_FALSE(isValidRunwayId(std::string("37")));
}

TEST(Validate, Zero) {
	EXPECT_FALSE(isValidRunwayId(std::string("0")));
}

TEST(Validate, PaddedSingleDigitNumber) {
	EXPECT_TRUE(isValidRunwayId(std::string("06")));
}

TEST(Validate, DoublePaddedSingleDigitNumber) {
	EXPECT_FALSE(isValidRunwayId(std::string("006")));
}

TEST(Validate, PaddedTwoDigitNumber) {
	EXPECT_FALSE(isValidRunwayId(std::string("017")));
}

TEST(Validate, SingleDigitLetter) {
	EXPECT_TRUE(isValidRunwayId(std::string("7L")));
}

TEST(Validate, TwoDigitsLetter) {
	EXPECT_TRUE(isValidRunwayId(std::string("18R")));
}

TEST(Validate, SingleDigitInvalidLetter) {
	EXPECT_FALSE(isValidRunwayId(std::string("8M")));
}

TEST(Validate, PaddedSingleDigitInvalidLetter) {
	EXPECT_FALSE(isValidRunwayId(std::string("09X")));
}

TEST(Validate, WhitespaceSingleDigit) {
	EXPECT_FALSE(isValidRunwayId(std::string(" 7")));
}

TEST(Validate, TwoDigitsLowerCaseLetter) {
	EXPECT_FALSE(isValidRunwayId(std::string("18r")));
}

TEST(Reciprocal, LowNumber) {
	EXPECT_EQ(getReciprocalRunwayId("08"), "26");
}

TEST(Reciprocal, Overflow) {
	EXPECT_EQ(getReciprocalRunwayId("32"), "14");
}

TEST(Reciprocal, Padding) {
	EXPECT_EQ(getReciprocalRunwayId("20"), "02");
}

TEST(Reciprocal, Center) {
	EXPECT_EQ(getReciprocalRunwayId("13C"), "31C");
}

TEST(Reciprocal, Right) {
	EXPECT_EQ(getReciprocalRunwayId("28R"), "10L");
}

TEST(Reciprocal, Left) {
	EXPECT_EQ(getReciprocalRunwayId("3L"), "21R");
}
