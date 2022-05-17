// сортировка подсчетом MSD

#include <iostream>
#include <vector>
#include <stack>
#include <time.h>
#include <algorithm>
#include <numeric>

using namespace std;

void print(vector<int> vec) 
{
	for (vector<int>::iterator iter = vec.begin(); iter != vec.end(); cout << *iter << " ", ++iter); cout << "\n";
}

vector<int> create_vector(int n)
{
	vector<int> vec;
	for (int i = 0; i < n; vec.push_back(rand() % 10000), ++i);
	print(vec);
	return vec;
}

void sort(vector<int>& vec, int k_10, int n) 
{
	//Рекурсивно выполняем данную функцию, пока не отсортируем все подвекторы вектора data
	vector<vector<int>> box;
	box.resize(10);
	for (int j = 0; j < n; ++j)
		box[(vec[j] / k_10) % 10].push_back(vec[j]);
	for (int i = 0; i < 10; ++i)
		if (box[i].size() > 1)
			sort(box[i], k_10 / 10, box[i].size());
	vec.clear();

	for (int j = 0; j < 10; ++j)
	{
		for (vector<int>::iterator iter = box[j].begin(); iter != box[j].end(); vec.push_back(*iter), ++iter);
		box[j].clear();
	}
}

void MSD(vector<int>& vec, int n) 
{
	//Макc число
	int mx = 0;
	for (int i = 0; i < n; mx = max(mx, vec[i]), ++i);

	//Макс разряд 
	int k = 0;
	for (int i = 0; mx > 0; ++k, ++i)
		mx /= 10;

	//10^k
	int k_10 = 1;
	for (int i = 0; i < k - 1; k_10 *= 10, ++i);
	sort(vec, k_10, n);
}

int main() 
{
	srand(time(0));
	int n = 0;
	cout << "n = ";
	cin >> n;
	vector<int> vec = create_vector(n);
	MSD(vec, n);
	print(vec);
}
