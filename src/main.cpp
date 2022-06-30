#include "ProblemRegister.hpp"
#include "String.hpp"

#include <iostream>

//TODO: register problems
#include "problems/Problems1.hpp"
void Register(ProblemRegister* pRegister)
{
	pRegister->Register<Problem1>();
};

//vars
ProblemRegister problems;
bool bIsRunning = true;

using CommandFn = void (*)(const std::vector<std::string>& );
//commands
void Help(const std::vector<std::string>& args)
{
	std::cout << "==========================================\n";
	std::cout << "Command [args].\n";
	std::cout << "Help - Displays all commands.\n";
	std::cout << "Exit - Exits the application.\n";
	std::cout << "Run [int] - runs the problem solver identified by the ID.\n";
};

void Exit(const std::vector<std::string>& args)
{
	bIsRunning = false;
};

void Run(const std::vector<std::string>& args)
{
	if (args.size() != 2)
	{
		return;
	}

	try
	{
		int id = std::stoi( args[1] );
		problems.Run(id);
	}
	catch (const std::exception&)
	{
		std::cerr << "Invalid parameter, expected a int.\n";
	}
};

//loop
int main()
{
	std::cout << "Solvers for https://projecteuler.net\n";
	Register(&problems);

	//commands
	std::map<std::string, CommandFn> cmdMap;
	cmdMap["help"] = &Help;
	cmdMap["exit"] = &Exit;
	cmdMap["run"] = &Run;

	while (bIsRunning)
	{
		std::string input;
		std::vector<std::string> args;
		std::cout << "==========================================\n";
		std::getline(std::cin, input);
		
		if (input.empty())
		{
			Help(args);
			continue;
		}

		args = String::Split(input, ' ');
		std::string cmd = String::ToLower( args[0] );

		auto itr = cmdMap.find(cmd);
		if (itr != cmdMap.end())
		{
			itr->second(args);
		}
		else
		{
			Help(args);
		}
	}
}
