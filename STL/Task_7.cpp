//7. ƒана последовательность целых чисел. ”далить все четные элементы. 
//«аменить все максимальные элементы на минимальный. Ќайти количество элементов, кратных ??.

#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>

using namespace std;

bool odd(int x) // €вл€етс€ ли элемент четным
{ 
	return x % 2 == 0;
}

int x=1; 
bool kratn(int y) // кратен ли y x
{ 
	return y % x == 0;
}

bool nekratn(int y) // не кратен ли y X
{ 
	return y % x!= 0;
}

int main() 
{
	setlocale(LC_ALL, "rus");
	int n, i;
	cout << "n= ";
	cin >> n;

	vector<int>v; // описание вектора
	for (int i = 0; i < n; i++) // заполнение вектора элементами
		v.push_back(rand()%10);

	for (int i = 0; i < v.size(); i++)//вывод с помощью индекса
		cout << v[i] << " ";
	cout << endl;

	
	cout << "”даление всех четных элементов:" << endl;
	vector<int>v1(v); // создаем копию вектора v, дл€ выполнени€ действий
	vector<int>::iterator it = remove_if(v1.begin(), v1.end(), odd);
	v1.erase(it, v1.end()); // удаление четных элементов

	for (vector<int>::iterator iter = v1.begin(); iter != v1.end(); iter++) // вывод без четных элементов
		cout << *iter << " ";
	cout << endl;


	cout << "«амена Max на Min:" << endl;
	v1 = v; // присваиваем вектору v1 значени€ вектора v
	int Max = *max_element(v1.begin(), v1.end()); // с помощью функций находим максимум и минимум в векторе
	int Min = *min_element(v1.begin(), v1.end());
	replace(v1.begin(), v1.end(), Max, Min); // замен€ем максимум на минимум
	for (vector<int>::iterator iter = v1.begin(); iter != v1.end(); iter++) // вывод с заменой
		cout << *iter<<" ";
	cout << endl;
	

	cout << " ол-во кратных X:" << endl;
	v1 = v; // присваиваем вектору v1 значени€ вектора v
	cout << "X = "; 
	cin>> x;
	int count = 0; // переменна€ дл€ количества
	replace_if(v1.begin(), v1.end(), kratn, x); // мен€ем местами элементы с веденным x, если число кратно x
	replace_if(v1.begin(), v1.end(), nekratn, 0); // мен€ем местами элементы с 0, если число некратно 
	count = accumulate(v1.begin(), v1.end(), 0) / x; // считаем количество
	cout << count << endl;
	return 0;
}