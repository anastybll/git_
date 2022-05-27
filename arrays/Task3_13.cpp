// 13. Удалить все строки, содержащие хотя бы один элемент x.
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	int k = 0, c, x, n, i, j;
	cout << "Введите размер массива n: ";
	cin >> n;
	cout << "Введите число x: "; 
	cin >> x;

	int** a = new int* [n]; // выделение памяти для массива n
	for (i = 0; i < n; i++) 
	{
		a[i] = new int[n];
	}

	cout << "Введите массив n: " << '\n'; // заполняем массив числами
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			cin >> a[i][j];
		}
	}
	// удаление
	for (i = 0; i < n; i++) 
	{
		c = 0; // переменная для подсчета нечетных элементов в массиве
		for (j = 0; j < n; j++)
		{
			if (a[i][j] == x) c++;
		}
		if (c > 0) // если нашлись нужные нам элементы выполняем вставку
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

	cout << "Вывод нового массива" << '\n';
	for (i = 0; i < n - k; i++) 
	{
		for (j = 0; j < n; j++) 
		{
			cout << a[i][j] << ' ';
		}
		cout << '\n';
	}
}
