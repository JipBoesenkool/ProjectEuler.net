#pragma once
#include "../Problem.hpp"

#include <iostream>
#include <vector>
#include <cstdint>

class Problem3 : public Problem
{
public:
	Problem3()
		: Problem(3)
	{
		const char* cDesc =
			"The prime factors of 13195 are 5, 7, 13 and 29.\n"
			"What is the largest prime factor of the number 600851475143?\n";
		Description = std::string(cDesc);
	};

	//Works its way up from the lower prime (excluding 1 and 2) to the highest
	void Run() override
	{
		long long i;
		//long long n = 13195; //example
		long long n = 600851475143;
		for (i = 3; i <= n; i += 2)
		{
			while (n % i == 0)
			{
				std::cout << "N: " << n << "\n";
				std::cout << "I: " << i << "\n";
				n /= i;
			}

			if (n == 1) break;
		}

		std::cout << "Largest prime factor of " << n << " is " << i << "\n";
	};

	void FindAllPrimes(int n)
	{
		std::cout << "Primes: ";
		std::vector<int> primes;
		const int num = n;
		for (int i = num - 1; i > 2; i--)
		{
			if ((num % i == 0))
			{
				if (IsPrime(i))
				{
					primes.push_back(i);
					std::cout << i << ", ";
				}
			}
		}
		std::cout << "\n";
	}

	bool IsPrime(int n)
	{
		const int num = n;
		for (int i = 2; i < num; i++)
		{
			if (num % i == 0)
			{
				return false;
			}
		}
		//no div found
		return true;
	}
};
