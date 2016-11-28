// 03_wektor3d.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>

using namespace std;

class Wektor3d
{
private:
	double _x, _y, _z;

public:
	Wektor3d()
	{
		_x = 0;
		_y = 0;
		_z = 0;
	};

	Wektor3d(double x, double y, double z)
	{
		_x = x;
		_y = y;
		_z = z;
	};

	Wektor3d operator- () const
	{
		return Wektor3d(-this->_x, -this->_y, -this->_z);
	}

	Wektor3d operator+(const Wektor3d& wektor1)
	{
		return Wektor3d((this->_x + wektor1._x), (this->_y + wektor1._y), (this->_z + wektor1._z));
	}

	Wektor3d operator-(const Wektor3d& wektor1)
	{
		return Wektor3d((this->_x - wektor1._x), (this->_y - wektor1._y), (this->_z - wektor1._z));

	}

	Wektor3d operator* (const double x)
	{
		return  Wektor3d((this->_x * x), (this->_y * x), (this->_z * x));
	}

	double operator*(const Wektor3d& wektor1)
	{
		return this->_x * wektor1._x + this->_y * wektor1._y + this->_z * wektor1._z;
	}

	friend ostream & operator <<(ostream & s, const Wektor3d & w)
	{
		return s << "[" << w._x << ", " << w._y << ", " << w._z << "]"; //TODO <<
	}
};

int main()
{
	Wektor3d wektor1 = Wektor3d(3, 4, 6);
	Wektor3d wektor2 = Wektor3d(1, 2, 3);
	double scalar;


	cout << wektor1 << endl;
	cout << wektor2 << endl;

	cout << endl << "**************ZWROT**************" << endl;
	cout << "-" << wektor1 << " = " << -wektor1 << endl;

	cout << endl << "************DODAWANIE************" << endl;
	cout << wektor1 << " + " << wektor2 << " = " << wektor1 + wektor2 << endl;

	cout << endl << "***********ODEJMOWANIE***********" << endl;
	cout << wektor1 << " - " << wektor2 << " = " << wektor1 - wektor2 << endl;

	cout << endl << "********MNOZENIE SKALARNE********" << endl;
	cout << wektor1 << " * " << wektor2 << " = " << wektor1 * wektor2 << endl;

	cout << endl << "************MNOZENIE*************" << endl;
	cout << wektor1 << " * " << 2 << " = " << wektor1 * 2 << endl;


	return 0;
}



