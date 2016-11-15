// 01_bank.cpp : Defines the entry point for the console application.
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

int sumBalance(Couple couple)
{
	return couple.he.account.balance + couple.she.account.balance;
};


const Couple* bestClient(Couple* couples, int size, Banks bank)
{
	int biggestBalance = 0;

	Couple* bestClients = nullptr;

	for (int i = 0; i < size; i++)
	{
		if ((couples[i].he.account.bank == bank) || (couples[i].she.account.bank == bank))
		{
			if (biggestBalance == 0)
			{
				biggestBalance = sumBalance(couples[i]);
			}
			if (biggestBalance < sumBalance(couples[i]))
			{
				biggestBalance = sumBalance(couples[i]);

				bestClients = &couples[i];
			}
		}
	}

	return bestClients;
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
		cout << p->he.name << " i " << p->she.name << ": " << p->he.account.balance + p->she.account.balance << endl;

	else
		cout << "Nothing found" << endl;

	return 0;
}




