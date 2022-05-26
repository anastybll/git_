//ѕомен€ть местами строки по следующему правилу : первую с последней, вторую с предпоследней и т.д.

#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<time.h>

using namespace std;

int main() 
{
	setlocale(LC_ALL, "rus");
	int n, i, g, k;
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
	for (i = 0;i < n / 2;i++) 
	{
		for (int j = 0;j < n;j++)
		{
			k = a[i][j];
			a[i][j] = a[n - i - 1][j]; // мен€ем строки
			a[n - i - 1][j] = k;
		}
	}
	cout << "преобразованный массив:" << endl;
	for (i = 0;i < n;i++)
	{
		for (int j = 0;j < n;j++)
			cout << a[i][j] << "\t";
		cout << "\n";
	}
}
