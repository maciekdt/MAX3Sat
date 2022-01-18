#include "GAIndividual.h"

GAIndividual::GAIndividual(){
	genotype = new vector<LogicVariable*>();
}

GAIndividual* GAIndividual::mutation(float probability){
	GAIndividual* mutatedInd = new GAIndividual();
	for (int i = 0; i < genotype->size(); i++) {
		float random = ((float)rand()) / (float)RAND_MAX;
		if (random < probability) {
			mutatedInd->genotype->push_back(new LogicVariable(genotype->at(i)->getId(), !(genotype->at(i)->sign)));
		}
		else {
			mutatedInd->genotype->push_back(new LogicVariable(genotype->at(i)->getId(), genotype->at(i)->get));
		}
	}
	return mutatedInd;
}



vector<GAIndividual*>* GAIndividual::crossOver(GAIndividual* individual1, GAIndividual* individual2){
	GAIndividual* child1 = new GAIndividual();
	GAIndividual* child2 = new GAIndividual();
	for (int i = 0; i < individual1->genotype->size(); i++) {
		if (0 + (rand() % (1 - 0 + 1)) == 1) {
			child1->genotype->push_back(new LogicVariable(individual1->genotype->at(i)->id, individual1->genotype->at(i)->sign));
			child2->genotype->push_back(new LogicVariable(individual1->genotype->at(i)->id, individual1->genotype->at(i)->sign));
		}
		else {
			child1->genotype->push_back(new LogicVariable(individual2->genotype->at(i)->id, individual2->genotype->at(i)->sign));
			child2->genotype->push_back(new LogicVariable(individual2->genotype->at(i)->id, individual2->genotype->at(i)->sign));
		}
	}
	vector<GAIndividual*>* result = new vector<GAIndividual*>();
	result->push_back(child1);
	result->push_back(child2);
	return result;
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






