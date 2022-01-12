#pragma once
#include <vector>
#include "LogicVariable.h"
using namespace std;

class GAIndividual
{
public:
	vector<LogicVariable> genotype;

	GAIndividual* mutation(float probability);
	GAIndividual* crossOver(GAIndividual* otherParent);

};

