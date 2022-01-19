#include "GAOptymizer.h"

GAOptymizer::GAOptymizer() {
	population = new vector<GAIndividual*>();
	populationSize = POPULATIONSIZE;
	crossoverProbability = CROSSOVERPROBABILITY;
	mutationProbability = MUTATIONPROBABILITY;
}

GAOptymizer::~GAOptymizer() {
	if (this != NULL) {
		deletePopulation();
	}
}

GAIndividual* GAOptymizer::chooseParent(Max3SatProblem* enviroment){
	int max = population->size() - 1;
	int min = 0;
	GAIndividual* parent1 = population->at(rand() % (max - min + 1) + min);
	GAIndividual* parent2 = population->at(rand() % (max - min + 1) + min);

	if (parent1->fitness(enviroment) > parent2->fitness(enviroment)) return parent1;
	return parent2;
}

void GAOptymizer::deletePopulation(){
	if (population != NULL) {
		for (int i = 0; i < population->size(); i++) {
			if (population->at(i) != NULL)
				delete population->at(i);
		}
		delete population;
	}
}

void GAOptymizer::setParameters(int populationSize, float crossoverProbabilty, float mutationProbability){
	this->populationSize = populationSize;
	this->crossoverProbability = crossoverProbabilty;
	this->mutationProbability = mutationProbability;
}

void GAOptymizer::initialize(vector<int>* variables){
	for (int i = 0; i < populationSize; i++) {
		GAIndividual* ind = new  GAIndividual();			
		for (int i = 0; i < variables->size(); i++) {	
			ind->addToGenotypeRand(variables->at(i));
		}
		population->push_back(ind);
	}
}


void GAOptymizer::runIteration(Max3SatProblem* environment){
	vector<GAIndividual*>* newPopulation = new vector<GAIndividual*>();	//nowy wskaznik
	while (newPopulation->size() < population->size()) {
		GAIndividual* parent1 = chooseParent(environment);
		GAIndividual* parent2 = chooseParent(environment);
		vector<GAIndividual*>* children = GAIndividual::crossOver(parent1,parent2,crossoverProbability);
		GAIndividual* child1 = children->at(0);
		GAIndividual* child2 = children->at(1);
		child1 = child1->mutation(mutationProbability);
		child2 = child2->mutation(mutationProbability);
		newPopulation->push_back(child1);
		newPopulation->push_back(child2);
	}
	deletePopulation();
	population = newPopulation;
}

GAIndividual* GAOptymizer::findTheBestInPopulation(Max3SatProblem* environment){
	GAIndividual* bestInd = population->at(0);
	float bestFitness = bestInd->fitness(environment);
	for (int i = 1; i < population->size(); i++) {
		float newFitnes = population->at(i)->fitness(environment);
		if (newFitnes > bestFitness) {
			bestInd = population->at(i);
			bestFitness = newFitnes;
		}
	}
	return bestInd;
}
