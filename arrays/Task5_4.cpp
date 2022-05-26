//среднее арифметическое нечетных элементов на попадающих в заданный диапазон 
#include<iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

using namespace std;

int main() {
	setlocale(LC_ALL, "rus");
	int n;
	cout << "Размер массива = "; cin >> n;
	int* a = new int[n]; // выделение памяти под массив
	srand((unsigned)time(NULL)); // начальная точка для старта массива
	
	for (int i = 0; i < n; i++) { //псевдослучайное число
		a[i] = rand() % 15;
		cout << a[i] << " ";
	}
	cout << endl;

	int b, c;
	cout << "b = ";cin >> b; // задаем диапазон для массива
	cout << "c = ";cin >> c;
	
	if (b > c) { // защита от не правильного ввода диапазона массива
		swap(b, c);
	}

	int k = 0, sum = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] % 2 != 0 && (a[i]<b || a[i]>c)) {
			k++;
			sum += a[i];
		}
	}
	if (!k) {
		cout << "Таких эл-ов нет\n";
	}
	else {
		cout << "Среднее арифметическое = " << 1.0 * sum / k << endl;
	}
}
