//7. ���� ������������������ ����� �����. ������� ��� ������ ��������. 
//�������� ��� ������������ �������� �� �����������. ����� ���������� ���������, ������� ??.

#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>

using namespace std;

bool odd(int x) // �������� �� ������� ������
{ 
	return x % 2 == 0;
}

int x=1; 
bool kratn(int y) // ������ �� y x
{ 
	return y % x == 0;
}

bool nekratn(int y) // �� ������ �� y X
{ 
	return y % x!= 0;
}

int main() 
{
	setlocale(LC_ALL, "rus");
	int n, i;
	cout << "n= ";
	cin >> n;

	vector<int>v; // �������� �������
	for (int i = 0; i < n; i++) // ���������� ������� ����������
		v.push_back(rand()%10);

	for (int i = 0; i < v.size(); i++)//����� � ������� �������
		cout << v[i] << " ";
	cout << endl;

	
	cout << "�������� ���� ������ ���������:" << endl;
	vector<int>v1(v); // ������� ����� ������� v, ��� ���������� ��������
	vector<int>::iterator it = remove_if(v1.begin(), v1.end(), odd);
	v1.erase(it, v1.end()); // �������� ������ ���������

	for (vector<int>::iterator iter = v1.begin(); iter != v1.end(); iter++) // ����� ��� ������ ���������
		cout << *iter << " ";
	cout << endl;


	cout << "������ Max �� Min:" << endl;
	v1 = v; // ����������� ������� v1 �������� ������� v
	int Max = *max_element(v1.begin(), v1.end()); // � ������� ������� ������� �������� � ������� � �������
	int Min = *min_element(v1.begin(), v1.end());
	replace(v1.begin(), v1.end(), Max, Min); // �������� �������� �� �������
	for (vector<int>::iterator iter = v1.begin(); iter != v1.end(); iter++) // ����� � �������
		cout << *iter<<" ";
	cout << endl;
	

	cout << "���-�� ������� X:" << endl;
	v1 = v; // ����������� ������� v1 �������� ������� v
	cout << "X = "; 
	cin>> x;
	int count = 0; // ���������� ��� ����������
	replace_if(v1.begin(), v1.end(), kratn, x); // ������ ������� �������� � �������� x, ���� ����� ������ x
	replace_if(v1.begin(), v1.end(), nekratn, 0); // ������ ������� �������� � 0, ���� ����� �������� 
	count = accumulate(v1.begin(), v1.end(), 0) / x; // ������� ����������
	cout << count << endl;
	return 0;
}