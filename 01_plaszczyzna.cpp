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
	if ((r1->UR.x < r2->LL.x) && (r1->UR.y < r2->LL.y))
		return true;

	if ((r1->UR.x > r2->LL.x) && (r1->UR.y > r2->LL.y))
		return true;

	if ((r2->UR.x < r1->LL.x) && (r2->UR.y < r1->LL.y))
		return true;

	return false;
};

Rect intersection(const Rect& r1, const Rect& r2)
{
	if (doIntersect(&r1, &r2))
		//TODO
		return r1;

	else
		throw "Error in 'intersection'";
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

	system("pause");

	return 0;
}

