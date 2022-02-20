#include "pch.h"
#include "../Codewars/multiply_numbers_as_string.cpp"

TEST(multiply_numbers_as_string_test, handle_edge_cases)
{
    EXPECT_EQ(multiply("2", "0"), "0");
    EXPECT_EQ(multiply("0", "30"), "0");
    EXPECT_EQ(multiply("0000001", "3"), "3");
    EXPECT_EQ(multiply("1009", "03"), "3027");
}

TEST(multiply_numbers_as_string_test, handle_advanced_fixed_assertions)
{
    EXPECT_EQ(multiply("98765", "56894"), "5619135910");
    EXPECT_EQ(multiply("1020303004875647366210", "2774537626200857473632627613"), "2830869077153280552556547081187254342445169156730");
    EXPECT_EQ(multiply("58608473622772837728372827", "7586374672263726736374"), "444625839871840560024489175424316205566214109298");
    EXPECT_EQ(multiply("9007199254740991", "9007199254740991"), "81129638414606663681390495662081");
}