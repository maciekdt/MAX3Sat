#pragma once
class Clause
{
public:
	Clause(int first,
		int second,
		int third,
		bool firstNegativ,
		bool secondNegativ,
		bool thirdNegativ) {
		firstId = first;
		secondId = second;
		thirdId = third;
		firstSign = firstNegativ;
		secondSign = secondNegativ;
		thirdSign = thirdNegativ;
	};
	~Clause(){};

	int getFirstId() { return firstId; };
	int getSecondId() { return secondId; };
	int getThirdId() { return thirdId; };

	bool getFirstSign() { return firstSign; };
	bool getSecondSign() { return secondId; };
	bool getThridSign() { return thirdId; };

private:
	int firstId;
	int secondId;
	int thirdId;
	bool firstSign;
	bool secondSign;
	bool thirdSign;
};

