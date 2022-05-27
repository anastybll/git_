// 18. Удалить все столбцы, содержащие хотя бы один элемент, кратный 𝑋.
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
	for (j = 0; j < n; j++)
	{
		c = 0; // переменная для подсчета нечетных элементов в массиве
		for (i = 0; i < n; i++)
		{
			if (a[i][j] % x == 0) c++;
		}
		if (c > 0) // если нашлись нужные нам элементы выполняем удаление
		{
			k++;
			for (int d = j; d < n - k; d++) 
			{
				for (i = 0; i < n; i++) 
				{
					a[i][d] = a[i][d + 1];
				}
			}
			j--;
		}
	}

	cout << "Вывод нового массива" << '\n';
	for (i = 0; i < n; i++) {
		for (j = 0; j < n - k; j++) 
		{
			cout << a[i][j] << ' ';
		}
		cout << '\n';
	}
}
