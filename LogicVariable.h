#pragma once
class LogicVariable {
public:
	LogicVariable(int id, bool sign) {
		this->id = id;
		this->sign = sign;
	};

	int getId() { return id;  }
	bool getSign() { return sign;  }

private:
	int id;
	bool sign;
};

