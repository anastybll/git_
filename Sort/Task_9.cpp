// 9. Сначала по году рождения, потом по стажу работы с помощью сортировки расческой.

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

ifstream in("input.txt");
ofstream out("output.txt");

struct date { // дата
	int dd, mm, yy;
};

struct people { // информация о людях
	string surname;
	string post;
	date dateofbirth;
	int experience;
	int salary;
};

date Str_to_date(string str) { // превращаем дату к нужному виду
	date x;
	string temp = str.substr(0, 2);
	x.dd = atoi(temp.c_str());
	temp = str.substr(3, 2);
	x.mm = atoi(temp.c_str());
	temp = str.substr(6, 4);
	x.yy = atoi(temp.c_str());
	return x;
}

vector<people> inFile() { // ввод из файла
	vector<people>x;
	people temp;
	while (in.peek() != EOF) {
		in >> temp.surname;
		in >> temp.post;
		string tmp;
		in >> tmp;
		temp.dateofbirth = Str_to_date(tmp);
		in >> temp.experience;
		in >> temp.salary;
		x.push_back(temp);
	}
	return x;
}

void print(people x) { // функция для вывода в файл
	out << x.surname << " " << x.post << " ";

	if (x.dateofbirth.dd < 10)
		out << "0" << x.dateofbirth.dd << ".";
	else
		out << x.dateofbirth.dd << ".";

	if (x.dateofbirth.mm < 10)
		out << "0" << x.dateofbirth.mm << ".";
	else
		out << x.dateofbirth.mm << ".";

	if (x.dateofbirth.yy < 10)
		out << "0" << x.dateofbirth.yy << " ";
	else
		out << x.dateofbirth.yy << " ";

	out << x.experience << " " << x.salary << endl;
}

bool operator<(people a, people b) {
	if (a.dateofbirth.yy < b.dateofbirth.yy) return true;
	if (a.dateofbirth.yy == b.dateofbirth.yy && a.experience < b.experience) return true;
	return false;
}

void sorting(vector<people>& x) { // сортировка подсчетом и вывод данных в фыйл
	double factor = 1.2473309;
	int step = x.size() - 1;
	while (step >= 1) {
		for (int i = 0; i + step < x.size();i++) {
			if (x[i].dateofbirth.yy > x[i + step].dateofbirth.yy)
				swap(x[i], x[i + step]);
			else if (x[i].dateofbirth.yy == x[i + step].dateofbirth.yy && x[i].experience > x[i + 1].experience)
				swap(x[i], x[i + step]);
			else if ((x[i].dateofbirth.yy == x[i+1].dateofbirth.yy && x[i].experience >x[i+1].experience) || (x[i].dateofbirth.yy >  x[i+1].dateofbirth.yy))
				swap(x[i], x[i + step]);
			
		}
		step /= factor;
	}

	for (vector<people>::iterator iter = x.begin(); iter != x.end(); iter++) {
		people temp = *iter;
		if (temp.surname != "")
			print(temp);
	}
}

int main() { // вызываем функции ввода и сортировки
	setlocale(LC_ALL, "rus");
	vector<people>x = inFile();
	sorting(x);
	return 0;
}