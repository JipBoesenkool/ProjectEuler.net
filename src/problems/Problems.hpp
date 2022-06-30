#pragma once
#include "ProblemRegister.hpp"
//TODO: register problems
#include "Problem1.hpp"
#include "Problem2.hpp"
#include "Problem6.hpp"
void Register(ProblemRegister* pRegister)
{
	pRegister->Register<Problem1>();
	pRegister->Register<Problem2>();
	pRegister->Register<Problem6>();
};
