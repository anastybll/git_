// 1. Дана последовательность целых чисел. Найти сумму элементов, не попадающих в заданный интервал[𝑎, 𝑏].

#include<iostream>
#include<vector>
#include<numeric>

using namespace std;

int main() 
{
	int n, i;
	cout << "n= ";
	cin >> n;
	vector<int>v; // описание вектора
	for (int i = 0; i < n; i++) // заполнение вектора элементами
		v.push_back(rand()%10);
	
	for (int i = 0; i < v.size(); i++)//вывод с помощью индекса
		 cout << v[i] << " ";
	cout << endl;

	int a, b; // вводим промежуток
	cout << "a = ";
	cin >> a;
	cout << "b = ";
	cin >> b;

	int sum = accumulate(v.begin(), v.end(), 0, [a, b](int& s, int& x) {return s += (x<a || x>b ? x : 0); }); // считаем сумму элеменот в зависимости от попадания элемента в промежуток
	cout << sum;
	return 0;
}