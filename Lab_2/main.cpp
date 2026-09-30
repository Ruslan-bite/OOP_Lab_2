#include <iostream>
#include <windows.h>
#include "money.h"
using namespace std;

int main()
{
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    Money a, b; // Створення двох об'єктів

    // Введення даних користувачем
    cout << "   Введення першої суми:" << endl;
    a.Read();

    cout << "\n   Введення другої суми:" << endl;
    b.Read();

    // Виведення введених сум на екран
    cout << "\nПерша сума: ";
    a.Display();

    cout << "Друга сума: ";
    b.Display();

    // Арифметичні операції
    cout << "\nРезультат додавання:" << endl;
    Money sum = a.Add(b);
    sum.Display();

    cout << "\nРезультат віднімання:" << endl;
    Money difference = a.Subtract(b);
    difference.Display();

    // Ділення однієї суми на іншу
    cout << "\nРезультат ділення сум:" << endl << a.Divide(b) << endl;

    // Множення та ділення на дробове число
    cout << "\nРезультат ділення першої суми на 2.5:" << endl;
    a.DivideByNumber(2.5).Display();

    cout << "\nРезультат множення першої суми на 2.5:" << endl;
    a.MultiplyByNumber(2.5).Display();

    // Перевірка операцій порівняння
    cout << "\n   Порівняння" << endl;
    if (a.IsEqual(b)) cout << "Суми рівні" << endl;
    if (a.IsNotEqual(b)) cout << "Суми не рівні" << endl;
    if (a.IsGreater(b)) cout << "Перша сума більша" << endl;
    if (a.IsLess(b)) cout << "Перша сума менша" << endl;

    return 0;
}