//Заполнить массив n × n числами от 0 до n^2 − 1 в требуемом порядке
#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<time.h>

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	int n = 5, k = 0, i;

	int** a = new int* [n]; // выделение памяти под массив
	for (int i = 0; i < n; i++)
	{
		a[i] = new int[n]; // выделение памяти для каждого указателя
	}

	for (int j = 0; j < n; j+=2) {

	for (int i = n - 1; i >= 0; i--)
	{
		a[i][j] = k;
		k++;
		if (k > n * n - 1) {
			break;
		}
	}
	for (int i = 0; i < n;i++) {
		a[i][j+1] = k;
		k++;
		if (k > n * n - 1) {
			break;
		}
	}
	}
	// вывод массива
	for (int j = 0;j < n;j++)
	{
		for (i = 0;i < n;i++)
		{
			cout << a[i][j] << "\t";
		}
		cout << "\n";
	}
}
