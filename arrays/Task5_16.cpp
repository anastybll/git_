//ѕомен€ть местами первый минимальный и первый максимальный элементы массива
#include<iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

using namespace std;

int main() {
	setlocale(LC_ALL, "rus");
	int n,m=0,r=0,y;
	cout << "–азмер массива = "; cin >> n;
	int* a = new int[n]; // выделение пам€ти под массив
	srand((unsigned)time(NULL)); // начальна€ точка дл€ старта массива

	for (int i = 0; i < n; i++) { //псевдослучайное число
		a[i] = rand() % 15;
		cout << a[i] << " ";
	}
	cout << endl;

	int max = a[0];
	int min = a[0];
	
	for (int i = 1; i <= n; i++) {
		if (a[i] > max) {
			max = a[i];
			m = i; // индекс первого максимального элемента массива
		}
	}
	for (int i = 1; i < n; i++) {
		if (a[i] < min) {
			min = a[i];
			r = i; // индекс первого минимального элемента массива
		}
	}
	//мен€ем местами максимальный и минимальный элеметны 
	y = a[m];
	a[m] = a[r];
	a[r] = y;
	
	for (int i = 0;i < n;i++) {
		cout << a[i] << " ";
	}
}


