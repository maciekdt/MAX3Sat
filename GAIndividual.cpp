#include "GAIndividual.h"

GAIndividual::GAIndividual(){
	genotype = new vector<LogicVariable*>();
}

GAIndividual::~GAIndividual() {
	if (this != NULL) {
		if (genotype != NULL) {
			for (int i = 0; i < genotype->size(); i++) {
				if (genotype->at(i) != NULL) delete genotype->at(i);
			}
			delete genotype;
		}
	}
}

GAIndividual* GAIndividual::mutation(float probability){
	GAIndividual* mutatedInd = new GAIndividual();
	for (int i = 0; i < genotype->size(); i++) {
		float random = ((float)rand()) / (float)RAND_MAX;
		if (random < probability) {
			mutatedInd->genotype->push_back(new LogicVariable(genotype->at(i)->getId(), !(genotype->at(i)->getSign())));
		}
		else {
			mutatedInd->genotype->push_back(new LogicVariable(genotype->at(i)->getId(), genotype->at(i)->getSign()));
		}
	}
	delete this;
	return mutatedInd;
}



vector<GAIndividual*>* GAIndividual::crossOver(GAIndividual* individual1, GAIndividual* individual2, float probability){
	GAIndividual* child1 = new GAIndividual();
	GAIndividual* child2 = new GAIndividual();
	float random = ((float)rand()) / (float)RAND_MAX;
	if (random < probability) {
		for (int i = 0; i < individual1->genotype->size(); i++) {
			if (0 + (rand() % (1 - 0 + 1)) == 1) {
				child1->genotype->push_back(new LogicVariable(individual1->genotype->at(i)->getId(), individual1->genotype->at(i)->getSign()));
				child2->genotype->push_back(new LogicVariable(individual2->genotype->at(i)->getId(), individual2->genotype->at(i)->getSign()));
			}
			else {
				child1->genotype->push_back(new LogicVariable(individual2->genotype->at(i)->getId(), individual2->genotype->at(i)->getSign()));
				child2->genotype->push_back(new LogicVariable(individual1->genotype->at(i)->getId(), individual1->genotype->at(i)->getSign()));
			}
		}
	}
	else {
		for (int i = 0; i < individual1->genotype->size(); i++) {
			child1->genotype->push_back(new LogicVariable(individual1->genotype->at(i)->getId(), individual1->genotype->at(i)->getSign()));
			child2->genotype->push_back(new LogicVariable(individual2->genotype->at(i)->getId(), individual2->genotype->at(i)->getSign()));
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
		if (genotype->at(i)->getId() == id) return genotype->at(i);
	}
	return nullptr;
}






