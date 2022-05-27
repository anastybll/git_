﻿// 3. После строк, содержащих хотя бы один элемент 𝑌 , вставить строку 𝑋.
#include <iostream>
#include <cmath>

using namespace std;

int main() 
{
	setlocale(LC_ALL, "rus");
	int n,y, z = 0, c = 0;
	cout << "Введите размер массива n: ";
	cin >> n;
	cout << "Введите число y: ";
	cin >> y;

	int** a = new int* [2 * n]; // выделение памяти для массива n
	for (int i = 0; i < 2 * n; i++)
	{
		a[i] = new int[n];
	}

	cout << "Введите массив n " << '\n'; // заполняем массив числами
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++) 
		{
			cin >> a[i][j];
		}
	}

	int* b = new int[n]; // выделение памяти для массива, который будет содержать строку для вставки
	cout << '\n' << "Введите строку x" << '\n';
	for (int i = 0; i < n; i++)
	{
		cin >> b[i];
	}
	// вставка
	for (int i = 0; i < n + z; i++) 
	{
		c = 0; // переменная для подсчета элементов в массиве равные y
		for (int j = 0; j < n; j++) 
		{
			if (a[i][j] == y) // проверка элементов (равняются ли они y)
			{
				c++; 
			}
		}
		if (c > 0) // если нашлись нужные нам элементы выполняем вставку
		{
			z++;
			for (int d = n + z - 1; d > i + 1; d--) // идем с конца массива
			{
				for (int j = 0; j < n; j++) 
				{
					a[d][j] = a[d - 1][j];
				}
			}
			i++;
			for (int j = 0; j < n; j++) 
			{
				a[i][j] = b[j]; // вставка
			}
		}
	}

	cout << '\n' << "Вывод нового массива" << '\n';
	for (int i = 0; i < n + z; i++) 
	{
		for (int j = 0; j < n; j++) 
		{
			cout << a[i][j] << ' ';
		}
		cout << '\n';
	}
}




