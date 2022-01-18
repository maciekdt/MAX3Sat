#pragma once
#include <vector>
#include "LogicVariable.h"
#include "Max3SatProblem.h"
#include "Clause.h"

using namespace std;

class GAIndividual
{
private:
	vector<LogicVariable*>* genotype;

public:
	GAIndividual();
	GAIndividual* mutation(float probability);
	GAIndividual* crossOver(GAIndividual* otherParent);
	float fitness(Max3SatProblem* enviroment);
	void addToGenotypeRand(int id);
	LogicVariable* getLogicVariableById(int id);
};

