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

float GAIndividual::fitness(vector<Clause*>* clauses){
	int numberFitedClauses = 0;
	for (int i = 0; i < clauses->size(); i++) {
		bool first = (clauses->at(i)->firstSign == getLogicVariableById(clauses->at(i)->firstId)->sign);
		bool second = (clauses->at(i)->secondSign == getLogicVariableById(clauses->at(i)->secondId)->sign);
		bool third = (clauses->at(i)->thirdSign == getLogicVariableById(clauses->at(i)->thirdId)->sign);
		if (first || second || third) numberFitedClauses++;
	}
	return ((float)numberFitedClauses) / ((float)clauses->size());
}

LogicVariable* GAIndividual::getLogicVariableById(int id){
	for (int i = 0; i < genotype->size(); i++) {
		if (genotype->at(i)->id == id) return genotype->at(i);
	}
	return nullptr;
}






