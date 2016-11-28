// 04_odcinek.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <algorithm>

using namespace std;

class Segment
{
private:
	double _a, _b;
public:
	Segment(double A, double B) : _a(A), _b(B) {}

	bool operator ()(const double d) const
	{
		return ((d > _a) && (d < _b));
	}
	Segment operator*(const double d) const
	{
		return Segment(_a * d, _b * d);
	}
	Segment operator+(const double d) const
	{
		return Segment(_a + d, _b + d);
	}
	Segment operator-(const double d) const
	{
		return Segment(_a - d, _b - d);
	}
	Segment operator/(const double d) const
	{
		return Segment(_a / d, _b / d);
	}

	Segment operator+(const Segment& seg)
	{
		return Segment(min(this->_a, seg._a), max(this->_b, seg._b));
	}

	friend Segment operator * (double d, const Segment& seg)
	{
		return Segment(d*seg._a, d*seg._b);
	}
	friend Segment operator + (double d, const Segment& seg)
	{
		return Segment(d + seg._a, d + seg._b);
	}

	friend ostream & operator <<(ostream & s, const Segment & segment)
	{
		return s << "[" << segment._a << ", " << segment._b << "]";
	}
};

int main()
{
	Segment seg(2, 3), s = 1 + 2 * ((seg - 2) / 2 + seg) / 3;

	cout << s << endl << boolalpha;

	for (double x = 0.5; x < 4; x += 1)

		cout << "x=" << x << ": " << s(x) << endl;

	return 0;
}


