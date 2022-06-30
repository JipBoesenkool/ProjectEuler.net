#pragma once
#include "../Problem.hpp"

#include <iostream>

class Problem1 : public Problem
{
public:
	Problem1()
		: Problem(1)
	{
	};

	void Run() override
	{
		std::cout << "Running problem 1. \n";
	};
};
