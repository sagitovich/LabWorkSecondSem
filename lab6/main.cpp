#include "Figure.hpp"

int main()
{
    Rectangle A(1, 5, 1, 1, 5, 5, 5, 1);
    A.setType("Прямоугольник");
    A.setColor("Красный");
    Info(A);

    Parallelogram B(4, 4, 1, 1, 7, 1, 45);
    B.setType("Параллелограмм");
    B.setColor("Оранжевый");
    Info(B);

    return 0;
}
