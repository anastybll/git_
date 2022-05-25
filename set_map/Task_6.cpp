// ƒан текст, состо€щий из предложений, разделенных знаками препинани€ из набора Ђ. ? !ї.
// ѕредложени€ в свою очередь состо€т из слов, отделенных друг от друга пробелами.
// Ќайти слова(без учета регистра) и их количество, которые не встречаютс€ ни в вопросительных, ни в восклицательных предложени€х.
#include <map>
#include <set>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
#include <iostream>

using namespace std;

set<string> other;
set<string> every; // будем помещать слова из предложени€
map<string, int> number;

void def_1(string str, char ch) {
	string new_str = "";
	for (string::size_type i = 0; i < str.length(); ++i)
		if (isupper(str[i]))
			new_str += tolower(str[i]); // дл€ букв
		else
			new_str += str[i];

	str = new_str;
	bool flag = true; 
	for (string::size_type pos = 0; pos < str.length(); pos = str.find(' ', pos + 1)) {
		if (!flag)
			pos++;
		flag = false;
		every.insert(str.substr(pos, str.find(' ', pos) - pos));
		number[str.substr(pos, str.find(' ', pos) - pos)]++;
		switch (ch) {
		case '!': case '?': other.insert(str.substr(pos, str.find(' ', pos) - pos)); break;
		}
	}
}


int main() {
	vector<string> dif;

	string str = "";
	cout << "Input string: "; // ввод строки
	getline(cin, str);
	string::size_type pos = 0, pos1 = str.find_first_of(".!?", pos);
	while (pos1 < str.length()) {
		def_1(str.substr(pos, pos1 - pos), str[pos1]);
		pos = pos1 + 2;
		pos1 = str.find_first_of(".!?", pos);
	}

	dif.resize(every.size());

	vector<string>::iterator res = set_difference(every.begin(), every.end(), other.begin(), other.end(), dif.begin());
	cout << "Answer:\n"; for (vector<string>::iterator it = dif.begin(); it != res; cout << *it << ": " << number[*it] << " times\n", ++it);

	return 0;
}

