#pragma once
#include <vector>
class GAIndividual
{
public:
	void crossover();
/*Klasa osobnika (rozwi�zania problemu)
Musi posiada� genotyp, czyli rozwi�zanie w formie tablicy/wektora/listy warto�ci
true/false (konkretny typ i forma przechowywania to decyzja Autora)
Musi posiada� metod� Crossover, wykonuj�c� krzy�owanie osobnik�w
 Musi posiada� metod� Mutation, wykonuj�c� mutacj� danego osobnika
Musi posiada� metod� Fitness, zwracaj�c� przystosowanie/jako�� (ang. fitness) dla
danego osobnika*/
private:
	std::vector<bool> genotype;
};

