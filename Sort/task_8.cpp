// 1. Столбцы по возрастанию с помощью быстрой сортировки

#include<iostream>
#include<fstream>
#include <algorithm>

using namespace std;

ifstream in("sort.txt");
ofstream out("output.txt");

int n = 5; // размерность нашего массива в файле

void qsort(int* mas, int size) 
{
	int i = 0; // начало массива
	int j = size - 1; //  конец массива

	int mid = mas[size / 2]; // вычисление центрального  элемента массива

	do // делим массив
	{
		while (mas[i] < mid) // в левой части массива пропускаем элемента, которые меньше центрального
		{
			i++;
		}

		while (mas[j] > mid) // в правой части массива пропускаем элементы, которые больше центрального
		{
			j--;
		}

		if (i <= j) // меняем элементы местами
		{
			int tmp = mas[i];
			mas[i] = mas[j];
			mas[j] = tmp;
		}
		i++;
		j--;
	} while (i < j);

	if (j > 0) // если осталось что сортировать(сначала левая часть, затем правая)
	{
		qsort(mas, j + 1);
	}
	if (i < size)
	{
		qsort(&mas[i], size - i);
	}
}

int** inFile() //ввод из файла
{ 
	int** mas = new int* [n];
	for (int i = 0; i < n; i++)
		mas[i] = new int[n];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			in >> mas[j][i];
	return mas;
}

void OutFile(int**& mas) //вывод в файл
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