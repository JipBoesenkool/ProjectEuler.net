#pragma once
#include "ProblemRegister.hpp"
//TODO: register problems
#include "Problem1.hpp"
void Register(ProblemRegister* pRegister)
{
	pRegister->Register<Problem1>();
};
