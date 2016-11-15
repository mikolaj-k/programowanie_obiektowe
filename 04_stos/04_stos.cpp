// 04_stos.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"

#include <cassert>           // assert
#include <stdexcept>         // out_of_range
#include <initializer_list>
#include <cstring>           // memcpy; useful in the ctor
#include <iostream>

using namespace std;

class StackArr
{
private:
	enum : size_t { SIZE = 8 };
	int arr[SIZE];
	size_t top;    // index of the first "free" location
public:
	//StackArr(initializer_list<int> lista) : arr(lista) {};
};

int main() {
	/*using std::cout; using std::endl;

	StackArr stack(1, 2, 3, 4, 5);
	stack << 6 << 7 << 8;
	cout << stack << endl;

	int a, b, c;
	stack >> c >> b >> a;
	assert(b == 7);
	assert(stack.peek() == 5);
	while (stack.avail() > 0) {
		stack.push(9);
	}
	assert(stack.full());
	assert(!stack.empty());
	while (stack.peek() > 3) {
		cout << "pop:  " << stack.pop() << endl;
	}
	cout << "Removing the rest..." << endl;
	while (stack) {
		cout << "pop:  " << stack.pop() << endl;
	}
	assert(stack.empty());*/
}


