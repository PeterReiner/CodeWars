#include <vector>

using std::vector;

auto at4(vector<vector<bool>>& grid, int index)
{
    auto res = grid.at((index + 4) / 3).at((index + 4) % 3);
    return res;
}

vector<int> get_neighbour_indices(vector<vector<bool>>& grid, int index)
{
    vector<int> result{};
    vector<int> tmp{  };
    if (std::abs(index) > 2)
    {
        tmp = (index < 0) ? vector<int>{index + 5, index + 7} : vector<int>{ index - 5, index - 7 };
    }
    else if (std::abs(index) == 2)
    {
        tmp = (index < 0) ? vector<int>{index + 5, index + 1} : vector<int>{ index - 5, index - 1 };
    }
    else if (std::abs(index) > 0)
    {
        tmp = (index < 0) ? vector<int>{index + 5, index - 1} : vector<int>{ index - 5, index + 1 };
    }
    else
    {
        for (int i{ -4 }; i < 5; i++)
        {
            if (at4(grid, i))
            {
                result.push_back(i);
            }
        }
        return result;
    }
    for (auto i : tmp)
    {
        if (at4(grid, i))
            result.push_back(i);
    }
    if (std::abs(index) == 4)
    {
        vector<int> actual_indices = (index < 0) ? vector<int>{index + 1, index + 2, index + 3, index + 6, index + 4, index + 8} : 
                                                   vector<int>{index - 1, index - 2, index - 3, index - 6, index - 4, index - 8};
        for (int i{ 0 }; i < actual_indices.size() - 1; i += 2)
        {
            if (at4(grid, actual_indices[i]))
            {
                result.push_back(actual_indices[i]);
            }
            else if (at4(grid, actual_indices[i + 1]))
            {
                result.push_back(actual_indices[i + 1]);
            }
        }
    }
    else if (std::abs(index) == 3)
    {
        vector<int> actual_indices = (index < 0) ? vector<int>{index + 1, index - 1, index + 3, index + 4, index + 2, index + 6} :
            vector<int>{ index + 1, index - 1, index - 3, index - 4, index - 2, index - 6 };
        for (int i{ 0 }; i < actual_indices.size() - 1; i++)
        {
            if (at4(grid, (actual_indices[i])))
            {
                result.push_back(actual_indices[i]);
            }
        }
        if (!at4(grid, actual_indices[2]))
            if (at4(grid, actual_indices[5]))
                result.push_back(actual_indices[5]);
    }
    else if (std::abs(index) == 2)
    {
        vector<int> actual_indices = (index < 0) ? vector<int>{index + 3, index + 6, index - 1, index - 2, index + 2, index + 4} :
            vector<int>{ index - 3, index - 6, index + 1, index + 2, index - 2, index - 4 };
        for (int i{ 0 }; i < actual_indices.size() - 1; i += 2)
        {
            if (at4(grid, actual_indices[i]))
            {
                result.push_back(actual_indices[i]);
            }
            else if (at4(grid, actual_indices[i + 1]))
            {
                result.push_back(actual_indices[i + 1]);
            }
        }
    } 
    else
    {
        vector<int> actual_indices = (index < 0) ? vector<int>{index + 3, index - 3, index + 1, index + 4, index - 2, index + 2} :
            vector<int>{ index + 3, index - 3, index - 1, index - 4, index + 2, index - 2 };
        for (int i{ 0 }; i < actual_indices.size() - 1; i++)
        {
            if (at4(grid, actual_indices[i]))
            {
                result.push_back(actual_indices[i]);
            }
        }
        if (!at4(grid, actual_indices[2]))
            if (at4(grid, actual_indices[5]))
                result.push_back(actual_indices[5]);
    }
    return result;
}

unsigned int calc_possibilities(vector<vector<bool>> grid, int index, unsigned short length)
{
    if (length == 1)
        return length;
    at4(grid, index) = false;
    vector<int> neighbours = get_neighbour_indices(grid, index);
    unsigned int sum{0};
    for (auto n : neighbours)
    {
        sum += calc_possibilities(grid, n, length - 1);
    }
    return sum;
}

unsigned int countPatternsFrom(char firstDot, unsigned short length) 
{
    if (length > 9 || !length)
        return 0;
    if (length == 1)
        return length;

    return calc_possibilities(vector<vector<bool>>{ {true, true, true}, { true, true, true }, { true, true, true }}, static_cast<int>(firstDot - 'A') - 4, length);
}
