#include <iostream>
#include "class.hpp"

int main()
{
    std::string text; // строка
    std::cout << "Введите строку: " << std::endl;
    std::getline(std::cin, text);

    double ShowTime;   // время вывода всей строки
    std::cout << "Введите время вывода текста: ";
    std::cin >> ShowTime;
    if (ShowTime <= 0)
    {
        std::cout << "Error time!" << std::endl;
        return 0;
    }

    MyText Ani(text, ShowTime);
    Ani.AnimationText();

    return 0;
}
