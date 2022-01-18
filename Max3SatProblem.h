#pragma once
#include "GAIndividual.h"
#include "Clause.h"
#include <string>
#include <vector>

class Max3SatProblem
{
public: 
	Max3SatProblem();
	void load(std::string path);
	bool contains(int intToCheck);
	int compute(GAIndividual* solution);
	int getNumberOfClauses();

private:
	std::vector<Clause*> *clauses;
	std::vector<int> *variables;
};

