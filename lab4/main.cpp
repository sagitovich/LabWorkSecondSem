#include <iostream>

template <typename T>
class myVectorBool
{
    private:
        T *m_N; 
        int m_size;
    public:
        myVectorBool()  // basic constructor
        {
            m_N = nullptr;
            m_size = 0;
        }

        myVectorBool(int N)   // перевод в двоичную и получение длины цепочки
        {
            int temp = 0;   // временная переменная
            int k = 1;
            while (N)
            {
                temp += (N % 2) * k;
                k *= 10;
                N /= 2;
            }
            int temp_ = temp;   // резервная копия 

            m_size = 0;
            while (temp > 0)
            {
                temp /= 10;
                m_size++;       //получение длины цепочки
            }

            m_N = new T[m_size];
            for (int i = m_size-1; i >= 0; i--)    // заполнение массива m_N
            {
                m_N[i] = temp_ % 10;
                temp_ /= 10;
            }
        }

        void setN()
        {
            m_N = new T[m_size];
        }

        myVectorBool& operator=(const myVectorBool& Vector)
        {
            m_N = new T[Vector.m_size];
            for (int i = 0; i < Vector.m_size; i++)
            {
                m_N[i] = Vector.m_N[i];
            }
            m_size = Vector.m_size;

            return *this;
        }

        void add_begin(bool k)
        {      
            T *tempArray = new T[m_size];       // копия массива m_N
            for (int i = 0; i < m_size; i++)
            {
                tempArray[i] = m_N[i];
            }

            m_N = (bool*)realloc(m_N, sizeof(bool));  // увеличиваем размер m_N
            m_size += 1;

            m_N[0] = k;                               // заполняем первый элемент
            for (int i = 1; i < m_size + 1; i++)      
            {
                m_N[i] = tempArray[i-1];
            }
            delete[] tempArray;
        }

        void add_end(bool k)
        {
            T *tempArray = new T[m_size];             // копия массива m_N
            for (int i = 0; i < m_size; i++)
            {
                tempArray[i] = m_N[i];
            }
       
            m_N = (bool*)realloc(m_N, 2 * sizeof(bool));  // увеличиваем размер m_N
            m_size += 1;
            
            for (int i = 0; i < m_size; i++)      
            {
                m_N[i] = tempArray[i];
            }
            m_N[m_size] = k;

            delete[] tempArray; 
        }

        int size()
        {
            return m_size;
        }

        void erase(int j)
        {
            if ((0 < j) && (j < m_size + 1))
            {
                for (int i = j-1; i < m_size; i++)
                {
                    m_N[i] = m_N[i + 1];
                }

                m_size = m_size - 1;
                T *tempArray = new T[m_size];
                for (int i = 0; i < m_size; i++)
                {
                    tempArray[i] = m_N[i];
                }

                for (int i = 0; i < m_size; i++)
                {
                    m_N[i] = tempArray[i];
                }
                delete[] tempArray;
            }
            else
            {
                std::cout << "Ошибка!" << std::endl;
            }

        }

        T operator[](int index)
        {
            if ((0 < index) && (index <= m_size))
            {
                std::cout << "Элемент цепочки под номером " << index << ": " << m_N[index-1] << std::endl;
            }
            else
            {
                std::cout << "Неверный индекс цепочки" << std::endl;
            }
            return m_N[index-1];
        }

        T operator()(int index)
        {
            if ((0 < index) && (index <= m_size))
            {
                std::cout << "Элемент цепочки под номером " << index << ": " << m_N[index-1] << std::endl;
                std::cout << "Заменён на противоположный элемент." << std::endl;
                m_N[index-1] = !m_N[index-1];
            }
            else
            {
                std::cout << "Неверный индекс цепочки" << std::endl;
            }
            return m_N[index-1];
        }

        void HelloWorld(int size)
        {
            std::cout << std::endl;
            for (int i = 0; i < size; i++)
            {
                std::cout << "Hello, world!" << std::endl;
            }
            std::cout << std::endl;
        }

        void Print(const char *name)
        {
            std::cout << name;
            for (int i = 0; i < m_size; i++)
            {
                std::cout << m_N[i];
            }
            std::cout << std::endl;
        }

        friend myVectorBool operator+(myVectorBool &a, myVectorBool &b)
        {
            int cntA = 0; int cntB = 0;
            if (a.size() != b.size())
            {
                while (a.size() != b.size())    // приводим массивы слагаемых к одной длине
                {
                    if (a.size() > b.size())
                    {
                        int temp = a.size() - b.size();     // разница длин слагаемых массивов
                        for (int i = 0; i < temp; i++)
                        {
                            b.add_begin(0);
                            cntB += 1;
                        }
                    }
                    if (a.size() < b.size())
                    {
                        int temp = b.size() - a.size();     // разница длин слагаемых массивов
                        for (int i = 0; i < temp; i++)
                        {
                            a.add_begin(0);
                            cntA += 1;
                        }
                    }
                }
            }
            int sizeAB = a.size();
            int sizeC = sizeAB + 1;

            myVectorBool <bool> c;      //   11011
            c.m_size = sizeC;           //   00110
            c.setN();                   //  100001 

            for (int i = sizeC - 1; i > 0; i--)
            {
                if (c.m_N[i] == 0)
                {
                    if ((a.m_N[i-1] == 1) && (b.m_N[i-1] == 1))
                    {
                        c.m_N[i-1] = 1;
                    }

                    if ((a.m_N[i-1] == 1) && (b.m_N[i-1] == 0))
                    {
                        c.m_N[i] = 1;
                    }

                    if ((a.m_N[i-1] == 0) && (b.m_N[i-1] == 1))
                    {
                        c.m_N[i] = 1;
                    }
                }

                else if (c.m_N[i] == 1)
                {
                    if ((a.m_N[i-1] == 1) && (b.m_N[i-1] == 1))
                    {
                        c.m_N[i-1] = 1;
                    }

                    if ((a.m_N[i-1] == 1) && (b.m_N[i-1] == 0))
                    {
                        c.m_N[i] = 0;
                        c.m_N[i-1] = 1;
                    }

                    if ((a.m_N[i-1] == 0) && (b.m_N[i-1] == 1))
                    {
                        c.m_N[i] = 0;
                        c.m_N[i-1] = 1;
                    }
                }       
            }
            for (int i = 0; i < cntA; i++)
            {
                a.erase(1);
            }
            for (int i = 0; i < cntB; i++)
            {
                b.erase(1);
            }
            while (c.m_N[0] != 1)  // убрать лишний ноль в начале
            {
                c.erase(1);
            }
            return c;
        }
        
        ~myVectorBool() 
        {
            delete[] m_N;
        }
};

int main()
{
    myVectorBool <bool> A(11); // 11
    myVectorBool <bool> B(3);  // 3
    myVectorBool <bool> C;
    myVectorBool <bool> D;

    A.Print("Вектор А: ");
    B.Print("Вектор Б: ");
    
    A.add_begin(0);
    A.Print("Вектор А`: ");

    B.add_end(0);
    B.add_begin(0);
    B.Print("Вектор Б`: ");
    int size = B.size();

    C = A + B;
    C.Print("Вектор C: ");

    D = B + B;
    D.Print("Вектор D: ");

    int index;
    std::cout << "Введите index: ";
    std::cin >> index;

    C[index];
    C(index);
    C.Print("Вектор C`: ");

    C.erase(index);
    C.Print("Вектор C``: ");

    B.HelloWorld(size);
     A.Print("Вектор А: ");
      B.Print("Вектор B: ");

    return 0;
}