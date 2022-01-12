#pragma once
#include <vector>
#include "Clause.h"
#include <string>

class Max3SatProblem
{
public: 
	Max3SatProblem();
	void load(std::string path);
	float compute(std::vector<bool> solution);

private:
	std::vector<Clause*> clauses;
	std::vector<int> variables;
};

