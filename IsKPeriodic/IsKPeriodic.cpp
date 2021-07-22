// IsKPeriodic.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <limits>

bool isKPeriodic(std::string str, int k)
{
    char* kStr = new char[k]; //Массив для хранения первых k символов
    if (k <= 0)         //Проверка на неправильный ввод k
    {
        std::cout << "K must be > 0 " << std::endl;
        return false;
    }
    if (str.length() % k != 0)  //Если длинна строки не кратка k, то и сама строка не кратна k
    {
        std::cout << "String is not K periodic " << std::endl;
        return false;
    }
    if (k > str.length())   //Если k больше длинны строки, то строка не может быть ему кратна
    {
        std::cout << "String is not K periodic " << std::endl;
        return false;
    }
    for (int i = 0; i < k; i++) //Сохраняем первые k символов исходной строки
    {
        kStr[i] = str[i];
    }
    int i = k;          // Итератор. Начинаем с позиции k, т.к. первые k символов уже считали
    while (i < str.size())  //Цикл прохода по всей строке
    {
        for (int j = 0; j < k; j++) //Цикл прохода по подстроке из k символов внутри строки
        {
            if (str[i + j] != kStr[j])  //Если символ подстроки не совпадает с соответствующим ему символом сохранненной строки
            {
                std::cout << "String is not K periodic " << std::endl;  //Строка не кратна k и нет смысла в дальнейшей проверке
                return false;
            }
        }
        i += k; //Пройдя по всем символам подстроки увеличиваем итератор на k
    }
    std::cout << "String is K periodic " << std::endl;  //Если мы прошли по всей строке и не вышли из-за несоответствия, значит строка кратна k
    delete[] kStr;
    return true;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    std::cout << "Hello World!\n";
    bool exit = false;  //переменная провекри на выход
    std::string buff;   //Строка для хранения ввода
    int k;              //Переменная для хранения k
    bool check = false; //переменная для проверки на ввод k
    while (!exit)
    {
        check = false;
        std::cout << "Введите строку или q для выхода " << std::endl;
        std::cin >> buff;
        if (buff == "q")
        {
            exit = true;
            continue;
        }
        while (!check)
        {
            std::cout << "Введите k " << std::endl;
            std::cin >> k;
            if (k <= 0)
            {
                std::cout << "k должно быть больше 0 и числом" << std::endl;
            }
            else
            {
                check = true;
            }
            std::cin.clear(); // на случай, если предыдущий ввод завершился с ошибкой
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        isKPeriodic(buff, k);
    }
}

