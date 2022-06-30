#pragma once
#include <map>
#include <iostream>
#include <chrono>

#include "Problem.hpp"

class ProblemRegister
{
private:
	std::map<int, Problem*> ProblemMap;
public:
	template <typename T>
	bool Register()
	{
		T* pProblem = new T();
		auto itr = ProblemMap.find(pProblem->ID);
		if (itr == ProblemMap.end())
		{
			ProblemMap[pProblem->ID] = pProblem;
			return true;
		}
		delete pProblem;
		return false;
	};

	void Run(int id)
	{
		auto itr = ProblemMap.find(id);
		if (itr != ProblemMap.end())
		{
			std::cout << "Running problem: " << id << ".\n";
			const std::string desc = itr->second->Description;
			if (desc.empty() == false)
			{
				std::cout << "Description: \n";
				std::cout << desc << "\n";
			}
			std::cout << "==================================\n";
			//run solver
			auto start = std::chrono::steady_clock::now();
			itr->second->Run();
			auto end = std::chrono::steady_clock::now();
			std::chrono::duration<double> elapsed_seconds = end - start;
			std::cout << "elapsed time: " << elapsed_seconds.count() << "s\n";
		}
		else
		{
			std::cout << "Could not find solution to problem: " << id << ".\n";
		}
	};
};
