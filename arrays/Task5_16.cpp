//�������� ������� ������ ����������� � ������ ������������ �������� �������
#include<iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

using namespace std;

int main() {
	setlocale(LC_ALL, "rus");
	int n,m=0,r=0,y;
	cout << "������ ������� = "; cin >> n;
	int* a = new int[n]; // ��������� ������ ��� ������
	srand((unsigned)time(NULL)); // ��������� ����� ��� ������ �������

	for (int i = 0; i < n; i++) { //��������������� �����
		a[i] = rand() % 15;
		cout << a[i] << " ";
	}
	cout << endl;

	int max = a[0];
	int min = a[0];
	
	for (int i = 1; i <= n; i++) {
		if (a[i] > max) {
			max = a[i];
			m = i; // ������ ������� ������������� �������� �������
		}
	}
	for (int i = 1; i < n; i++) {
		if (a[i] < min) {
			min = a[i];
			r = i; // ������ ������� ������������ �������� �������
		}
	}
	//������ ������� ������������ � ����������� �������� 
	y = a[m];
	a[m] = a[r];
	a[r] = y;
	
	for (int i = 0;i < n;i++) {
		cout << a[i] << " ";
	}
}


