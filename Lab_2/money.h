#pragma once

/*Створити клас Money для роботи із грошовими сумами. Число повинне бути презентовано двома полями: типу long для гривень і типу unsigned char - для копійок. Дробова частина (копійки) при виводі на екран повинна бути відділена від цілої частини коми. Реалізувати додавання, віднімання, ділення сум, ділення суми на дробове число, множення на дробове число й операції порівняння.*/

#include <string>

class Money
{
private:
    long grn;                  // Гривні
    unsigned char kop;         // Копійки

public:
    // Ініціалізація та введення/виведення
    void Init(long startGrn, unsigned char startKop);
    void Read();
    std::string toString() const;
    void Display() const;

    // Арифметичні операції
    Money Add(const Money& other) const;
    Money Subtract(const Money& other) const;
    double Divide(const Money& other) const;
    Money DivideByNumber(double number) const;
    Money MultiplyByNumber(double number) const;

    // Методи порівняння
    bool IsEqual(const Money& other) const;
    bool IsNotEqual(const Money& other) const;
    bool IsGreater(const Money& other) const;
    bool IsLess(const Money& other) const;
};