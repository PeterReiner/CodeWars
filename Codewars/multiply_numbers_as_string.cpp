#ifndef _MULTIPLY_NUMBERS_H_
#define _MULTIPLY_NUMBERS_H_

#include <algorithm>
#include <cmath>
#include <iterator>
#include <string>


using std::string;

string multiply(string a, string b) {
	if (a.empty() || b.empty())
		return "0";
	string result(a.size() + b.size() + 1, '0');
	char carry{ 0 };

	for (int i{ static_cast<int>(b.size()) - 1 }; i >= 0; i--)
	{
		if (b.at(i) == '0') //nothing to do here
			continue;
		auto it{ result.begin()};
		std::advance(it, b.size() - 1 - i);
		for (int j{ static_cast<int>(a.size()) - 1 }; j >= 0; j--)
		{
			char tmp{ (b.at(i) - '0') * (a.at(j) - '0') + carry + (*it - '0')};
			*it = (tmp % 10) + '0';
			carry = tmp / 10;
			it++;
		}
		while (carry)
		{
			*it = (carry % 10) + '0';
			carry = carry / 10;
			it++;
		}
	}
	while (!result.empty() && result.size() > 1 && result.back() == '0')
		result.pop_back();
	std::reverse(result.begin(), result.end());
	return result;
}




#endif