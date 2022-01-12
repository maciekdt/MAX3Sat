#include "GAIndividual.h"
#include <set>

GAIndividual* GAIndividual::mutation(float probability){
	for (int i = 0; i < genotype.size(); i++) {
		float random = ((float)rand()) / (float)RAND_MAX;
		if (random < probability) {
			genotype[i].sign = (!genotype[i].sign);
		}
	}
}

GAIndividual* GAIndividual::crossOver(GAIndividual* otherParent){
	GAIndividual* child = new GAIndividual();
	set<int> set;
	for (int i = 0; i < genotype.size(); i++) {
		if (0 + (rand() % (1 - 0 + 1)) == 1) {
			child->genotype[i] = genotype[i];
		}
		else {
			child->genotype[i] = otherParent->genotype[i];
		}
	}
}




