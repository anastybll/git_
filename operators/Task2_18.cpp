#include<iostream>;
#include<cmath>;

using namespace std;

int main() {
	setlocale(LC_ALL, "rus");
	float a1, b1, c1, a2, b2, c2,l,m,t1,t2;
	const float eps = 0.00001;
	cout << "a1 = ";
	cin >> a1;
	cout << "b1 = ";
	cin >> b1;
	cout << "c1 = ";
	cin >> c1;
	cout << "a2 = ";
	cin >> a2;
	cout << "b2 = ";
	cin >> b2;
	cout << "c2 = ";
	cin >> c2;

	l = sqrt(pow(a1, 2) + pow(b1, 2)); // выражение для проверки первого уравнения 
	m = sqrt(pow(a2, 2) + pow(b2, 2)); // выражение для проверки второго уравнения

	if ((l < eps) && (m < eps)) // проверка двух уравнений
	{
		cout << "Не прямые" << endl;
	}
	else if (l < eps) // проверка первго уравнения
	{
		cout << "1 - не прямая" << endl;
	}
	else if (m < eps) // проверка второго уравнения
	{
		cout << "2-не прямая" << endl;
	}
	else if ((abs(a1 * b2) - abs(a2 * b1) == 0)&&((a1 / a2) != (b1 / b2) || ((a1 / a2) != (c1 / c2)) || ((b1 / b2) != (c1 / c2)))) // проверяем параллельность прямых
	{
		cout << "Параллельны" << endl;
	}
	else if ((a1 / a2) == (b1 / b2) && ((a1 / a2) == (c1 / c2))) // проверяем совпадают ли прямые
	{
		cout << "Совпадают" << endl;
	}
	else {
		t1 = ((-c1 * b2) - (b1 * (-c2))) / ((a1 * b2) - (a2 * b1)); // точки пересечения 
		t2 = ((a1 * (-c2)) - (-c1 * a2)) / ((a1 * b2) - (a2 * b1));
		
		cout << "Пересекаются" << endl;
		cout << t1 << endl;
		cout << t2 << endl;

	}
}

