#pragma once
#include <vector>
#include <algorithm>
#include <sstream>

namespace String
{
	std::string ToLower( const std::string& str )
	{
		std::string result = str;
		std::for_each(result.begin(), result.end(), [](char& c)
		{
			c = std::tolower(c);
		});
		return result;
	};

	std::vector<std::string> Split(const std::string& str, char delim) {
		std::vector<std::string> result;
		std::istringstream iss(str);
		for (std::string s; iss >> s; )
		{
			result.push_back(s);
		}
		return result;
	};
};
