// После всех элементов, равных 𝑋, вставить Y.
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
	cout << "Введети x: ";
	cin >> x;
	cout << "Введите y: ";
	cin >> y;
	
	int* a = new int[100]; // выделение памяти под массив
	srand((unsigned)time(NULL)); // начальная точка для старта массива

	// заполняем массив элементами 
	for (int i = 0;i < d;i++) 
	{
		a[i] = rand() % 10;
		cout << a[i] << ' ';
	}
	cout << endl;
	
	// вставка элемента y после элемента x
	for (int i = 0; i < d;i++)
	{
		if (a[i] == x) { // находим элемент равный x
			d++; 
			for (int j = d - 1;j != i;j--) // идем с конца массива для вставки x
			{
				a[j] = a[j - 1];
			}
			a[i + 1] = y;
			i++;
		}
	}
	
	// выводим массив
	for (int i = 0;i < d;i++) 
	{
		cout << a[i] << ' ';
	}
	cout << endl;
	delete[] a;
}

