#include<iostream>
#include<cmath>

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	int A, X, Y;
	cout << " ������� ����������� ����� A = ";
	cin >> A;
	cout << " ������� ����������� ����� X = ";
	cin >> X;
	cout << " ������� ����������� ����� Y = ";
	cin >> Y;
	// ������ �� ������
	if (A < 100 || A > 999 || X <= 0 || X > 9 || Y <= 0 || Y > 9)
	{
		cout << "������������ ���� ������";
	}
	else {
		int a = A / 100; // ������ ����� ����� �
		int b = (A % 100) / 10; // ������ ����� ����� A
		int c = (A % 100) % 10; // ������ ����� ����� A
		int sum = a + b + c; // ����� ���� ���� ����� A

		int an, bn, cn, res;
		if (sum % X == 0 && sum % Y == 0) {
			an = abs(a - 5);
			bn = abs(b - 5);
			cn = abs(c - 5);
		}

		else if (sum % X == 0 && sum % Y != 0) {
			an = a * 2 % 10;
			bn = b * 2 % 10;
			cn = c * 2 % 10;
		}
		else if (sum % X != 0 && sum % Y == 0) {
			an = (a + 1) % 10;
			bn = (b + 1) % 10;
			cn = (c + 1) % 10;
		}
		else {
			an = abs(a - 1);
			bn = abs(b - 1);
			cn = abs(c - 1);
		}
		res = an * 100 + bn * 10 + cn;
		cout << " ��������� = " << res << endl;
	}
}
	
