#include<iostream>
#include<cmath>

using namespace std;

int main() 
{
	setlocale(LC_ALL, "rus");
	float a, b, h;
	cout << "a = ";
	cin >> a;
	cout << "b = ";
	cin >> b;
	cout << "h = ";
	cin >> h;
	const float eps = 0.00001;

	// проверка на корректный ввод данных
	if (a > b) 
	{
		swap(a, b);
	}
	for (float x = a; x < b + h; x += h)
	{
		// проверяем ОДЗ
		if ( x < 1) 
		{
			cout << "Корень из отрицательного числа";
			break;
		}
		else if (x < 4 || abs(x - 4) < eps) 
		{
			cout << "Логарифм отрицательного числа";
			break;
		}
		else if ((x - 4) < eps) 
		{
			cout << "Деление на ноль";
			break;
		}
		else //функция определена
		{ 
			float y = sqrt(x * x + 1) / (log10(2 * x - 8));
			cout << "x = " << x << " y = " << y << endl;
		}
	}
}