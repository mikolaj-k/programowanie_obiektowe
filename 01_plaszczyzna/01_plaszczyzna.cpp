// 01_plaszczyzna.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>

using namespace std;

struct Point
{
	int x, y;
};

struct Rect
{
	Point LL, UR;
};

void printPoint(const Point p)
{
	printf("(%i, %i)", p.x, p.y);
};

void printRect(const Rect& r)
{
	cout << "[";
	printPoint(r.LL);
	cout << ", ";
	printPoint(r.UR);
	cout << "]" << endl;
};

bool doIntersect(const Rect* r1, const Rect* r2)
{
	//TODO
	return true;
};

Rect intersection(const Rect& r1, const Rect& r2)
{
	//TODO
	return r1;
};

int main()
{

	Rect ra{ { -1,-2 },{ 1, 1 } };
	Rect rb{ { 0, 0 },{ 5, 1 } };
	Rect rc{ { 2,-1 },{ 4, 2 } };
	Rect rd{ { 1,-3 },{ 4, 3 } };

	printRect(ra);
	printRect(rb);
	printRect(rc);
	printRect(rd);

	cout << std::boolalpha << "Do intersect:\n";
	cout << "ra rb ? " << doIntersect(&ra, &rb) << '\n';
	cout << "ra rc ? " << doIntersect(&ra, &rc) << '\n';
	cout << "rb rd ? " << doIntersect(&rb, &rd) << '\n';

	cout << "Intersections:\n";
	cout << "ra & rb: ";
	printRect(intersection(ra, rb));
	cout << "rb & rc: ";
	printRect(intersection(rb, rc));
	cout << "rc & rd: ";
	printRect(intersection(rc, rd));
	cout << "ra & rd: ";
	printRect(intersection(ra, rd));

	return 0;
}

