#include<iostream>;
#include<cmath>;

using namespace std;

int main() {
	setlocale(LC_ALL,"rus");
	float x;
	cout << "Введите значение x = ";
	cin >> x;
	const float eps = 0.00001;
	//проверяем ОДЗ
	if (x < -5) {
		cout << "Корень из отрицательного числа";
	}
	else if (x > 4 || abs(x - 4) < eps) {
		cout << "Логарифм отрицательного числа";
	}
	else if ((x + 1) < eps) {
		cout << "Деление на ноль";
	}
	else { //функция определена
		float F = (sqrt(x + 5) + log(8 - 2 * x)) / (x + 1);
		cout << "F = " << F << endl;
	}
}
