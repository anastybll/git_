// 9. Каждый третий столбец по убыванию, остальные по возрастанию с помощью сортировки расческой

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>

using namespace std;

ifstream in("sort.txt");
ofstream out("output.txt");

void sort(vector<int>& vec, int n, int f) // сортировка 
{
	int gap = n / 1.247;
	while (gap >= 1) 
	{
		if (gap < 1)
			gap = 1;

		for (int i = 0; i < n - gap; ++i)
			if (f * vec[i] > f * vec[i + gap])
				swap(vec[i], vec[i + gap]);

		gap /= 1.247;
	}
}

int main() 
{
	vector<int> v0; // создаем вектор
	while (in.peek() != EOF) 
	{
		int a = 0; in >> a; v0.push_back(a); // из файла заполняем его
	}
	int n = sqrt(v0.size()); // размерность вектора(корень т.к. матрица квадратная)
	vector<vector<int>> vec; vec.resize(n);
	for (int i = 0; i < n; vec[i].resize(n), ++i);
	for (int i = 0; i < v0.size(); ++i)
		vec[i % n][i / n] = v0[i];
	for (int i = 0; i < n; ++i)
		sort(vec[i], n, (i % 3) ? 1 : -1);

	for (int i = 0; i < n; out << "\n", ++i) // вывод новой матрицы
		for (int j = 0; j < n; out << vec[j][i] << " ", ++j);
}