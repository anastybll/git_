//  Удалить все элементы, оканчивающиеся на цифру 𝑋.
#include<iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

using namespace std;

int main() 
{
	setlocale(LC_ALL, "rus");
	int n,x;
	cout << "Размер массива = ";
	cin >> n;
	cout << "Введите число x: ";
	cin >> x;
	
	int* a = new int[n]; // выделение памяти под массив
	srand((unsigned)time(NULL)); // начальная точка для старта массива
	
	// заполняем массив элементами
	for (int i = 0; i < n; i++)   
	{
		a[i] = rand() % 100;
		cout << a[i] << " ";
	}
	cout << endl;
	
	// удаляем из массива элементы, оканчивающиеся на x
	int b = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] % 10!=x) // проверяем оканчивается элемент на x
		{
			a[b++] = a[i]; // сдвиг
		}
	}
	
	// выводим массив
	for (int i = 0; i < b;i++)
	{
		cout << a[i] << ' ';
	}
	cout << endl;
	delete[] a;
}
