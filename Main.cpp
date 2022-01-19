#include "Max3SatProblem.h"
#include "GAOptymizer.h"
#include <iostream>
#include <fstream> 
#include <sstream>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
using namespace std;

int main() {
    Max3SatProblem* problem = new Max3SatProblem;
    problem->load("m3s_50_0.txt");

    int iterations = 2;
    GAOptymizer* optymalizator = new GAOptymizer();
    optymalizator->setParameters(50, 0.3, 0.1);
    optymalizator->initialize(problem->getVariables());

    for (int i = 0; i < iterations; i++) {
        optymalizator->runIteration(problem);
        cout << "iteration  : " << i << " || fitness of the best individual : " << optymalizator->findTheBestInPopulation(problem)->fitness(problem) << "\n";
    }
    delete problem;
    delete optymalizator;

    return 0;
}
