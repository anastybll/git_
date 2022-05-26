//вывести номера эл-ов кратные 4 и подходящим в диапазон
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
	int i,l;
	

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

	int k = 0;
	for (i=0; i < n; i++) {
		if (a[i] % 4 == 0 && (a[i]>=b || a[i]<=c)) {
			k++;
		    if (a[i] != 0) {
				l = i;
				cout << "Номера эл-ов: " << l << endl;
			}
		}
	}
	if (!k) {
		cout << "Таких эл-ов нет\n";
	}
}
