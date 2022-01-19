#pragma once
#include<vector>
#include "GAIndividual.h"


using namespace std;

class GAOptymizer {
private:
	const int POPULATIONSIZE = 50;
	const float CROSSOVERPROBABILITY = 0.9;
	const float MUTATIONPROBABILITY = 0.01;
	int populationSize;
	float crossoverProbability;
	float mutationProbability;
	vector<GAIndividual*>* population;
	GAIndividual* chooseParent(Max3SatProblem* environment);
	void deletePopulation();

public:
	void printSolution(Max3SatProblem* environment);
	void setParameters(int populationSize, float crossoverProbabilty, float mutationProbability);
	void initialize(vector<int>* variables);
	void runIteration(Max3SatProblem* enviroment);
	GAIndividual* findTheBestInPopulation(Max3SatProblem* enviroment);
	GAOptymizer();
	~GAOptymizer();
};

