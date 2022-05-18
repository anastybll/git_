//12. ���� ��� ������������������ ����� �����.� ������ ������������������ ������� ��� ��������, ������� X.
//�� ������ � �������� ��������, ���������� � ��������[a, b] ������ Y.
//������������� ������ ������������������.���������� �� � ���� ��������������� ���������������c��.

#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>

using namespace std;

void output_vector(vector<int>v) // ������� ��� ������ �������� �� �����
{
	for (vector<int>::iterator iter = v.begin(); iter != v.end(); iter++) 
		cout << *iter << " ";
	cout << endl;
}

int x;
bool kratn(int y) // ������ �� ����� � �
{ 
	return y % x == 0;
}


int a, b;
bool interval(int y) // ������ �� ����� � ��������
{ 
	return y <= b && y >= a;
}


int main() 
{
	setlocale(LC_ALL, "rus");
	int n; 
	cout << "n = "; 
	cin >> n;

	cout << "������ ������:" << endl;
	vector<int>v1; // �������� ������� �������
	for (int i = 0; i < n; i++) // ���������� ������� ����������
		v1.push_back(rand()%10);
	output_vector(v1);
	cout << endl;


	cout << "������ ������:" << endl;
	vector<int>v2; // �������� ������� �������
	for (int i = 0; i < n; i++) // ���������� ������� ����������
		v2.push_back(rand()%10);
	output_vector(v2);
	cout << endl;


	cout << "� ������ ������� ��� ��������, ������� x:" << endl;
	cout << "x = ";
	cin >> x;

	vector<int>::iterator iter = remove_if(v1.begin(), v1.end(), kratn);
	v1.erase(iter, v1.end()); // ������� ������ ��������
	output_vector(v1);
	cout << endl;

	
	cout << "�� ������ �������� ��������, ���������� � [a, b] ������ y" << endl;
	int y;
	cout << "a = "; // ������ �������� � y
	cin >> a;
	cout << "b = ";
	cin >> b;
	cout << "y = ";
	cin >> y;

	replace_if(v2.begin(), v2.end(), interval, y); // ������
	output_vector(v2);
	cout << endl;

	// ����������
	cout << "��������� ������ ������: " << endl;
	sort(v1.begin(), v1.end());
	output_vector(v1);
	cout << "��������� ������ ������: " << endl;
	sort(v2.begin(), v2.end());
	output_vector(v2);
	cout << endl;

	
	cout << "����������� ��������: " << endl;
	vector<int> v3(v1.size() + v2.size());
	merge(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());
	output_vector(v3);
	return 0;
}