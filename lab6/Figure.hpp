#include <iostream>
#include <cmath>

class Figure
{
private:
    std::string m_Color;
    std::string m_Type;
public:
    void setColor(std::string Color)
    {
        m_Color = Color;
    }
    std::string GetColor() const
    {
        return m_Color;
    }
    void setType(std::string Type)
    {
        m_Type = Type;
    }
    std::string GetType() const
    {
        return m_Type;
    }
};

class Rectangle: public Figure
{
private:
    double m_Area;
    double m_Point[8];
public:
    Rectangle(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4)
    {
        if (sqrt(pow(x2-x1, 2) + pow(y2-y1, 2)) == sqrt(pow(x4-x3, 2) + pow(y4-y3, 2)))
        {
            m_Area = sqrt(pow(x2-x1, 2) + pow(y2-y1, 2)) * sqrt(pow(x3-x2, 2) + pow(y3-y2, 2));
        }

        else if(sqrt(pow(x2-x1, 2) + pow(y2-y1, 2)) != sqrt(pow(x4-x3, 2) + pow(y4-y3, 2)))
        {
            m_Area = sqrt(pow(x2-x1, 2) + pow(y2-y1, 2)) * sqrt(pow(x4-x3, 2) + pow(y4-y3, 2));
        }

        m_Point[0] = x1;    m_Point[2] = x2;    m_Point[4] = x3;    m_Point[6] = x4;
        m_Point[1] = y1;    m_Point[3] = y2;    m_Point[5] = y3;    m_Point[7] = y4;
    }

    const double& GetArea() const
    {
        return m_Area;
    }

    void GetPoint() const 
    {
        std::cout << "A(" << m_Point[0] << ";" << m_Point[1] << ") ";
        std::cout << "B(" << m_Point[2] << ";" << m_Point[3] << ") ";
        std::cout << "C(" << m_Point[4] << ";" << m_Point[5] << ") ";
        std::cout << "D(" << m_Point[6] << ";" << m_Point[7] << ") " << "\n";
    }

    ~Rectangle() {}
};  

class Parallelogram: public Figure
{
private:
    double m_Area;
    double m_Point[6];
public:
    Parallelogram(double x1, double y1, double x2, double y2, double x3, double y3, double angle)
    {
        m_Area = sqrt(pow(x2-x1, 2) + pow(y2-y1, 2)) * sqrt(pow(x3-x2, 2) + pow(y3-y2, 2)) * sin(angle);

        m_Point[0] = x1;    m_Point[2] = x2;    m_Point[4] = x3;
        m_Point[1] = y1;    m_Point[3] = y2;    m_Point[5] = y3;
    }

    const double& GetArea() const
    {
        return m_Area;
    }

    void GetPoint() const
    {
        std::cout << "A(" << m_Point[0] << ";" << m_Point[1] << ") ";
        std::cout << "B(" << m_Point[2] << ";" << m_Point[3] << ") ";
        std::cout << "C(" << m_Point[4] << ";" << m_Point[5] << ") " << "\n";
    }

    ~Parallelogram() {}
};

template <typename T>
static void Info(const T& type)
{
    std::cout << "\n" << "Тип: " << type.GetType() << "\n";
    std::cout << "Цвет: " << type.GetColor() << "\n";
    std::cout << "Площадь: " << type.GetArea() << "\n";
    std::cout << "Вершины: "; type.GetPoint(); std::cout << "\n";
}
