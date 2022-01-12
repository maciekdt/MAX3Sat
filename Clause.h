#pragma once
class Clause
{
public:
	int firstId;
	int secondId;
	int thirdId;
	bool firstSign;
	bool secondSign;
	bool thirdSign;

	Clause(int first,
		int second,
		int third,
		bool firstNegativ,
		bool secondNegativ,
		bool thirdNegativ);
};

