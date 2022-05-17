// 1. ������� �� ����������� � ������� ������� ����������

#include<iostream>
#include<fstream>
#include <algorithm>

using namespace std;

ifstream in("sort.txt");
ofstream out("output.txt");

int n = 5; // ����������� ������ ������� � �����

void qsort(int* mas, int size) 
{
	int i = 0; // ������ �������
	int j = size - 1; //  ����� �������

	int mid = mas[size / 2]; // ���������� ������������  �������� �������

	do // ����� ������
	{
		while (mas[i] < mid) // � ����� ����� ������� ���������� ��������, ������� ������ ������������
		{
			i++;
		}

		while (mas[j] > mid) // � ������ ����� ������� ���������� ��������, ������� ������ ������������
		{
			j--;
		}

		if (i <= j) // ������ �������� �������
		{
			int tmp = mas[i];
			mas[i] = mas[j];
			mas[j] = tmp;
		}
		i++;
		j--;
	} while (i < j);

	if (j > 0) // ���� �������� ��� �����������(������� ����� �����, ����� ������)
	{
		qsort(mas, j + 1);
	}
	if (i < size)
	{
		qsort(&mas[i], size - i);
	}
}

int** inFile() //���� �� �����
{ 
	int** mas = new int* [n];
	for (int i = 0; i < n; i++)
		mas[i] = new int[n];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			in >> mas[j][i];
	return mas;
}

void OutFile(int**& mas) //����� � ����
{ 
	for (int j = 0; j < n; j++, out << endl)
		for (int i = 0; i < n; i++)
			out << mas[i][j] << " ";
}

int main()
{
	int** mas = inFile();
	for (int i = 0; i < n; i++)
		qsort(mas[i], n );
	OutFile(mas);
	return 0;
}