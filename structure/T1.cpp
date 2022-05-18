// Создать структуру Hotel, содержащую след. данные: ФИО туриста, дату прибытия, кол-во дней пребывания в отеле.
// Определить людей, находящихся в отеле в заданный день. Необходимо проверить корректность ввода дат.

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct hotel { // структура отель
	string full_name;
	int day, month, year;
	int day_leave, month_leave, year_leave;
	bool vis, vis_leave;
};

void output(string line, hotel* list, int n) {
	int day = int(line[0] - '0') * 10 + int(line[1] - '0'); // проводим из строки данные о дате к типу инт
	int month = int(line[3] - '0') * 10 + int(line[4] - '0');
	int year = int(line[6] - '0') * 1000 + int(line[7] - '0') * 100 + int(line[8] - '0') * 10 + int(line[9] - '0');
	cout << "People in hotel: \n\n"; // вводим сколько сейчас лудей в отеле
	for (int i = 0; i < n; ++i) { // осуществляем проверку находится ли человек в отеле в заданную дату 
		if (list[i].year < year && year < list[i].year_leave) {
			cout << list[i].full_name << "\n";
			continue;
		}
		if (list[i].year < list[i].year_leave) {
			if (list[i].year == year && list[i].month < month) {
				cout << list[i].full_name << "\n";
				continue;
			}
			if (list[i].year == year && list[i].month == month && list[i].day <= day) {
				cout << list[i].full_name << "\n";
				continue;
			}
			if (list[i].year_leave == year && list[i].month_leave > month) {
				cout << list[i].full_name << "\n";
				continue;
			}
			if (list[i].year_leave == year && list[i].month_leave == month && list[i].day_leave >= day) {
				cout << list[i].full_name << "\n";
				continue;
			}
		}
		if (list[i].year == list[i].year_leave && list[i].year == year) {
			if (list[i].month < month && month < list[i].month_leave) {
				cout << list[i].full_name << "\n";
				continue;
			}
			if (list[i].month < list[i].month_leave) {
				if (list[i].month == month && list[i].day <= day) {
					cout << list[i].full_name << "\n";
					continue;
				}
				if (list[i].month_leave == month && list[i].day_leave >= day) {
					cout << list[i].full_name << "\n";
					continue;
				}
			}
			if (list[i].month == list[i].month_leave && list[i].month == month) {
				if (list[i].day <= day && list[i].day_leave >= day) {
					cout << list[i].full_name << "\n";
					continue;
				}
			}
		}
	}
}

bool check_correct(string line, hotel* list, int i, bool flag) {
	bool correct_format, correct_date = false;
	int day, month, year;

	correct_format = (line.length() == 10 && isdigit(line[0]) && isdigit(line[1]) && isdigit(line[3]) && isdigit(line[4]) && isdigit(line[6]) && isdigit(line[7]) && isdigit(line[8]) && isdigit(line[9]) && line[2] == '.' && line[5] == '.');
	if (correct_format) {
		day = int(line[0] - '0') * 10 + int(line[1] - '0'); // приводим текущую дату из строки к типу итн
		month = int(line[3] - '0') * 10 + int(line[4] - '0');
		year = int(line[6] - '0') * 1000 + int(line[7] - '0') * 100 + int(line[8] - '0') * 10 + int(line[9] - '0');
		bool vis = ((!(year % 4) && (year % 100)) || !(year % 400)); // проверяем високосность года
		switch (month) { // проверяем соответствие днч месяцу
		case 1: case 3: case 5: case 7: case 8: case 10: case 12: correct_date = (day >= 1 && day <= 31); break;
		case 4: case 6: case 9: case 11: correct_date = (day >= 1 && day <= 30); break;
		case 2: correct_date = (vis ? (day >= 1 && day <= 29) : (day >= 1 && day <= 28)); break;
		}

		if (correct_date && flag) {
			list[i].day = day;
			list[i].month = month;
			list[i].year = year;
			list[i].vis = vis;
		}
	}

	return correct_date;
}

void add_day(hotel* list, int i) { // считываем кол-во дней, проведенных в отеле
	list[i].day_leave += 1;
	switch (list[i].month_leave) {
	case 1: case 3: case 5: case 7: case 8: case 10: case 12:
		if (list[i].day_leave > 31) {
			list[i].month_leave += 1;
			list[i].day_leave = 1;
		}
		if (list[i].month_leave == 13) {
			list[i].month_leave = 1;
			list[i].year_leave += 1;
			list[i].vis_leave = ((!(list[i].year_leave % 4) && (list[i].year_leave % 100)) || !(list[i].year_leave % 400));
		}
		break;
	case 4: case 6: case 9: case 11:
		if (list[i].day_leave > 30) {
			list[i].month_leave += 1;
			list[i].day_leave = 1;
		}
		break;

	case 2:
		if (list[i].day_leave > 28 + list[i].vis_leave) {
			list[i].month_leave += 1;
			list[i].day_leave = 1;
		}
		break;
	}
}

void input(hotel* list, int n) { // функция на входе получает динамический массив структур размером n = числу туристов
	string line = "";
	getline(cin, line);
	
	for (int i = 0; i < n; ++i) { // начинаем заполнять данными все поля в структуре в i ячейке массива
		cout << "Number " << i + 1 << "\n";
		cout << "Input full name: ";
		getline(cin, line); // начинаем вводить сначала имя
		list[i].full_name = line;
		cin;

		while (true) { // вводим дату(но сначала дата проходит проверку на корректность )
			cout << "Input date of arriving: ";
			getline(cin, line);
			if (check_correct(line, list, i, true))
				break;
			else
				cout << "Incorrect date!\n";
		}

		int spent_time = 0;
		cout << "Input number of days spent in the hotel: ";
		cin >> spent_time; // вводим сколько дней человек проведет в отеле
		list[i].day_leave = list[i].day;
		list[i].month_leave = list[i].month;
		list[i].year_leave = list[i].year;
		list[i].vis_leave = list[i].vis;
		for (int j = 0; j < spent_time; ++j)
			add_day(list, i);
		getline(cin, line);
		cout << "\n";
	}
	while (true) {
		cout << "Input current date: "; getline(cin, line); // вводим дату по которой мы будем смотреть находится ли еще турст в отеле или нет
		if (check_correct(line, list, -1, false))
			break;
		else
			cout << "Incorrect date!\n";
	}

	cout << "\n";

	output(line, list, n);
}

int main() {
	int n = 0; 
	cout << "Input number of tourists = "; 
	cin >> n;
	hotel* list = new hotel[n];

	input(list, n);

	return 0;
}


