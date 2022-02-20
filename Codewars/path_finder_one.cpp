#include <string>
#include <vector>
#include <sstream>
#include <memory>

using std::string;
using std::vector;
using std::shared_ptr;

vector<string> split_up(string maze)
{
	vector<string> result{};
	std::stringstream ss{ maze };
	string token{};

	while (std::getline(ss, token, '\n'))
	{
		result.push_back(token);
	}
	return result;
}

void find_neighbours(vector<size_t>& neighbours, size_t n, size_t o_i, size_t o_j)
{
	if (o_j % n != 0)
		neighbours.push_back((o_j - 1) + o_i * n);
	if (o_j % n != n - 1)
		neighbours.push_back(o_j + 1 + o_i * n);
	if (o_i % n != 0)
		neighbours.push_back((o_i - 1) * n + o_j);
	if (o_i % n != n - 1)
		neighbours.push_back((o_i + 1) * n + o_j);
}

bool find_path(const vector<string>& maze_v, shared_ptr<vector<vector<bool>>> visited, size_t destination)
{
	size_t n{ maze_v.size() };
	size_t i{ destination / n }, j{ destination % n };
	if (i == n - 1 && j == n - 1)
		return true;
	visited->at(i).at(j) = true;
	if (maze_v.at(i).at(j) == 'W')
		return false;
	vector<size_t> neighbours{};
	find_neighbours(neighbours, n, i, j);

	for (auto n_e : neighbours)
	{
		i = n_e / n, j = n_e % n;
		if (!visited->at(i).at(j))
		{
			if (find_path(maze_v, visited, n_e))
			{
				return true;
			}
		}
			
	}
	return false;
}


/*	 Determine whether one can reach the exit at (n - 1, n - 1)
	 starting from (0, 0) in a n × n maze (represented as a string)
	 and return a boolean value accordingly*/
bool path_finder(string maze) {
	const vector<string> maze_v{ split_up(maze) };
	shared_ptr<vector<vector<bool>>> visited_p = std::make_shared<vector<vector<bool>>>(maze_v.size(), vector<bool>(maze_v.size(), false));
	
	return find_path(maze_v, visited_p, 0);
}