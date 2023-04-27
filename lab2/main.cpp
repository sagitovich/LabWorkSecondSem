#include <iostream>
#include <math.h>

class R_Complex
{
    private:
        double m_R;        // модуль
        double m_Angle;    // угол
    public:
        R_Complex(double R = 0, double Angle = 0) : m_R(R), m_Angle(Angle) {} // базовый конструктор

        R_Complex(const R_Complex& Z)   // конструктор копирования
        {
            m_R = Z.m_R;
            m_Angle = Z.m_Angle;
        }

        R_Complex& operator=(R_Complex& Z)   // присваивание копированием
        {
            std::swap(m_R, Z.m_R);
            std::swap(m_Angle, Z.m_Angle);
            return *this;
        }

        R_Complex& operator++() // префиксный
        {
            this -> m_R += 1;
            std::cout << std::endl << " - префиксный - " << std::endl;
            return *this;
        }

        R_Complex operator++(int)  // постфиксный
        {
            R_Complex temp = *this;
            this -> m_R += 1;
            std::cout << std::endl << " - постфиксный - " << std::endl;
            return temp;
        }

        R_Complex& operator+=(R_Complex& Z)
        {
            this -> m_R = sqrt(m_R*m_R + Z.m_R*Z.m_R);
            this -> m_Angle = (m_Angle + Z.m_Angle) / 2;

            return *this;
        }

        R_Complex& operator*=(R_Complex& Z)
        {
            this -> m_R = m_R * Z.m_R;
            this -> m_Angle = m_Angle + Z.m_Angle;

            return *this;
        }

        friend R_Complex operator+(R_Complex& Z1, R_Complex& Z2);
        friend R_Complex operator*(R_Complex& Z1, R_Complex& Z2);
        friend std::istream& operator>>(std::istream& in, R_Complex& Z);
        friend std::ostream& operator<<(std::ostream& out, const R_Complex& Z);

        ~R_Complex() {}
};

R_Complex operator+(R_Complex& Z1, R_Complex& Z2)
{   
    R_Complex Z3;
    Z3.m_R = sqrt(Z1.m_R*Z1.m_R + Z2.m_R*Z2.m_R); 
    Z3.m_Angle = (Z1.m_Angle + Z2.m_Angle)  / 2;
    return Z3;
}

R_Complex operator*(R_Complex& Z1, R_Complex& Z2)
{
    R_Complex Z3;
    Z3.m_R = Z1.m_R * Z2.m_R; 
    Z3.m_Angle = Z1.m_Angle + Z2.m_Angle;
    return Z3;
}

std::istream& operator>>(std::istream& in, R_Complex& Z) // ввод модуля и аргумента
{
    std::cout << "Введите модуль и аргуемнт комплексного числа: ";
    in >> Z.m_R >> Z.m_Angle;
    return in;
}

std::ostream& operator<<(std::ostream& out, const R_Complex& Z) // вывод комлексного числа
{
    out << "z = " <<  Z.m_R << "(cos" << Z.m_Angle << "° + i・sin" << Z.m_Angle << "°)" << std::endl;
    return out;
}

int main()
{
    R_Complex z1;
    std::cin >> z1;

    int i = 0;
    while (i < 10)
    {
        std::cout << ++z1 << std::endl; 
        i++;
    }

    std::cin >> z1;

    int j = 0;
    while (j < 10)
    {
        std::cout << z1++ << std::endl; 
        j++;
    }

    return 0;
}


