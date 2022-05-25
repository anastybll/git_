//11. Ќайти все слова, встречающиес€ столько же раз, сколько первое число
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

bool IsNumber(const string& str) //провер€ет €вл€етс€ ли строка числом
{ 
	return all_of(str.begin(), str.end(), [](const char& c)
		{ return isdigit(c); });
}

int main()
{
	setlocale(LC_ALL, "rus");
	ifstream file("text3.txt");
	map<string, int> mpp;
	string str;
	bool flag = true;
	int first_digit;
	while (file.peek() != EOF)
	{
		getline(file, str, ' ');
		if (flag && IsNumber(str))
		{
			first_digit = stoi(str);
			flag = false;
		}
		if (!IsNumber(str))
		{
			map<string, int>::iterator iter = mpp.find(str);
			if (iter == mpp.end())
				mpp.insert(make_pair(str, 1));
			else
				iter->second += 1;
		}
	}
	for (map<string, int>::iterator iter = mpp.begin(); iter != mpp.end(); iter++)
	{
		cout << "слово: " << iter->first << " входит в файл: " << iter->second <<" раз" << endl;
	}
	cout << endl;
	for (map<string, int>::iterator iter = mpp.begin(); iter != mpp.end(); iter++)
	{
		if (iter->second == first_digit)
			cout << "слово: " << iter->first << " встречаетс€ " << first_digit << " раз" << endl;
	}
	cout << endl;
	return 0;
}