#pragma once
#include <vector>
#include "LogicVariable.h"
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
	float fitness(vector<Clause*>* clauses);

private:
	LogicVariable* getLogicVariableById(int id);

};

