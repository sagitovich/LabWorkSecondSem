#include <iostream> 

class Stack
{
private:
    int m_MaxSize;
    int* m_Array;      // массив для хранения элементов стека 
    int m_Index;       // индекс верхнего элемента
public:
    
    Stack(int Size)
    {
        try
        {
            m_MaxSize = Size;
            m_Array = new int[m_MaxSize];
            m_Index = 0;
        }
        catch(const std::bad_alloc& ErrorMessage)
        {
            std::cout << ErrorMessage.what() << "\n";
        }
    }

    int Size()    // получение размера стека 
    {
        return m_Index;
    }

    bool Empty()   // проверка стека на пустоту 
    {
        if (m_Index > 0)     // если элементы есть
        {
            return false;       // вернуть False 
        }
        else                // если элементов нет
        {
            return true;       // вернуть True 
        }
    }

    void Push(int Element)  // добавление элемента в стек
    {
        try
        {
            if (m_Index >= m_MaxSize)   // если стек не заполнен полностью 
            {
                throw std::overflow_error("Невозможно добавить элемент. Стек заполнен.");
            }
            m_Array[m_Index] = Element;   // элемент Element записывается в стек под индексом m_Index 
            m_Index++;                    // увеличим размер стека                        
        }
        catch(const std::overflow_error& ErrorMessage)
        {
            std::cout << ErrorMessage.what() << '\n';
        }
    }

    int Pop()    // получение элемента из стека и дальнейшее его удаление 
    {
        int Element;
        try 
        {
            if (Empty() == true)     // если стек пуст
            {
                throw std::out_of_range("Невозможно извлечь элемент. Стек пуст.");
            }
            m_Index -= 1;    // уменьшим размер стека на 1
            Element = m_Array[m_Index];

            return Element;         // и вернём последний элемент
        }
        catch (const std::out_of_range& ErrorMessage)
        {
            std::cout << ErrorMessage.what() << '\n';
            return 0;
        }
    }

    int Top()     // получение элемента из стека
    {
        try 
        {
            if (Empty())     // если стек пуст
            {
                throw std::logic_error("Невозможно посмотреть элемент. Стек пуст.");
            }
            return m_Array[m_Index - 1];      // вернём последний элемент 
        }
        catch (const std::logic_error& ErrorMessage)
        {
            std::cout << ErrorMessage.what() << '\n';
            return 0;
        }
    }

    int getMaxSize()
    {
        return m_MaxSize;
    }

    void Print()  // вывод стека
    {
        if (!Empty())    // если в стеке есть элементы
        {
            while (m_Index > 0) 
            {
                m_Index -= 1;    
                std::cout << m_Array[m_Index] << " ";
            }
        }
        else 
        {
            std::cout << "Стек пуст" << "\n";
        }
        std::cout << "\n";
    }

    void Info()
    {
        double Pr = (Size() * 100) / m_MaxSize;
        std::cout << "Стек заполнен на " << Pr << " %, он хранит " << Size() << " элементов из " << m_MaxSize; 
        std::cout << ". Верхний элемент: " << Top() << "\n";
    }

    ~Stack () {}
};
