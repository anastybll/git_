/*�������� ������ ������������ ������� � �������������� �������, ������� �������, �� ������ ����������� ������� ��
���������������� �������, �� ������� �������.����� ����� ���������.*/

#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<time.h>

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	int n, i, j, indmax = 0, indmin = 0, indmax2 = 0, indmin2 = 0;
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
			cout  << a[i][j] << "\t"; // ����� �� �����
		}
	}
	cout << endl;

	
	int max = a[0][0];

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j <= n-1-i;j++) 
		{
			if (a[i][j] > max) 
			{
				max = a[i][j];
				indmax = i; // ������ ������ ������� ������������� �������� �������
				indmax2 = j; // ������ ������� ������� ������������� �������� �������
			}
		}

	}
	cout << max << " " << indmax << " " << indmax2 << endl;
	
	int min = a[1][n - 1];
	
	
	for (int i = 1; i < n; i++) 
	{
		for (int j = n-i; j < n;j++)
		{
			if (a[i][j] < min) 
			{
				min = a[i][j];
				indmin = i; // ������ ������ ������� ������������ �������� �������
				indmin2 = j; // ������ ������� ������� ������������ �������� �������
			}
		}

	}
	cout << min << " " << indmin << " " << indmin2 << endl;
	
	
	int y = a[indmax][indmax2];
	a[indmax][indmax2] = a[indmin][indmin2];
	a[indmin][indmin2] = y;
	

	cout << "��������������� ������:" << endl; //����� �������
	for (i = 0;i < n;i++)
	{
		for (int j = 0;j < n;j++)
			cout << a[i][j] << "\t";
		cout << "\n";
	}
}
