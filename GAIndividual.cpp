#include "GAIndividual.h"

GAIndividual::GAIndividual(){
	genotype = new vector<LogicVariable*>();
}

GAIndividual* GAIndividual::mutation(float probability){
	GAIndividual* mutatedInd = new GAIndividual();
	for (int i = 0; i < genotype->size(); i++) {
		float random = ((float)rand()) / (float)RAND_MAX;
		if (random < probability) {
			mutatedInd->genotype->push_back(new LogicVariable(genotype->at(i)->id, !(genotype->at(i)->sign)));
		}
		else {
			mutatedInd->genotype->push_back(new LogicVariable(genotype->at(i)->id, genotype->at(i)->sign));
		}
	}
	return mutatedInd;
}


//Dopracowac!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
GAIndividual* GAIndividual::crossOver(GAIndividual* other){
	GAIndividual* child = new GAIndividual();
	for (int i = 0; i < genotype->size(); i++) {
		if (0 + (rand() % (1 - 0 + 1)) == 1) {
			child->genotype->push_back(new LogicVariable(genotype->at(i)->id, genotype->at(i)->sign));
		}
		else {
			child->genotype->push_back(new LogicVariable(other->genotype->at(i)->id, other->genotype->at(i)->sign));
		}
	}
	return child;
}

float GAIndividual::fitness(Max3SatProblem* enviroment){
	return ((float)enviroment->compute(genotype) / (float)enviroment->getNumberOfClauses());
}

void GAIndividual::addToGenotypeRand(int id){
	bool random = 0 + (rand() % (1 - 0 + 1)) == 1;
	genotype->push_back(new LogicVariable(id, random));
}


LogicVariable* GAIndividual::getLogicVariableById(int id){
	for (int i = 0; i < genotype->size(); i++) {
		if (genotype->at(i)->id == id) return genotype->at(i);
	}
	return nullptr;
}






