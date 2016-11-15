// 02_kwadrat_i_ulamek.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include<iostream>

using namespace std;

class Rect
{
private:
	double _a, _b;
public:
	Rect()
	{
		_a = _b = 1;
	}
	Rect(double a)
	{
		this->_a = this->_b = a;
	}
	Rect(double a, double b)
	{
		this->_a = a;
		this->_b = b;
	}

	double getA() const
	{
		return _a;
	}
	double getB() const
	{
		return _b;
	}

	double getDiagonal() const
	{
		return sqrt(_a * _a + _b * _b);
	}

	double getArea() const
	{
		return _a * _b;
	}

	bool isLargerThan(const Rect in_rect) const
	{
		return this->getArea() > in_rect.getArea();
	}

	void info() const
	{
		cout << "Rect[" << this->_a << ", " << this->_b << "]" << endl;
	}
};

class Frac
{
private:
	int _licz, _mian = 1;

	int _nwd(int a, int b)
	{
		while (a != b)
			if (a > b)
				a -= b;
			else
				b -= a;
		return a;
	}

	//TODO walidacja
public:
	Frac()
	{
		_licz = 0;
	}

	Frac(int i)
	{
		_licz = i;
	}

	Frac(int licz, int mian)
	{
		if (licz < 0)
		{
			int nwdInt = this->_nwd(-licz, mian);
			_licz = licz / nwdInt;
			_mian = mian / nwdInt;
		}
		else if (mian < 0)
		{
			int nwdInt = this->_nwd(licz, -mian);
			_licz = -licz / nwdInt;
			_mian = -mian / nwdInt;

		}
		else if (mian == 0)
		{
			cout << "Nope" << endl;
		}
		else if (licz == 0) // TODO walidacj� w oddzielnej klasie prywatnej
		{
			_licz = licz;
			_mian = 1;
		}
		else
		{
			int nwdInt = this->_nwd(licz, mian);
			_licz = licz / nwdInt;
			_mian = mian / nwdInt;
		}
	}

	Frac& add(const Frac& f)
	{
		if (f._mian == _mian)
			_licz += f._licz;
		else
		{
			_licz = _licz * f._mian + f._licz * _mian;
			_mian *= f._mian;
		}

		return *this;
	}

	void info() const
	{
		cout << _licz << "/" << _mian << endl;
	}
};

int main()
{
	cout << "***********************PROSTOKAT***********************" << endl;
	Rect test = Rect(3, 5);
	Rect test1 = Rect(5, 5);

	cout << "a: " << test.getA() << endl;
	cout << "b: " << test.getB() << endl;
	cout << "przekatna: " << test.getDiagonal() << endl;
	cout << "pole: " << test.getArea() << endl;
	cout << "wiekszy: " << test.isLargerThan(test1) << endl;
	test.info();
	test1.info();

	cout << endl << "***********************ULAMKI***********************" << endl;

	Frac testFract = Frac(6, -10);
	testFract.info();

	Frac testFract1 = Frac(3);
	testFract1.info();

	Frac testFract2 = Frac();
	testFract2.info();

	testFract2 = testFract.add(testFract1);
	testFract2.info();


	return 0;
}





