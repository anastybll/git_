// ����� ���� ������ ��������� �������� X.
#include<iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

using namespace std;

int main() 
{
	setlocale(LC_ALL, "rus");
	int n = 0, x, y, d;
	cout << "������� ����� �������: ";
	cin >> d;
	cout << "������� ����� x: ";
	cin >> x;

	int* a = new int[100]; // ��������� ������ ��� ������
	srand((unsigned)time(NULL)); // ��������� ����� ��� ������ �������

	// ��������� ������ ����������
	for (int i = 0;i < d;i++)
	{
		a[i] = rand() % 10;
		cout << a[i] << ' ';
	}
	cout << endl;
	
	// ������� �������� x ����� ������ ���������
	for (int i = 0; i < d;i++) 
	{
		if (a[i] % 2 == 0) // ��������� �� �������� �������
		{
			d++;
			for (int j = d - 1;j != i;j--) // ���� � ����� ������� ��� ������� x
			{
				a[j] = a[j - 1];
			}
			a[i + 1] = x;
			i++;
		}
	}
	
	// ����� �������
	for (int i = 0;i < d;i++) 
	{
		cout << a[i] << ' ';
	}
	cout << endl;
	delete[] a;
}
