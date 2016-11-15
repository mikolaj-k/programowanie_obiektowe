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
		else if (licz == 0) // TODO walidacjê w oddzielnej klasie prywatnej
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

	static Frac add(const Frac& f1, const Frac& f2)
	{
		//TODO
	};

	Frac& mul(const Frac& f)
	{
		//TODO
	};

	Frac& div(const Frac& f)
	{
		//TODO
	};

	static Frac& div(const Frac& f1, const Frac& f2)
	{
		//TODO
	};

	static Frac& sub(const Frac& f1, const Frac& f2)
	{
		//TODO
	};

	void show() const
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
	// 2 * ( (2 + 4/10)*5 - 4 ) / (24/15) = 10
	Frac f1 = Frac(2).mul(Frac::sub(Frac(5).mul(Frac::add(Frac(2), Frac(4, 10))), Frac(4))).div(Frac(24, 15));

	// 7 - 1/3 + (2/6 * 1114) / 111
	Frac f2 = Frac(7);//.sub(Frac(1, 3));//.add(Frac::div(Frac(2, 6).mul(Frac(1114)), Frac(111)));
	f1.show(); std::cout << " ";
	f2.show(); std::cout << std::endl;


	return 0;
}





