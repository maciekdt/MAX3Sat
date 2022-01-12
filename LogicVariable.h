#pragma once
class LogicVariable{
public:
	int id;
	bool sign;
	LogicVariable(int id, bool sign) {
		this->id = id;
		this->sign = sign;
	};
};

