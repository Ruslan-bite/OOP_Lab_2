#include "money.h"
#include <iostream>
#include <sstream>
#include <iomanip>
#include <cmath>
#include <cstdlib>
using namespace std;

// Ініціалізація полів
void Money::Init(long startGrn, unsigned char startKop)
{
    grn = startGrn;
    kop = startKop;
}

// Введення з клавіатури
void Money::Read()
{
    long tempGrn;
    int tempKop;

    cout << "Введіть гривні: ";
    cin >> tempGrn;

    cout << "Введіть копійки: ";
    cin >> tempKop;

    grn = tempGrn;
    kop = (unsigned char)(abs(tempKop) % 100);
}

// Перетворення в рядок
string Money::toString() const
{
    stringstream ss;

    if (grn < 0) {
        ss << "-" << -grn << "," << setw(2) << setfill('0') << (int)kop << " грн";
    }
    else {
        ss << grn << "," << setw(2) << setfill('0') << (int)kop << " грн";
    }

    return ss.str();
}

// Виведення на екран
void Money::Display() const
{
    cout << toString() << endl;
}

// Додавання сум (точний підрахунок через загальні копійки)
Money Money::Add(const Money& other) const
{
    Money result;

    long k1 = grn * 100 + (grn >= 0 ? kop : -kop);
    long k2 = other.grn * 100 + (other.grn >= 0 ? other.kop : -other.kop);
    long sumKop = k1 + k2;

    long resGrn = sumKop / 100;
    int resKop = sumKop % 100;

    if (resKop < 0) {
        resKop = -resKop;
    }

    result.Init(resGrn, (unsigned char)resKop);
    return result;
}

// Віднімання сум
Money Money::Subtract(const Money& other) const
{
    Money result;

    long k1 = grn * 100 + (grn >= 0 ? kop : -kop);
    long k2 = other.grn * 100 + (other.grn >= 0 ? other.kop : -other.kop);
    long diffKop = k1 - k2;

    long resGrn = diffKop / 100;
    int resKop = diffKop % 100;

    if (resKop < 0) {
        resKop = -resKop;
    }

    result.Init(resGrn, (unsigned char)resKop);
    return result;
}

// Ділення суми на суму
double Money::Divide(const Money& other) const
{
    double first = grn + (grn >= 0 ? (double)kop / 100.0 : -(double)kop / 100.0);
    double second = other.grn + (other.grn >= 0 ? (double)other.kop / 100.0 : -(double)other.kop / 100.0);

    if (second == 0.0) return 0.0;

    return first / second;
}

// Ділення суми на число
Money Money::DivideByNumber(double number) const
{
    Money result;
    if (number == 0.0) {
        result.Init(0, 0);
        return result;
    }

    double current = grn + (grn >= 0 ? (double)kop / 100.0 : -(double)kop / 100.0);
    double value = current / number;

    long totalKop = (long)(value * 100.0 + (value >= 0 ? 0.5 : -0.5));
    long resGrn = totalKop / 100;
    int resKop = totalKop % 100;

    if (resKop < 0) resKop = -resKop;

    result.Init(resGrn, (unsigned char)resKop);
    return result;
}

// Множення суми на число
Money Money::MultiplyByNumber(double number) const
{
    Money result;

    double current = grn + (grn >= 0 ? (double)kop / 100.0 : -(double)kop / 100.0);
    double value = current * number;

    long totalKop = (long)(value * 100.0 + (value >= 0 ? 0.5 : -0.5));
    long resGrn = totalKop / 100;
    int resKop = totalKop % 100;

    if (resKop < 0) resKop = -resKop;

    result.Init(resGrn, (unsigned char)resKop);
    return result;
}

// Порівняння на рівність
bool Money::IsEqual(const Money& other) const
{
    long k1 = grn * 100 + (grn >= 0 ? kop : -kop);
    long k2 = other.grn * 100 + (other.grn >= 0 ? other.kop : -other.kop);
    return k1 == k2;
}

// Порівняння на нерівність
bool Money::IsNotEqual(const Money& other) const
{
    return !IsEqual(other);
}

// Перевірка: перша сума більша за другу
bool Money::IsGreater(const Money& other) const
{
    long k1 = grn * 100 + (grn >= 0 ? kop : -kop);
    long k2 = other.grn * 100 + (other.grn >= 0 ? other.kop : -other.kop);
    return k1 > k2;
}

// Перевірка: перша сума менша за другу
bool Money::IsLess(const Money& other) const
{
    long k1 = grn * 100 + (grn >= 0 ? kop : -kop);
    long k2 = other.grn * 100 + (other.grn >= 0 ? other.kop : -other.kop);
    return k1 < k2;
}