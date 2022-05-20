//1. Создайте рекурсивную функцию, вычисляющую факториал числа.
#include<iostream>

using namespace std;

long double factorial(int n)
{
    if (n < 0) // если ввели отрицательное число
        return 0; // возвращаем ноль
    if (n == 0) // если ввели ноль,
        return 1; // возвращаем факториал от нуля это 1 
    else // Во всех остальных случаях
        return n * factorial(n - 1); // делаем рекурсию
}

int main()
{
    int n;
    setlocale(LC_ALL,"rus");
    cout << "Введите число для вычисления факториала: ";
    cin >> n;
    cout << "Факториал для числа " << n << " = " << factorial(n) << endl; // функция для вычисления факториал
    return 0;
}
