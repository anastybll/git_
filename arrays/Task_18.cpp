// После всех четных элементов вставить X.
#include<iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

using namespace std;

int main() 
{
	setlocale(LC_ALL, "rus");
	int n = 0, x, y, d;
	cout << "Введите длину массива: ";
	cin >> d;
	cout << "Введите число x: ";
	cin >> x;

	int* a = new int[100]; // выделение памяти под массив
	srand((unsigned)time(NULL)); // начальная точка для старта массива

	// заполняем массив элементами
	for (int i = 0;i < d;i++)
	{
		a[i] = rand() % 10;
		cout << a[i] << ' ';
	}
	cout << endl;
	
	// вставка элемента x после четных элементов
	for (int i = 0; i < d;i++) 
	{
		if (a[i] % 2 == 0) // проверяем на четность элемент
		{
			d++;
			for (int j = d - 1;j != i;j--) // идем с конца массива для вставки x
			{
				a[j] = a[j - 1];
			}
			a[i + 1] = x;
			i++;
		}
	}
	
	// вывод массива
	for (int i = 0;i < d;i++) 
	{
		cout << a[i] << ' ';
	}
	cout << endl;
	delete[] a;
}
