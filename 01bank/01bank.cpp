// 01bank.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>

using namespace std;

enum Banks
{
	PKO,
	BGZ,
	BRE,
	BPH
};

struct Account
{
	Banks bank;
	int balance;
};

struct Person
{
	char name[20];
	Account account;
};

struct Couple
{
	Person he;
	Person she;
};

const Couple* bestClient(const Couple* couples, int size, Banks bank)
{

	return nullptr;
};



int main()
{
	Couple couples[] =
	{
		"Johny", PKO, 1100, "Mary", BGZ, 1500,
		"Peter", BGZ, 1400, "Suzy", BRE, 1300,
		"Kevin", PKO, 1600, "Katy", BPH, 1500,
		"Kenny", BPH, 1800, "Lucy", BRE, 1700
	};

	const Couple* p = bestClient(couples, 4, BGZ);
	if (p != nullptr)
		cout << p->he.name << " i " << p->she.name
		<< ": " << p->he.account.balance +
		p->she.account.balance << endl;
	else cout << "Nothing found" << endl;

	return 0;
}


