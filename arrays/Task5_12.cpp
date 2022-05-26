//«аменить все максимальные элементы им противоположными
#include<iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

using namespace std;

int main() {
	setlocale(LC_ALL, "rus");
	int n;
	cout << "–азмер массива = "; cin >> n;
	int* a = new int[n]; // выделение пам€ти под массив
	srand((unsigned)time(NULL)); // начальна€ точка дл€ старта массива

	for (int i = 0; i < n; i++) { //псевдослучайное число
		a[i] = rand() % 15;
		cout << a[i] << " ";
	}
	cout << endl;

	int max = a[0]; //нахождение максимального элемента в массиве
	for (int i = 1; i <= n; i++)
		if (a[i] > max)
			max = a[i];
	for (int i = 0;i < n;i++) // максимальный элемент становитс€ минимальным 
		if (a[i] == max)
			a[i] = -max;
	for (int i = 0;i < n;i++)
		cout << a[i] << " ";
}
