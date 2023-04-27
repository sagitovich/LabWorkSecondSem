#include <iostream>
#include "Logger.hpp"

int main()
{
    bool flagDebug, flagInfo, flagError, flagCompletion;
    std::cout << "Активируйте логгеры:" << "\n";
    std::cout << "Debug = ";        std::cin >> flagDebug;
    std::cout << "Info = ";         std::cin >> flagInfo;
    std::cout << "Error = ";        std::cin >> flagError;
    std::cout << "Completion = ";   std::cin >> flagCompletion;

    Logger::GoFile();
    Debug(flagDebug);

    double a[5];
    int cnt = 0;
    int sum = 0;
    Info(flagInfo);
    std::cout << "Введите пять чисел" << std::endl;
    
    while (cnt < 5)
    {
        for (int i = 0; i < 5; i++)
        {
            std::cin >> a[i];
            if (a[i] == (int)a[i])
            {
                sum += a[i];
                cnt++;
            }
            else
            {
                cnt = 0;
                sum = 0;
                Error(flagError);
            }
        }
    }

    Info(flagInfo);
    std::cout << "Отсортированная последовательность: ";
    if (sum >= 100)
    {
        for (int i = 0; i < 5; i++)
        {
            for (int j = i+1; j < 5; j++)
            {
                if (a[i] > a[j])
                {
                    std::swap(a[i], a[j]);
                }
            }
            std::cout << a[i] << " ";

        }

    }

    if (sum < 100)
    {
        for (int i = 0; i < 5; i++)
        {
            for (int j = i+1; j < 5; j++)
            {
                if (a[i] > a[j])
                {
                    std::swap(a[i], a[j]);
                }
            }
        } 
        for (int i = 4; i >= 0; i--)
        {
            std::cout << a[i] << " ";
        }
    }

    std::cout << "\n";
    Info(flagInfo);
    std::cout << "Сумма: " << sum << "\n";

    Completion(flagCompletion);
    return 0;
}
