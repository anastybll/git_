/*����� ������ ����������� � ������ ������������ �������� �������.
����� ����� ���������.�������� ������� ������, ���������� ��� ��������.*/

#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<time.h>

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	int n, i, j, indmax = 0, indmin = 0;
	cout << "n = "; // ������ ������� n*n
	cin >> n;


	int** a = new int* [n]; // ��������� ������ ��� ������
	for (int i = 0; i < n; i++)
	{
		a[i] = new int[n]; // ��������� ������ ��� ������� ���������
	}

	srand((unsigned)time(NULL));

	for (int i = 0; i < n; i++, cout << endl)
	{
		for (int j = 0;j < n;j++)
		{
			a[i][j] = rand() % 15; // ���������� �������� �������
			cout << a[i][j] << " "; // ����� �� �����
		}
	}
	cout << endl;

	int min = a[0][0];
	int max = a[0][0];

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n;j++)
		{
			if (a[i][j] > max)
			{
				max = a[i][j];
				indmax = i; // ������ ������ ������� ������������� �������� �������
			}
		}

	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n;j++)
		{
			if (a[i][j] < min)
			{
				min = a[i][j];
				indmin = i; // ������ ������ ������� ������������ �������� �������
			}
		}

	}

	for (int j = 0;j < n;j++)
	{ // ������ ������ �������
		int y = a[indmax][j];
		a[indmax][j] = a[indmin][j];
		a[indmin][j] = y;
	}

	cout << "��������������� ������:" << endl;
	for (i = 0;i < n;i++)
	{
		for (int j = 0;j < n;j++)
			cout << a[i][j] << "\t";
		cout << "\n";
	}
}
