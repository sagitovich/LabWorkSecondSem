#include "Figure.hpp"

int main()
{
    Rectangle A(1, 5, 1, 1, 5, 5, 5, 1);
    A.setColor("Красный");
    Inf(A);

    Parallelogram B(4, 4, 1, 1, 7, 1);
    B.setColor("Жёлтый");
    Inf(B);

    return 0;
}
