#include <iostream>
#include "testStack.hpp"
using namespace std;

int main()
{
    StackList<int> SL;
    SL.Print("SL");

    SL.Push(8);
    SL.Push(5);
    SL.Push(10);
    SL.Push(7);
    SL.Print("SL");

  // проверка конструктора копирования
    StackList<int> SL2 = SL;
    SL2.Print("SL2");

    SL.Empty();
    SL.Print("SL");

    SL = SL2;
    SL.Print("SL = SL2");

    StackList<int> SL3;
    SL3.Push(1);
    SL3.Push(2);
    SL3.Push(3);
    SL3.Print("SL3");

    SL = SL2 = SL3;
    SL.Print("SL");
    SL2.Print("SL2");

    int d = SL2.Pop();

    cout << "d = " << d << endl;
    SL2.Print("SL2-1");

    d = SL2.Pop();
    SL2.Print("SL2-2");

    d = SL2.Pop();
    SL2.Print("SL2-3");

    d = SL2.Pop();
    cout << "d = " << d << endl;
    SL2.Print("SL2----");
}