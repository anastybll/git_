//������� ������ ��-�� ������� 4 � ���������� � ��������
#include<iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

using namespace std;

int main() {
	setlocale(LC_ALL, "rus");
	int n;
	cout << "������ ������� = "; cin >> n;
	int* a = new int[n]; // ��������� ������ ��� ������
	srand((unsigned)time(NULL)); // ��������� ����� ��� ������ �������
	int i,l;
	

	for (int i = 0; i < n; i++) { //��������������� �����
		a[i] = rand() % 15;
		cout << a[i] << " ";
	}
	cout << endl;

	int b, c;
	cout << "b = ";cin >> b; // ������ �������� ��� �������
	cout << "c = ";cin >> c;

	if (b > c) { // ������ �� �� ����������� ����� ��������� �������
		swap(b, c);
	}

	int k = 0;
	for (i=0; i < n; i++) {
		if (a[i] % 4 == 0 && (a[i]>=b || a[i]<=c)) {
			k++;
		    if (a[i] != 0) {
				l = i;
				cout << "������ ��-��: " << l << endl;
			}
		}
	}
	if (!k) {
		cout << "����� ��-�� ���\n";
	}
}
