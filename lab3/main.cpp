#include <iostream>

template <typename T>
class Matrix
{
private:
    T** m_M;    // матрица
    int m_s;    // строки
    int m_n;    // столбцы
public:
    Matrix()  {}  // base

    Matrix(int s, int n) : m_s(s), m_n(n)   // инициализация переменных
    {
        m_M = (T**) new T*[m_s];  // память для строк 

        for (int i = 0; i < m_s; i++)
        {
            m_M[i] = (T*) new T[m_n];         // память для элементов
        }

        for (int i = 0; i < m_s; i++)         // заполнение массива нулями
        {
            for (int j = 0; j < m_n; j++)
            {
                m_M[i][j] = 0;
            }
        }
    }

    Matrix (const Matrix& M)    // конструктор копирования
    {
        m_s = M.m_s;    m_n = M.m_n;

        m_M = (T**) new T*[m_s];  // выделения памяти для матрицы

        for (int i = 0; i < m_s; i++)
        {
            m_M[i] = (T*) new T[m_n];         // память для элементов
        }

        for (int i = 0; i < m_s; i++)       // заполнение массива нулями
        {
            for (int j = 0; j < m_n; j++)
            {
                m_M[i][j] = M.m_M[i][j];
            }
        }
    }

    Matrix operator=(const Matrix& M)   // оператор присваивания
    {
        if (m_n > 0)
        {
            for (int i = 0; i < m_s; i++)
            {
                delete[] m_M[i];
            }
        }

        if (m_s > 0)
        {
            delete[] m_M;
        }

        m_s = M.m_s;
        m_n = M.m_n;

        m_M = (T**) new T*[m_s];    // выделение памяти для матрицы
        for (int i = 0; i < m_s; i++)
        {
            m_M[i] = (T*) new T[m_n];
        }

        for (int i = 0; i < m_s; i++)   // заполнение значениями
        {
            for (int j = 0; j < m_n; j++)
            {
                m_M[i][j] = M.m_M[i][j];
            }
        }
        return *this;
    }

    void Fill()
    {
        std::cout << "Введите элементы матрицы:" << std::endl;
        for (int i = 0; i < m_s; i++)
        {
            for (int j = 0; j < m_n; j++)
            {
                std::cin >> m_M[i][j];
            }
        }
        std::cout << std::endl;
    }

    void Print(const char* name)    // вывод матрицы
    {
        std::cout<< name << std::endl;
        for (int i = 0; i < m_s; i++)
        {
            for (int j = 0; j < m_n; j++) 
            {    
                std::cout << m_M[i][j] << "\t";
            }
            std::cout << std::endl;
        }
            std::cout << "_____________________" << std::endl << std::endl;
    }

    Matrix operator++(int)
    {
        for (int i = 0; i < m_s; i++)
        {
            for (int j = m_n - 1; j < m_n; j++) 
            {    
                this -> m_M[i][j] += 1;
            }
        }
        return *this; //temp;
    }

    T GetMeObject(int i, int j)         // получение переменных строк и столбцов
    {
        if ((m_s > 0) && (m_n > 0))
        {
            std::cout << m_M[i][j] << std::endl;
            return m_M[i][j];
        }
        else
            return 0;
    }

    void EditElement(int i, int j, T edit)  // изменение элемента матрицы
    {
        if ((i < 0) || (i >= m_s))
            return;
        if ((j < 0) || (j >= m_n))
            return;
        m_M[i][j] = edit;
    }

    friend Matrix<T> operator+(Matrix<T> &m1, Matrix<T> &m2)
    {
        int s = m1.m_s; int n = m1.m_n;
        Matrix<T> m3(s, n);

        if ((m1.m_s = m2.m_s) && (m1.m_n = m2.m_n))
        {
            for (int i = 0; i < s; i++)
            {
                for (int j = 0; j < n; j++)
                {
                   m3.m_M[i][j] = (m1.m_M[i][j] + m2.m_M[i][j]);
                }
            }
        }
        
        return m3;
    }

    friend Matrix<T> operator-(Matrix<T> &m1, Matrix<T> &m2)
    {
        int s = m1.m_s; int n = m1.m_n;
        Matrix<T> m3(s, n);

        if ((m1.m_s = m2.m_s) && (m1.m_n = m2.m_n))
        {
            for (int i = 0; i < s; i++)
            {
                for (int j = 0; j < n; j++)
                {
                   m3.m_M[i][j] = (m1.m_M[i][j] - m2.m_M[i][j]);
                }
            }
        }
        
        return m3;
    }

    Matrix operator+=(Matrix &M)
    {
        for (int i = 0; i < M.m_s; i++)
        {
            for (int j = 0; j < M.m_n; j++)
            {
                this -> m_M[i][j] += M.m_M[i][j];
            }
        }
        return *this;
    }

