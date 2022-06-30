#pragma once
#include "../Problem.hpp"

#include <iostream>

class Problem1 : public Problem
{
public:
	Problem1()
		: Problem(1)
	{
		Description = "If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.\nFind the sum of all the multiples of 3 or 5 below 1000.\n";
	};

	void Run() override
	{
		int const n = 3;
		int const m = 5;
		int const t = 1000;

		std::cout << "Running problem 1. \n";
		int sum = 0;
		for (int i = 1; i < t; i++)
		{
			const int num = (i % n == 0 || i % m == 0) ? i : 0;
			sum += num;
		}
		std::cout << "Sum of all multiples of " << n << " and " << m << " below " << t << " = "<< sum <<"\n";
	};
};
