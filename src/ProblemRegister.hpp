#pragma once
#include <map>
#include <iostream>

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
			itr->second->Run();
		}
		else
		{
			std::cout << "Could not find solution to problem: " << id << ".\n";
		}
	};
};
