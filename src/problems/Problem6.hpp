#pragma once
#include "../Problem.hpp"

#include <iostream>

class Problem6 : public Problem
{
public:
	Problem6()
		: Problem(6)
	{
		const char* cDesc =
			"The difference between the sum of the squares of the first ten natural numbers and the square of the sum is \n"
			"3025 - 385 = 2640 \n"
			"Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.\n";
		Description = std::string(cDesc);
	};

	void Run() override
	{
		int const limit = 100;

		int sumNat = 0;
		int sumSq = 0;
		for (int i = 0; i <= limit; i++)
		{
			sumNat += i;
			sumSq  += i*i;
		}
		sumNat = sumNat*sumNat;
		const int sum = sumNat - sumSq;
		std::cout << sumNat << " - " << sumSq << " = " << sum << "\n";
	};
};
