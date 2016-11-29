#include <cassert>           // assert
#include <stdexcept>         // out_of_range
#include <initializer_list>
#include <cstring>           // memcpy; useful in the ctor
#include <iostream>
#include <algorithm>

using namespace std;

class StackArr
{
private:
    enum : size_t {SIZE = 8};
    int arr[SIZE];
    size_t top;    // index of the first "free" location

public:
    StackArr() : arr() {};
    StackArr(initializer_list<int> lista)
    {
        copy(lista.begin(), lista.end(), arr);
        top = lista.size()-1;
    }

    size_t getTop()
    {
        return top++;
    }

    void push(int e)
    {
        arr[++top] = e;
    }

    int pop()
    {
        return arr[--top];
    }

    int peek()
    {
        return arr[top];
    }

    bool empty() const
    {
        return !top;
    }

    bool full()
    {
        return (top == SIZE);
    }

    size_t avail()
    {
        return (SIZE - top);
    }

    operator bool() const
    {
        return !(this -> empty());
    }

    StackArr operator << (int e)
    {
        this -> push(e);
        return *this;
    }

    int operator >> (int a)
    {
        a = this -> pop();
        return a;
    }

    friend ostream & operator <<(ostream & s, const StackArr & lista)
    {
        s << "[ ";

        for(int i = 0; i < lista.top+1; i++)
        {
            s << lista.arr[i] << " ";
        }
        s << "]";

        return s;
    }
};

int main()
{
    StackArr stack({1,2,3,4,5});
    cout << stack << endl;

    stack << 6 << 7;

    cout << stack << endl;
//
//    int a, b, c;
//    stack >> c >> b >> a;
//    assert(b == 7);
//    assert(stack.peek() == 5);
//    while (stack.avail() > 0)
//    {
//        stack.push(9);
//    }
//    assert(stack.full());
//    assert(!stack.empty());
//    while(stack.peek() > 3)
//    {
//        cout << "pop:  " << stack.pop() << endl;
//    }
//    cout << "Removing the rest..." << endl;
//    while (stack)
//    {
//        cout << "pop:  " << stack.pop() << endl;
//    }
//    assert(stack.empty());
}
