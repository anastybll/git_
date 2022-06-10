#include<iostream>;

using namespace std;

int main() {
	setlocale(LC_ALL, "rus");
	int a,b,c,h, r, S, P, selection;
	const double PI = 3.141592653589793; 
	// создаем меню
	cout << "Выберите тип фигуры" << endl <<
		"1. Круг" << endl <<
		"2. Квадрат" << endl <<
		"3. Треугольник" << endl << 
		"4. Прямоугольник" << endl;
	cin >> selection;
	// в зависимости от выбора в меню вводим необходимые данные для определение площади и периметра 
	switch (selection)
	{
	case 1:
		cout << "Введите радиус = ";
		cin >> r;
		// проверка на верный ввод данных
		if (r < 1) {
			cout << "Ошибка ввода данных";
			break;
		}
		S = PI * r * r; // определяем площадь фигуры
		P = 2 * PI * r; // определяем периметр фигуры
		cout << "Площадь = " << S << endl;
		cout << "Длина = " << P << endl;
		break;
	case 2:
		cout << "Введите значение стороны a = ";
		cin >> a;
		if (a < 1) {
			cout << "Ошибка ввода данных";
			break;
		}
		S = a * a;
		P = 4 * a;
		cout << "Площадь = " << S << endl;
		cout << "Периметр = " << P << endl;
		break;
	case 3:
		cout << "Введите значение стороны a = ";
		cin >> a;
		cout << "Введите значение стороны b = ";
		cin >> b;
		cout << "Введите значение стороны с = ";
		cin >> c;
		cout << "Введите хначение высоты h = ";
		cin >> h;
		if (a < 1 || b < 1 || c < 1 || h < 1) {
			cout << "Ошибка ввода данных";
			break;
		}
		S = 0.5 * a * h;
		P = a + b + c;
		cout << "Площадь = " << S << endl;
		cout << "Периметр = " << P << endl;
		break;
	case 4:
		cout << "Введите значение стороны a = ";
		cin >> a;
		cout << "Введите значение стороны b = ";
		cin >> b;
		if (a < 1 || b < 1) {
			cout << "Ошибка ввода данных";
			break;
		}
		S = a * b;
		P = 2 * (a + b);
		cout << "Площадь = " << S << endl;
		cout << "Периметр = " << P << endl;
		break;

	default:
		cout << "Ошибка, пункт меню отсутствует" << endl;
		break;
	}

}
