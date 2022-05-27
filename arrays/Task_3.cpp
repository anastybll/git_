// ”далить все четные элементы.
#include<iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	int n;
	cout << "–азмер массива = "; 
	cin >> n;
	
	int* a = new int[n]; // выделение пам€ти под массив
	srand((unsigned)time(NULL)); // начальна€ точка дл€ старта массива
	
	// заполн€ем массив числами 
	for (int i = 0; i < n; i++) 
	{ 
		a[i] = rand() % 10;
		cout << a[i] << " ";
	}
	cout << endl;
	
	// удал€ем из массива четные элементы
	int b = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] % 2==0)
		{
			a[b++] = a[i];
		}
	}
	
	// выводим новый массив
	for (int i = 0; i < b;i++) 
	{
		cout << a[i] << ' ';
	}
	cout << endl;
	delete[] a;
}
