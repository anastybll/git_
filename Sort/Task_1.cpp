// 2. По году рождения с помощью сортировки подсчетом.

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

void sorting(vector<people>& x) { // сортировка подсчетом и вывод данных в фыйл
	vector<vector<people>> counting(100);
	for (vector<people>::iterator iter = x.begin();iter != x.end(); iter++) {
		people p = *iter;
		counting[p.dateofbirth.yy].push_back(p);
	}
	int n = x.size();
	x.clear();
	x.resize(n);
	for (vector<vector<people>>::iterator iter = counting.begin();iter != counting.end();iter++) {
		vector<people> temp = *iter;
		for (vector<people>::iterator iter1 = temp.begin(); iter1 != temp.end(); iter1++)
		{
			people p = *iter1;
			x.push_back(p);
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