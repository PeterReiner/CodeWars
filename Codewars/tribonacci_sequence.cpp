#include <vector>

std::vector<int> tribonacci(std::vector<int> signature, int n)
{
    std::vector<int> result;
    if (!n)
        return result;
    result.resize(n);
    result[0] = signature[0];
    result[1] = signature[1];
    result[2] = signature[2];

    for (int i = 3; i < n; i++)
    {
        result[i] = result[i - 1] + result[i - 2] + result[i - 3];
    }
    return result;
}