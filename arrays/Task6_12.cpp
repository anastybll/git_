/*Заменить первый максимальный элемент в заштрихованной области, включая границы, на первый минимальный элемент из
незаштрихованной области, не включая границы.Поиск вести построчно.*/

#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<time.h>

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	int n, i, j, indmax = 0, indmin = 0, indmax2 = 0, indmin2 = 0;
	cout << "n = "; // размер массива n*n
	cin >> n;
	

	int** a = new int* [n]; // выделение памяти под массив

	for (int i = 0; i < n; i++) 
	{
		a[i] = new int[n]; // выделение памяти для каждого указателя
	}

	srand((unsigned)time(NULL));

	for (int i = 0; i < n; i++, cout << endl)
	{
		for (int j = 0;j < n;j++)
		{
			a[i][j] = rand() % 15; // заполнение элемента массива
			cout  << a[i][j] << "\t"; // вывод на экран
		}
	}
	cout << endl;

	
	int max = a[0][0];

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j <= n-1-i;j++) 
		{
			if (a[i][j] > max) 
			{
				max = a[i][j];
				indmax = i; // индекс строки первого максимального элемента массива
				indmax2 = j; // индекс столбца первого максимального элемента массива
			}
		}

	}
	cout << max << " " << indmax << " " << indmax2 << endl;
	
	int min = a[1][n - 1];
	
	
	for (int i = 1; i < n; i++) 
	{
		for (int j = n-i; j < n;j++)
		{
			if (a[i][j] < min) 
			{
				min = a[i][j];
				indmin = i; // индекс строки первого минимального элемента массива
				indmin2 = j; // индекс столбца первого минимального элемента массива
			}
		}

	}
	cout << min << " " << indmin << " " << indmin2 << endl;
	
	
	int y = a[indmax][indmax2];
	a[indmax][indmax2] = a[indmin][indmin2];
	a[indmin][indmin2] = y;
	

	cout << "преобразованный массив:" << endl; //вывод массива
	for (i = 0;i < n;i++)
	{
		for (int j = 0;j < n;j++)
			cout << a[i][j] << "\t";
		cout << "\n";
	}
}
