#pragma once
#include <vector>
#include "Clause.h"
#include <string>


class Max3SatProblem
{
public: 
	//Max3SatProblem();
	void load(std::string path);
	bool contains(int intToCheck);
	int compute(GAIndividual* solution);
	int getNumberOfClauses();

private:
	std::vector<Clause*> *clauses;
	std::vector<int> *variables;
};

