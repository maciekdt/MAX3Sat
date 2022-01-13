#pragma once
#include <vector>
#include "LogicVariable.h"
#include "Clause.h"
#include "Max3SatProblem.h"

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

