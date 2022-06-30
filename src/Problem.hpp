#pragma once

#include <string>

class Problem
{
public:
	int ID;
	std::string Description;
protected:
	Problem(int id, const std::string& description = "")
		: ID(id), Description(description)
	{
	};
	~Problem() = default;
public:
	virtual void Run() = 0;
};
