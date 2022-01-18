#include "Max3SatProblem.h"
#include "GAOptymizer.h"
#include <iostream>
#include <fstream> 
#include <sstream>
#include <stdio.h>
#include <string.h>
using namespace std;

int main() {
    Max3SatProblem* problem = new Max3SatProblem;
    problem->load("m3s_50_0.txt");

    int iterations = 5;
    GAOptymizer* optymalizator = new GAOptymizer();
    optymalizator->setParameters(10, 0.3, 0.1);
    optymalizator->initialize(problem->getVariables());

    //for (int i = 0; i < iterations; i++) {
        //cout << i << " ";
        //optymalizator.runIteration(problem);
    //}

    return 0;
}
