#pragma once
#include <iostream>
class LogicVariable {
public:
	LogicVariable(int id, bool sign) {
		this->id = id;
		this->sign = sign;
	};
	~LogicVariable(){};

	int getId() { return id;  }
	bool getSign() { return sign;  }
	void print() { std::cout << "{" << id << " - " << sign << "}"; };

private:
	int id;
	bool sign;
};

