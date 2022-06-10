#include<iostream>;
#include<cmath>;

using namespace std;

int main() {
	setlocale(LC_ALL, "rus");
	float a1, b1, c1, a2, b2, c2,l,m,t1,t2;
	const float eps = 0.00001;
	cout << "a1 = ";
	cin >> a1;
	cout << "b1 = ";
	cin >> b1;
	cout << "c1 = ";
	cin >> c1;
	cout << "a2 = ";
	cin >> a2;
	cout << "b2 = ";
	cin >> b2;
	cout << "c2 = ";
	cin >> c2;

	l = sqrt(pow(a1, 2) + pow(b1, 2)); // ��������� ��� �������� ������� ��������� 
	m = sqrt(pow(a2, 2) + pow(b2, 2)); // ��������� ��� �������� ������� ���������

	if ((l < eps) && (m < eps)) // �������� ���� ���������
	{
		cout << "�� ������" << endl;
	}
	else if (l < eps) // �������� ������ ���������
	{
		cout << "1 - �� ������" << endl;
	}
	else if (m < eps) // �������� ������� ���������
	{
		cout << "2-�� ������" << endl;
	}
	else if ((abs(a1 * b2) - abs(a2 * b1) == 0)&&((a1 / a2) != (b1 / b2) || ((a1 / a2) != (c1 / c2)) || ((b1 / b2) != (c1 / c2)))) // ��������� �������������� ������
	{
		cout << "�����������" << endl;
	}
	else if ((a1 / a2) == (b1 / b2) && ((a1 / a2) == (c1 / c2))) // ��������� ��������� �� ������
	{
		cout << "���������" << endl;
	}
	else {
		t1 = ((-c1 * b2) - (b1 * (-c2))) / ((a1 * b2) - (a2 * b1)); // ����� ����������� 
		t2 = ((a1 * (-c2)) - (-c1 * a2)) / ((a1 * b2) - (a2 * b1));
		
		cout << "������������" << endl;
		cout << t1 << endl;
		cout << t2 << endl;

	}
}