    friend Matrix<T> operator*(Matrix<T> &m1, Matrix<T> &m2)
    { 
        // количество строк новой матрицы равно количеству строк первой
        // количество столбцов новой матрицы равно количеству столбцов второй
        Matrix m3(m1.m_s, m2.m_n);
        Matrix m(1, 1);
        bool flag = false;
        
        if (m1.m_n == m2.m_s)
        {// количество столбцов первой матрицы равно количеству строк второй
            for (int i = 0; i < m1.m_s; i++)
            {
                for (int j = 0; j < m2.m_n; j++)
                {
                    //m3.m_M[i][j] = 0;
                    for (int k = 0; k < m1.m_n; k++)
                    {
                        m3.m_M[i][j] += (m1.m_M[i][k] * m2.m_M[k][j]);
                    }
                }
            }
            return m3;
        }
        else
        {
            std::cout << "Ошибка" << std::endl;
            m.m_M[0][0] = flag;
            return m;
        }
        
    }

    Matrix operator*=(Matrix &M)
    {
        if (m_n == M.m_s)
        {
            Matrix<T> temp(m_n, M.m_s);
            for (int i = 0; i < M.m_s; i++)
            {
                for (int j = 0; j < m_n; j++)
                {
                    temp.m_M[i][j] = 0;
                }
            }

            for (int i = 0; i < m_s; i++)
            {
                for (int j = 0; j < M.m_n; j++)
                {
                    for (int k = 0; k < m_n; k++)
                    {
                        temp.m_M[i][j] += (m_M[i][k] * M.m_M[k][j]);
                        
                        //temp.m_M[i][j] = m_M[i][j]; 
                    }
                }
            }

            for (int i = 0; i < this -> m_s; i++)
            {
                for (int j = 0; j < this -> m_n; j++)
                {
                    this -> m_M[i][j] = temp.m_M[i][j];
                }
            }
            return *this;
        }
        else
        {
            Matrix m(1, 1);
            bool flag = false;
            std::cout << "Ошибка" << std::endl;         
            m_M[0][0] = flag;

            return m;
        }
    }

    T determinant(Matrix& M)   // определитель
    {
        double Z, z1, z2, z3;
        z1 = M.m_M[0][0] * (M.m_M[1][1] * M.m_M[2][2] - M.m_M[1][2] * M.m_M[2][1]);
        z2 = -1 * (M.m_M[0][1] * (M.m_M[1][0] * M.m_M[2][2] - M.m_M[1][2] * M.m_M[2][0]));
        z3 = M.m_M[0][2] * (M.m_M[1][0] * M.m_M[2][1] - M.m_M[1][1] * M.m_M[2][0]);
        Z = z1 + z2 + z3;

        std::cout << "Определитель матрицы B = " << Z << std::endl << std::endl; 
        return Z;  
    }

    ~Matrix ()  // деструктор
    {
        if (m_n > 0)
        {
        // освободить выделенную память для каждой строки
        for (int i = 0; i < m_s; i++)
            delete[] m_M[i];
        }

        if (m_s > 0)
        delete[] m_M;
    }
};

int main()
{
    Matrix <int> A(3, 3);
    A.Fill();

    Matrix <int> B(3, 3);
    B.Fill();

    Matrix <int> C(2, 3);
    C.Fill();

    Matrix <int> D(3, 3);
    D = A + B;
    D.Print("Матрица D = A + B");

    D = D - B;
    D.Print("Матрица D = D - B");

    D += B;
    D.Print("Матрица D += B");

    B.Print("Матрица В");
    D *= B;
    D.Print("Матрица D *= B");

    Matrix <int> E(1, 1);
    E = A * C;  // false
    E.Print("Матрица E = A * C");

    Matrix <int> F(2, 3);   // количество строк новой матрицы равно количеству строк первой
    F = C * B;              // количество столбцов новой матрицы равно количеству столбцов второй
    F.Print("Матрица F = C * B");

    int Z = B.determinant(B);

    A.Print("Матрица А");
    A++;
    A.Print("Матрица А`");

    int i, j;
    std::cout << "Введите элемент матрицы А, котрый хотите увидеть: " << std::endl;
    std::cin >> i >> j;
    A.GetMeObject(i, j);

    std::cout << "Введите элемент матрицы А, котрый хотите изменить: " << std::endl;
    int k, l;
    std::cin >> k >> l;
    A.EditElement(k, l, Z);
    A.Print("Матрица A`");

    return 0;
}

// https://www.bestprog.net/ru/2019/08/23/c-an-example-of-creating-a-template-class-matrix-dynamic-memory-allocation-ru/

// https://stackoverflow.com/questions/15578935/proper-way-of-casting-pointer-types
