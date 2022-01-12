#pragma once
#include<vector>
#include "GAIndividual.h"
using namespace std;

class GAOptymizer{
private:
	int populationSize;
	float crossoverProbabilty;
	float mutationProbability;
	vector<GAIndividual> solutions;

public:
	void setParameters(int populationSize, float crossoverProbabilty, float mutationProbability);
	void initialize(vector<int> variables);

};

