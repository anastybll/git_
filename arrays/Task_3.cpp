// ������� ��� ������ ��������.
#include<iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	int n;
	cout << "������ ������� = "; 
	cin >> n;
	
	int* a = new int[n]; // ��������� ������ ��� ������
	srand((unsigned)time(NULL)); // ��������� ����� ��� ������ �������
	
	// ��������� ������ ������� 
	for (int i = 0; i < n; i++) 
	{ 
		a[i] = rand() % 10;
		cout << a[i] << " ";
	}
	cout << endl;
	
	// ������� �� ������� ������ ��������
	int b = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] % 2==0)
		{
			a[b++] = a[i];
		}
	}
	
	// ������� ����� ������
	for (int i = 0; i < b;i++) 
	{
		cout << a[i] << ' ';
	}
	cout << endl;
	delete[] a;
}
