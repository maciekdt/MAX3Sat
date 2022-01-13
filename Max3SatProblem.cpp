#include "Max3SatProblem.h"
#include <fstream>
#include <iostream>
using namespace std;

void Max3SatProblem::load(string path) {
	ifstream file(path);
	string line;
	char separator = ' ';
	string val;

	bool sign = true;
	int id = 0;

	string number = "";
	vector<bool> flags;
	vector<int> ids;
	variables = new vector<int>();
	clauses = new vector<Clause*>();

	if (!file.good()) {
		cout << "file error";
		return;
	}

	if (file) {
		string line;

		while (getline(file, line)) {
			for (int i = 2; i < line.size()-2; i++) {
				if (line[i] == '-') {
					sign = false;
				}
				else if (line[i] != ' ') {
					number += (line[i]);
				}
				else if (line[i] == ' ' && line[i+1] == ' ') {
					id = stoi(number);
					if (!(contains(id)))
						variables->push_back(id);
					ids.push_back(id);
					flags.push_back(sign);
					number = "";
					i++;
				}
			}
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

