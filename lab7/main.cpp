#include <iostream>
#include "Stack.hpp"

int main()
{
    srand(time(0));
    Stack stk(10);

    int n = 1 + rand() % 8;     // генерация случайного кол-ва чисел 
    for (int i = 0; i < n; i++) 
    {
        stk.Push(1 + rand() % 100);   // заполнение стека случайными числами
        std::cout << stk.Top() << "\n";
    }
    stk.Info();

    for (int i = n; i < stk.getMaxSize(); i++)
    {
        stk.Push(0);                  // заполнение стека до конца нулями
    }
    stk.Info();

    stk.Push(1 + rand() % 100);     // исключение добавления
    
    stk.Print();                    // выгружаем все элементы

    stk.Pop();                      // исключение извлечения
    stk.Push(120);
    std::cout << stk.Top() << "\n";

    Stack stk1(-5);                 // исключение выделения памяти
    
    return 0;
}
