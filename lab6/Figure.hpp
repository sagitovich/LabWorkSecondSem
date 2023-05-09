#include <iostream>
#include <cmath>

template <typename T>
static void Inf(const T& type)
{
    type.Info();
}

class Figure
{
protected:
    std::string m_Color;
public:
    void setColor(std::string Color)
    {
        m_Color = Color;
    }
    std::string GetColor() const
    {
        return m_Color;
    }
    virtual void Info() const {}
};

class Rectangle: public Figure
{
private:
    double A[2];
    double B[2];
    double C[2];
    double D[2];
public:
    Rectangle(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4)
    {
        A[0] = x1;    B[0] = x2;    C[0] = x3;    D[0] = x4; 
        A[1] = y1;    B[1] = y2;    C[1] = y3;    D[1] = y4;
    }

    double GetArea() const
    {
        double Area;
        Area = sqrt(pow(A[0]-B[0], 2) + pow(A[1]-B[1], 2)) * sqrt(pow(A[0]-D[0], 2) + pow(A[1]-D[1], 2));   // AB * AD = Area
        return Area;
    }

    void Info() const 
    {
        std::cout << "Тип: Прямоугольник" << "\n";
        std::cout << "Цвет: " << GetColor() << "\n";
        std::cout << "Вершины: ";
        std::cout << "A(" << A[0] << ";" << A[1] << ") ";
        std::cout << "B(" << B[0] << ";" << B[1] << ") ";
        std::cout << "C(" << C[0] << ";" << C[1] << ") ";
        std::cout << "D(" << D[0] << ";" << D[1] << ") " << "\n";
        std::cout << "Площадь: " << GetArea() << "\n" << "\n";
    }

    ~Rectangle() {}
};  

class Parallelogram: public Figure
{
private:
    double A[2];
    double B[2];
    double C[2];
public:
    Parallelogram(double x1, double y1, double x2, double y2, double x3, double y3)
    {
        A[0] = x1;    B[0] = x2;    C[0] = x3;   
        A[1] = y1;    B[1] = y2;    C[1] = y3;
    }

    double GetArea() const
    {
        double Area;    // AB * BC * sin(ABC) = Area
        double cosAngle;

        Area = sqrt(pow(A[0]-B[0], 2) + pow(A[1]-B[1], 2)) * sqrt(pow(B[0]-C[0], 2) + pow(B[1]-C[1], 2));      // AB * BC

        cosAngle = ((B[0]-A[0])*(C[0]-B[0]) + (B[1]-A[1])*(C[1]-B[1])) / 
            (sqrt(pow(B[0]-A[0], 2) + pow(B[1]-A[1], 2)) * sqrt(pow(C[0]-B[0], 2) + pow(C[1]-B[1], 2)));

        Area *= sqrt(1 - pow(cosAngle, 2));     // AB * BC * sin(ABC)

        return Area;
    }

    void Info() const 
    {
        std::cout << "Тип: Прямоугольник" << "\n";
        std::cout << "Цвет: " << GetColor() << "\n";
        std::cout << "Вершины: ";
        std::cout << "A(" << A[0] << ";" << A[1] << ") ";
        std::cout << "B(" << B[0] << ";" << B[1] << ") ";
        std::cout << "С(" << C[0] << ";" << C[1] << ") " << "\n";
        std::cout << "Площадь: " << GetArea() << "\n" << "\n";
    }

    ~Parallelogram() {}
};

