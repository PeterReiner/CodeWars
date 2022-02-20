#include "pch.h"

#include "../../Codewars/Codewars/roman_numerals_helper.cpp"

TEST(roman_numerals_helper_test, handles_integer_input)
{
    EXPECT_EQ(RomanNumerals.to_roman(1000), "M");
    EXPECT_EQ(RomanNumerals.to_roman(4), "IV");
    EXPECT_EQ(RomanNumerals.to_roman(1), "I");
    EXPECT_EQ(RomanNumerals.to_roman(9), "IX");
    EXPECT_EQ(RomanNumerals.to_roman(1990), "MCMXC");
    EXPECT_EQ(RomanNumerals.to_roman(2008), "MMVIII");
    EXPECT_EQ(RomanNumerals.to_roman(3999), "MMMCMXCIX");
}

TEST(roman_numerals_helper_test, handles_string_input)
{
    EXPECT_EQ(RomanNumerals.from_roman("XXI"), 21);
    EXPECT_EQ(RomanNumerals.from_roman("I"), 1);
    EXPECT_EQ(RomanNumerals.from_roman("IX"), 9);
    EXPECT_EQ(RomanNumerals.from_roman("IV"), 4);
    EXPECT_EQ(RomanNumerals.from_roman("MMVIII"), 2008);
    EXPECT_EQ(RomanNumerals.from_roman("MDCLXVI"), 1666);
}