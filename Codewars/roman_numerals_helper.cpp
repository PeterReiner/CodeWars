#include <string>
#include <vector>
#include <map>


class RomanHelper {
public:
    std::string to_roman(unsigned int number) {
        std::string result{};
        std::vector<int> numbers{ 1, 5, 10, 50, 100, 500, 1000 };
        std::vector<std::string> roman_literals{ "I", "V", "X", "L", "C", "D", "M" };

        for (int i = 0; i < 3; i++)
        {
            int remainder = number % numbers[2 + i * 2];
            if (remainder == 0)
                continue; //nothing to do

            if (remainder + numbers[0 + i * 2] == numbers[2 + i * 2])
            {//one step before next bigger literal
                result.insert(0, roman_literals[0 + i * 2] + roman_literals[2 + i * 2]);
                number -= remainder;
                continue;
            }
            else if (remainder / numbers[1 + i * 2] == 1)
            {
                remainder -= numbers[1 + i * 2];
                if (remainder)
                    result.insert(0, std::string(remainder / numbers[0 + i * 2], roman_literals[0 + i * 2].at(0)));
                result.insert(0, roman_literals[1 + i * 2]);
                number = number - (numbers[1 + i * 2] + remainder);
                continue;
            }
            if (remainder)
            {
                if (remainder + numbers[0 + i * 2] == numbers[1 + i * 2])
                    result.insert(0, roman_literals[0 + i * 2] + roman_literals[1 + i * 2]);
                else
                    result.insert(0, std::string(remainder / numbers[0 + i * 2], roman_literals[0 + i * 2].at(0)));
            }
            number -= remainder;
        }
        result.insert(0, std::string(number / 1000, 'M'));

        return result;
    }
    int from_roman(std::string rn) {
        int result{0};
        std::map<std::string, int> mapping{ {"M", 1000}, {"D", 500}, {"C", 100}, {"L", 50}, {"X", 10}, {"V", 5},
            {"I", 1}, {"CM", 900}, {"CD", 400}, {"XC", 90}, {"XL", 40}, {"IX", 9}, {"IV", 4} };


        std::string power_of_ten{"CXI"};
        std::vector<std::string>  next_higher{ "MD", "CL", "XV" };
        for (int i{ 0 }; i < rn.size(); i++)
        {
            if (power_of_ten.find(rn.at(i)) != std::string::npos)
            {
                for (int j{ 0 }; j < power_of_ten.size(); j++)
                {
                    if (i + 1 < rn.size() && power_of_ten.at(j) == rn.at(i) && next_higher.at(j).find(rn.at(i + 1)) != std::string::npos)
                    {
                        result += mapping.at(std::string(1, rn.at(i)).append(1, rn.at(i + 1)));
                        i++;
                        break;
                    }
                    else if (power_of_ten.at(j) == rn.at(i))
                    {
                        result += mapping.at(std::string(1, rn.at(i)));
                        break;
                    }
                }
            }
            else {
                result += mapping.at(std::string(1, rn.at(i)));
            }
        }

        return result;
    }
} RomanNumerals;