//Реализовать функции для работы с датой: определение количества прошедших дней, определение даты через N дней, 
// корректность даты, определение дня недели.

#include <iostream>
#include <string>

using namespace std;

struct dates 
{
	int day, month, year;
	int day_leave, month_leave, year_leave;
	bool vis, vis_leave;
};

void check_week_day(dates* date)
{
	int code_day = date[0].day;
	int code_year = ((date[0].year % 100) / 4 + date[0].year % 100) % 7 + (20 - date[0].year / 100);
	int code_month = 0;
	
	switch (date[0].month)
	{
	case 1: code_month = 6 - date[0].vis; break;
	case 2: code_month = 2 - date[0].vis; break;
	case 3: code_month = 2; break;
	case 4: code_month = 5; break;
	case 5: code_month = 0; break;
	case 6: code_month = 3; break;
	case 7: code_month = 5; break;
	case 8: code_month = 1; break;
	case 9: code_month = 4; break;
	case 10: code_month = 6; break;
	case 11: code_month = 2; break;
	case 12: code_month = 4; break;
	}

	switch ((code_day + code_month + code_year) % 7)
	{
	case 0: cout << "Sunday\n"; break;
	case 1: cout << "Monday\n"; break;
	case 2: cout << "Tuesday\n"; break;
	case 3: cout << "Wednesday\n"; break;
	case 4: cout << "Thursday\n"; break;
	case 5: cout << "Friday\n"; break;
	case 6: cout << "Saturday\n"; break;
	}
}

void add_day(dates* date) // для точности даты, добавляем +1 день к дате
{
	date[0].day += 1;
	switch (date[0].month)
	{
	case 1: case 3: case 5: case 7: case 8: case 10: case 12:
		if (date[0].day > 31) 
		{
			date[0].month += 1;
			date[0].day = 1;
		}
		if (date[0].month == 13) 
		{
			date[0].month = 1;
			date[0].year += 1;
			date[0].vis = ((!(date[0].year % 4) && (date[0].year % 100)) || !(date[0].year % 400));
		}
		break;
	case 4: case 6: case 9: case 11:
		if (date[0].day > 30) 
		{
			date[0].month += 1;
			date[0].day = 1;
		}
		break;

	case 2:
		if (date[0].day > 28 + date[0].vis)
		{
			date[0].month += 1;
			date[0].day = 1;
		}
		break;
	}
}

bool check_correct(string line, dates* date, bool flag) // проверка на корректность даты
{
	bool correct_format, correct_date = false;
	int day, month, year;

	correct_format = (line.length() == 10 && isdigit(line[0]) && isdigit(line[1]) && isdigit(line[3]) && isdigit(line[4]) && isdigit(line[6]) && isdigit(line[7]) && isdigit(line[8]) && isdigit(line[9]) && line[2] == '.' && line[5] == '.');
	if (correct_format) 
	{
		day = int(line[0] - '0') * 10 + int(line[1] - '0');
		month = int(line[3] - '0') * 10 + int(line[4] - '0');
		year = int(line[6] - '0') * 1000 + int(line[7] - '0') * 100 + int(line[8] - '0') * 10 + int(line[9] - '0');
		bool vis = ((!(year % 4) && (year % 100)) || !(year % 400));
		switch (month) {
		case 1: case 3: case 5: case 7: case 8: case 10: case 12: correct_date = (day >= 1 && day <= 31); break;
		case 4: case 6: case 9: case 11: correct_date = (day >= 1 && day <= 30); break;
		case 2: correct_date = (vis ? (day >= 1 && day <= 29) : (day >= 1 && day <= 28)); break;
		}

		if (correct_date && flag)
		{
			date[0].day = day;
			date[0].month = month;
			date[0].year = year;
			date[0].vis = vis;
		}
		else if (correct_date && !flag) 
		{
			date[0].day_leave = day;
			date[0].month_leave = month;
			date[0].year_leave = year;
			date[0].vis_leave = vis;
		}
	}

	return correct_date;
}

void input_1(dates* date) // функция для первого вопроса
{
	string line = "";
	getline(cin, line);
	int n = 0;

	while (true)
	{
		cout << "Input first date: "; 
		getline(cin, line);
		if (check_correct(line, date, true)) // проверка на корректность
			break;
		else
			cout << "Incorrect date!\n";
	}

	while (true) {
		cout << "Input second date: ";
		getline(cin, line);
		if (check_correct(line, date, false)) // проверка на корректность
			break;
		else
			cout << "Incorrect date!\n";
	}
	// вызываем функцию для опредедения кол-ва прошедших дней
	while (!(date[0].day == date[0].day_leave && date[0].month == date[0].month_leave && date[0].year == date[0].year_leave && date[0].vis == date[0].vis_leave)) 
	{
		add_day(date);
		n++;
	}

	cout << n << " days left\n";
}

void input_2(dates* date) // функция для второго вопроса
{
	string line = "";
	getline(cin, line);

	while (true)
	{
		cout << "Input date: ";
		getline(cin, line);
		if (check_correct(line, date, true)) // проверка на корректность даты
			break;
		else
			cout << "Incorrect date!\n";
	}

	int n = 0; 
	cout << "Input the number of days: "; // день n
	cin >> n;

	for (int i = 0; i < n; ++i)
		add_day(date);

	cout << (date[0].day < 10 ? "0" : "") << date[0].day << "." << (date[0].month < 10 ? "0" : "") << date[0].month << "." << date[0].year << "\n";
}

void input_3(dates* date) // функция для третьего вопроса
{
	string line = "";
	getline(cin, line);


	while (true) 
	{
		cout << "Input date: "; 
		getline(cin, line);
		if (check_correct(line, date, true)) // проверка на корректность даты
			break;
		else
			cout << "Incorrect date!\n";
	}

	check_week_day(date);
}

int main()
{
	setlocale(LC_ALL, "rus");
	cout << "1 - определение количества прошедших дней\n";
	cout << "2 - определение даты через N дней\n";
	cout << "3 - определение дня недели\n";
	int x = 0; 
	cout << "Введите цифру: ";
	cin >> x;
	dates* date = new dates[1];

	switch (x) // вызываем нужную функцию в зависимости от выбора
	{
	case 1: input_1(date); break;
	case 2: input_2(date); break;
	case 3: input_3(date); break;
	}

	return 0;
}