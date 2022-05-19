//���� ��������� ����� � ������������. ����� ����� �����, ��� ��� ������� R, �������� ���������� ���������� �����.

#include <iostream>
#include <cmath>

using namespace std;

struct point // ��������� ����� � ������������
{
	int x, y, z;
};

void solve(point* list, int n)
{
	for (int i = 0; i < n; ++i) // ���� �� ������� �����
	{
		cout << "Point " << i + 1 << "\nInput x, y, z: "; // ������ ���������� x y z
		cin >> list[i].x >> list[i].y >> list[i].z; cout << "\n";
	}

	int r = 0;
	cout << "Input R = "; // ������ ������ ����������
	cin >> r;
	cout << "\n";

	int max_num = 0; // ��������� ��� ����������� ������������ �����
	int* count = new int[n]; // ������� ������ ��� ������ ��������� �����

	for (int i = 0; i < n; ++i)
		count[i] = 0;

	for (int i = 0; i < n; ++i) // ���������� �� ���� ������ (�� ������ ����� ������� ������ � ������� ������� �������� �����)
		for (int j = 0; j < n; ++j)
			if ((list[i].x - list[j].x) * (list[i].x - list[j].x) + (list[i].y - list[j].y) * (list[i].y - list[j].y) + (list[i].z - list[j].z) * (list[i].z - list[j].z) <= r * r)
				count[i] += 1;

	for (int i = 0; i < n; ++i) // ���������� ���-�� �������� �����
		if (count[i] > max_num)
			max_num = count[i];

	cout << "answer: \n"; // ����� ������
	
	for (int i = 0; i < n; ++i) // ����� �����
		if (count[i] == max_num)
			cout << "point " << i + 1 << " (" << list[i].x << ", " << list[i].y << ", " << list[i].z << ")\n";


}

int main() {
	int n = 0;
	cout << "Input n = "; // ������ ����-�� �����
	cin >> n;

	point* list = new point[n]; // ������� ������ ��� ���� �����

	solve(list, n); // �������� �������

	return 0;
}

/*
* 3
* 0 0 0
* 1 1 1
* 2 2 2
* 2
*/