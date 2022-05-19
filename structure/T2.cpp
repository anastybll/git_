//ƒано множество точек в пространстве. Ќайти такую точку, что шар радиуса R, содержит наибольшее количество точек.

#include <iostream>
#include <cmath>

using namespace std;

struct point // структура точек в пространстве
{
	int x, y, z;
};

void solve(point* list, int n)
{
	for (int i = 0; i < n; ++i) // идем по массиву точек
	{
		cout << "Point " << i + 1 << "\nInput x, y, z: "; // вводим координаты x y z
		cin >> list[i].x >> list[i].y >> list[i].z; cout << "\n";
	}

	int r = 0;
	cout << "Input R = "; // вводим радиус окружности
	cin >> r;
	cout << "\n";

	int max_num = 0; // перемена€ дл€ определени€ максимальных точек
	int* count = new int[n]; // создаем массив дл€ записи находимых точек

	for (int i = 0; i < n; ++i)
		count[i] = 0;

	for (int i = 0; i < n; ++i) // проходимс€ по всем точкам (от каждой точки смотрим радиус и считаем сколько попадает точек)
		for (int j = 0; j < n; ++j)
			if ((list[i].x - list[j].x) * (list[i].x - list[j].x) + (list[i].y - list[j].y) * (list[i].y - list[j].y) + (list[i].z - list[j].z) * (list[i].z - list[j].z) <= r * r)
				count[i] += 1;

	for (int i = 0; i < n; ++i) // сравниваем кол-во вход€щих точек
		if (count[i] > max_num)
			max_num = count[i];

	cout << "answer: \n"; // вывод ответа
	
	for (int i = 0; i < n; ++i) // вывод точки
		if (count[i] == max_num)
			cout << "point " << i + 1 << " (" << list[i].x << ", " << list[i].y << ", " << list[i].z << ")\n";


}

int main() {
	int n = 0;
	cout << "Input n = "; // вводим коли-во точек
	cin >> n;

	point* list = new point[n]; // создаем массив дл€ этих точек

	solve(list, n); // вызываем функцию

	return 0;
}

/*
* 3
* 0 0 0
* 1 1 1
* 2 2 2
* 2
*/