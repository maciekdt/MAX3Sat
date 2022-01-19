#pragma once
#include<vector>
#include "GAIndividual.h"

using namespace std;

class GAOptymizer {
private:
	const int POPULATIONSIZE = 50;
	const float CROSSOVERPROBABILITY = 0.3;
	const float MUTATIONPROBABILITY = 0.1;
	int populationSize;
	float crossoverProbability;
	float mutationProbability;
	vector<GAIndividual*>* population;
	GAIndividual* chooseParent(Max3SatProblem* environment);

public:
	void setParameters(int populationSize, float crossoverProbabilty, float mutationProbability);
	void initialize(vector<int>* variables);
	void runIteration(Max3SatProblem* enviroment);
	GAIndividual* findTheBestInPopulation(Max3SatProblem* enviroment);
	GAOptymizer();
	~GAOptymizer();
};

