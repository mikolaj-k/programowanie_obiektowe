// 04_opornik.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>

using namespace std;

class Resistor
{
private:
	double _resistance;

public:
	Resistor(double resistance) : _resistance(resistance) {};

	Resistor() : _resistance(0) {};

	double r()
	{
		return _resistance;
	}

	void r(double newResistance)
	{
		_resistance = newResistance;
	}

	Resistor operator +(Resistor & r)
	{
		return Resistor(this->_resistance + r._resistance);
	}

	Resistor operator *(Resistor & r)
	{
		return Resistor(r._resistance / this->_resistance);
	}

	friend ostream & operator <<(ostream & s, const Resistor & res)
	{
		return s << res._resistance;
	}
};


int main(void)
{
	Resistor r1, r2(6);
	r1.r(3);
	cout << (r1 + r2) << " " << (r1 * r2) << endl;

	return 0;
}


