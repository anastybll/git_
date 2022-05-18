//12. Даны две последовательности целых чисел.В первой последовательности удалить все элементы, кратные X.
//Во второй — заменить элементы, попадающие в интервал[a, b] числом Y.
//Отсортировать данные последовательности.Объединить их в одну отсортированную последовательноcть.

#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>

using namespace std;

void output_vector(vector<int>v) // функция для выводы векторов на экран
{
	for (vector<int>::iterator iter = v.begin(); iter != v.end(); iter++) 
		cout << *iter << " ";
	cout << endl;
}

int x;
bool kratn(int y) // кратно ли число у х
{ 
	return y % x == 0;
}


int a, b;
bool interval(int y) // входит ли число в интервал
{ 
	return y <= b && y >= a;
}


int main() 
{
	setlocale(LC_ALL, "rus");
	int n; 
	cout << "n = "; 
	cin >> n;

	cout << "Первый вектор:" << endl;
	vector<int>v1; // описание первого вектора
	for (int i = 0; i < n; i++) // заполнение вектора элементами
		v1.push_back(rand()%10);
	output_vector(v1);
	cout << endl;


	cout << "Второй вектор:" << endl;
	vector<int>v2; // описание второго вектора
	for (int i = 0; i < n; i++) // заполнение вектора элементами
		v2.push_back(rand()%10);
	output_vector(v2);
	cout << endl;


	cout << "В первом удалить все элементы, кратные x:" << endl;
	cout << "x = ";
	cin >> x;

	vector<int>::iterator iter = remove_if(v1.begin(), v1.end(), kratn);
	v1.erase(iter, v1.end()); // удаляем четные элементы
	output_vector(v1);
	cout << endl;

	
	cout << "Во втором заменить элементы, попадающие в [a, b] числом y" << endl;
	int y;
	cout << "a = "; // вводим диапозон и y
	cin >> a;
	cout << "b = ";
	cin >> b;
	cout << "y = ";
	cin >> y;

	replace_if(v2.begin(), v2.end(), interval, y); // замена
	output_vector(v2);
	cout << endl;

	// сортировка
	cout << "Сортируем первый вектор: " << endl;
	sort(v1.begin(), v1.end());
	output_vector(v1);
	cout << "Сортируем второй вектор: " << endl;
	sort(v2.begin(), v2.end());
	output_vector(v2);
	cout << endl;

	
	cout << "Объединение векторов: " << endl;
	vector<int> v3(v1.size() + v2.size());
	merge(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());
	output_vector(v3);
	return 0;
}