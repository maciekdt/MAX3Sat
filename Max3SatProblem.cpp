#pragma warning(disable : 4996)
#include "Max3SatProblem.h"
#include <fstream>
#include <iostream>

using namespace std;

Max3SatProblem::Max3SatProblem(){
	variables = new vector<int>();
	clauses = new vector<Clause*>();
}

Max3SatProblem::~Max3SatProblem(){
	if (this != NULL) {
		if (clauses != NULL) {
			for (int i = 0; i < clauses->size(); i++) {
				if (clauses->at(i) != NULL) delete clauses->at(i);
			}
			delete clauses;
		}
		if (variables != NULL) delete variables;
	}
}

void Max3SatProblem::load(string path) {
	ifstream file(path);

	if (!file.good()) {
		cout << "file error";
		return;
	}
	
	if (file) {
		string line;
		char* str;
		while (getline(file, line)) {
			vector<bool> flags;
			vector<int> ids;
			str = new char[line.size()+1];
			
			strcpy(str, line.c_str());
			for (int i = 0; i < line.size(); i++) {
				str[i] = line.at(i);
			}
			str[line.length()] = '\0';


			char* pch;
			pch = strtok(str, " )(");

			while (pch != NULL) {
				if (pch[0] == '-') {
					flags.push_back(false);
				}
				else {
					flags.push_back(true);
				}
				ids.push_back(abs(stoi(pch)));
				if (!(contains(abs(stoi(pch)))))
					variables->push_back(abs(stoi(pch)));
				pch = strtok(NULL, " )(");
			}
			delete str;
			delete pch;
			clauses->push_back(new Clause(ids.at(0), ids.at(1), ids.at(2),
				flags.at(0), flags.at(1), flags.at(2)));
		}
		file.close();
	}
}

bool Max3SatProblem::contains(int intToCheck) {
	for (int i = 0; i < variables->size(); i++) {
		if (variables->at(i) == intToCheck)
			return true;
	}
	return false;
}

int Max3SatProblem::compute(vector<LogicVariable*>* solution) {
	int numberFitedClauses = 0;
	bool first;
	bool second;
	bool third;

	for (int i = 0; i < clauses->size(); i++) {
		first = (clauses->at(i)->getFirstSign() == getVariableById(clauses->at(i)->getFirstId(), solution)->getSign());
		second = (clauses->at(i)->getSecondSign() == getVariableById(clauses->at(i)->getSecondId(), solution)->getSign());
		third = (clauses->at(i)->getThridSign() == getVariableById(clauses->at(i)->getThirdId(), solution)->getSign());
		if (first || second || third) numberFitedClauses++;
	}
	return numberFitedClauses;
}

int Max3SatProblem::getNumberOfClauses(){
	return clauses->size();
}

vector<int>* Max3SatProblem::getVariables()
{
	return variables;
}

LogicVariable* Max3SatProblem::getVariableById(int id, vector<LogicVariable*>* solution)
{
	for (int i = 0; i < solution->size(); i++) {
		if (solution->at(i)->getId() == id)
			return solution->at(i);
	}

	return nullptr;
}

