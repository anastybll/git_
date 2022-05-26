/*Ќайти первый минимальный и первый максимальный элементы массива.
ѕоиск вести построчно.ѕомен€ть местами строки, содержащие эти элементы.*/

#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<time.h>

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	int n, i, j, indmax = 0, indmin = 0;
	cout << "n = "; // размер массива n*n
	cin >> n;


	int** a = new int* [n]; // выделение пам€ти под массив
	for (int i = 0; i < n; i++)
	{
		a[i] = new int[n]; // выделение пам€ти дл€ каждого указател€
	}

	srand((unsigned)time(NULL));

	for (int i = 0; i < n; i++, cout << endl)
	{
		for (int j = 0;j < n;j++)
		{
			a[i][j] = rand() % 15; // заполнение элемента массива
			cout << a[i][j] << " "; // вывод на экран
		}
	}
	cout << endl;

	int min = a[0][0];
	int max = a[0][0];

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n;j++)
		{
			if (a[i][j] > max)
			{
				max = a[i][j];
				indmax = i; // индекс строки первого максимального элемента массива
			}
		}

	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n;j++)
		{
			if (a[i][j] < min)
			{
				min = a[i][j];
				indmin = i; // индекс строки первого минимального элемента массива
			}
		}

	}

	for (int j = 0;j < n;j++)
	{ // мен€ем строки местами
		int y = a[indmax][j];
		a[indmax][j] = a[indmin][j];
		a[indmin][j] = y;
	}

	cout << "преобразованный массив:" << endl;
	for (i = 0;i < n;i++)
	{
		for (int j = 0;j < n;j++)
			cout << a[i][j] << "\t";
		cout << "\n";
	}
}
