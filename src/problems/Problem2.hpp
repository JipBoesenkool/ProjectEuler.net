#pragma once
#include "../Problem.hpp"

#include <iostream>

class Problem2 : public Problem
{
public:
	Problem2()
		: Problem(2)
	{
		const char* cDesc =
			"Each new term in the Fibonacci sequence is generated by adding the previous two terms."
			"By starting with 1 and 2, the first 10 terms will be: "
			"1, 2, 3, 5, 8, 13, 21, 34, 55, 89, ..."
			"By considering the terms in the Fibonacci sequence whose values do not exceed four million, find the sum of the even-valued terms. ";
		Description = std::string(cDesc);
	};

	void Run() override
	{
		int const max = 4000000;

		int prev = 0;
		int curr = 1;
		int next = prev + curr;
		long sum = 0;
		while (curr < max)
		{
			prev = curr;
			curr = next;
			next = prev + curr;
			if (next % 2 == 0)
			{
				std::cout << "\t" << sum << " + " << next << " = ";
				sum += next;
				std::cout << sum  << "\n";
			}
			
		}
		std::cout << "sum of the even-valued terms below " << max << " = " << sum << "\n";
	};
};
