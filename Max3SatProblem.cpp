#include "Max3SatProblem.h"

void CMax3SatProblem::load(std::string path) {
	std::ifstream file;
	file.open(filename);
	if (!file.good())
		return std::vector<Clause*>();

	std::vector<Clause*> clauses;

	// potrzebne do splitowania
	std::string line;
	const char separator = ' ';
	std::vector<std::string> outputArray;
	std::string val;

	// odczytujemy dane
	int i = 0;
	while (i < amountOfClauzules) {
		// splitujemy
		std::getline(file, line);
		std::stringstream streamData(line);

		while (std::getline(streamData, val, separator)) {
			outputArray.push_back(val);
		}

		// nowa klauzla wrzucana do wektora
		Clause* read = new Clause(
			stoi(outputArray[1]),
			stoi(outputArray[3]),
			stoi(outputArray[5])
		);

		clauses.push_back(read);
		outputArray.clear();
		i++;
	}

	file.close();
	return clauses;
}