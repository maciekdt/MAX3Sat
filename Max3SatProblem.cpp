#include "Max3SatProblem.h"
#include <fstream>
#include <iostream>
using namespace std;

void Max3SatProblem::load(std::string path) {
	ifstream file;
	file.open(path);
	
	if (!file)
		return;

	std::string line;
	char separator = ' ';
	std::string val;

	bool sign = true;
	int id = 0;

	string number = "";
	vector<bool> flags;
	vector<int> ids;
	variables = new vector<int>();
	clauses = new vector<Clause*>();

	if (file.is_open()) {
		string line;


		while (getline(file, line)) {
			for (int i = 2; i < line.size()-2; i++) {
				if (line[i] == '-') {
					sign = false;
				}
				else if (line[i] != ' ') {
					number += (line[i]);
				}
				else if (line[i] == '  ') {
					id = stoi(number);
					if (!(contains(id)))
						variables->push_back(id);
					ids.push_back(id);
					flags.push_back(sign);
					number = "";
				}
			}
			clauses->push_back(new Clause(ids[0], ids[1], ids[2], 
											flags[0], flags[1], flags[2]));
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

int Max3SatProblem::compute(vector<bool> solution) { // zle
	int counter = 0;
	bool f_Flag;
	bool s_Flag;
	bool t_Flag;

	for (int i = 0; i < clauses->size(); i++) {
		f_Flag = (solution.at(clauses->at(i)->firstId) && clauses->at(i)->firstSign);
		s_Flag = (solution.at(clauses->at(i)->secondId) && clauses->at(i)->secondSign);
		t_Flag = (solution.at(clauses->at(i)->thirdId) && clauses->at(i)->thirdSign);
		if (f_Flag || s_Flag || t_Flag)
			counter++;
	}
	return counter;
}

