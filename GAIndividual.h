#pragma once
#include <vector>
class GAIndividual
{
public:
	void crossover();
/*Klasa osobnika (rozwi¹zania problemu)
Musi posiadaæ genotyp, czyli rozwi¹zanie w formie tablicy/wektora/listy wartoœci
true/false (konkretny typ i forma przechowywania to decyzja Autora)
Musi posiadaæ metodê Crossover, wykonuj¹c¹ krzy¿owanie osobników
 Musi posiadaæ metodê Mutation, wykonuj¹c¹ mutacjê danego osobnika
Musi posiadaæ metodê Fitness, zwracaj¹c¹ przystosowanie/jakoœæ (ang. fitness) dla
danego osobnika*/
private:
	std::vector<bool> genotype;
};

