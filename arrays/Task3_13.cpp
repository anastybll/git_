// 13. ������� ��� ������, ���������� ���� �� ���� ������� x.
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	int k = 0, c, x, n, i, j;
	cout << "������� ������ ������� n: ";
	cin >> n;
	cout << "������� ����� x: "; 
	cin >> x;

	int** a = new int* [n]; // ��������� ������ ��� ������� n
	for (i = 0; i < n; i++) 
	{
		a[i] = new int[n];
	}

	cout << "������� ������ n: " << '\n'; // ��������� ������ �������
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			cin >> a[i][j];
		}
	}
	// ��������
	for (i = 0; i < n; i++) 
	{
		c = 0; // ���������� ��� �������� �������� ��������� � �������
		for (j = 0; j < n; j++)
		{
			if (a[i][j] == x) c++;
		}
		if (c > 0) // ���� ������� ������ ��� �������� ��������� �������
		{
			k++;
			for (int d = i; d < n - k; d++) 
			{
				for (j = 0; j < n; j++) 
				{
					a[d][j] = a[d + 1][j];
				}
			}
			i--;
		}
	}

	cout << "����� ������ �������" << '\n';
	for (i = 0; i < n - k; i++) 
	{
		for (j = 0; j < n; j++) 
		{
			cout << a[i][j] << ' ';
		}
		cout << '\n';
	}
}
