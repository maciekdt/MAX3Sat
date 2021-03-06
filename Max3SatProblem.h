#pragma once
#include "Clause.h"
#include "LogicVariable.h"
#include <string>
#include<vector>
using namespace std;
class Max3SatProblem
{
public: 
	Max3SatProblem();
	~Max3SatProblem();
	void load(std::string path);
	bool contains(int intToCheck);
	int compute(vector<LogicVariable*>* solution);
	int getNumberOfClauses();
	vector<int>* getVariables();

private:
	LogicVariable* getVariableById(int id, vector<LogicVariable*>* solution);
	std::vector<Clause*> *clauses;
	std::vector<int> *variables;
};

