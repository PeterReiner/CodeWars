#include <algorithm>
#include <vector>


class Kata
{
public:
    std::vector<int> sortArray(std::vector<int> array)
    {
        std::vector<int> odds;
        for (int i = 0; i < array.size(); i++)
        {
            if (array.at(i) % 2 == 1)
                odds.push_back(array.at(i));
        }

        std::sort(odds.begin(), odds.end());
        for (int i = 0, j = 0; i < array.size(); i++)
        {
            if (array.at(i) % 2 == 1)
            {
                array.at(i) = odds.at(j);
                j++;
            }
        }

        return array;
    }
};