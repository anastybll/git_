// 15. Сначала по фамилии, потом по стажу работы, потом по году рождения с помощью сортировки вставками.

#include<iostream>
#include<fstream>
#include<iomanip>
#include<vector>
#include<string>

using namespace std;

ifstream in("input.txt");
ofstream out("output.txt");

struct date {
	int dd, mm, yy;
};

struct people {
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
	if (a.surname < b.surname) return true;
	if (a.surname == b.surname && a.experience < b.experience) return true;
	if (a.surname == b.surname && a.experience == b.experience && a.dateofbirth.yy < b.dateofbirth.yy) return true;
	return false;
}

void sorting(vector<people>& x) { // сортировка подсчетом и вывод данных в фыйл
	for (int i = 1; i <= x.size() - 1; i++) {
		int j = i;
		while (j > 0 && x[j] < x[j - 1]) {
			swap(x[j], x[j - 1]);
			j--;
		}
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
