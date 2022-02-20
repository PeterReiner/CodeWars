# include <string>

std::string disemvowel(const std::string& str) {
    std::string result(str);
    size_t possible_vowel = str.find_first_of("aeiouAEIOU");
    while (possible_vowel != std::string::npos)
    {
        result.erase(possible_vowel, 1);
        possible_vowel = result.find_first_of("aeiouAEIOU");
    }
    return result;
}