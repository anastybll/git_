#include<iostream>;
#include<cmath>;

using namespace std;

int main() {
	setlocale(LC_ALL,"rus");
	float x;
	cout << "������� �������� x = ";
	cin >> x;
	const float eps = 0.00001;
	//��������� ���
	if (x < -5) {
		cout << "������ �� �������������� �����";
	}
	else if (x > 4 || abs(x - 4) < eps) {
		cout << "�������� �������������� �����";
	}
	else if ((x + 1) < eps) {
		cout << "������� �� ����";
	}
	else { //������� ����������
		float F = (sqrt(x + 5) + log(8 - 2 * x)) / (x + 1);
		cout << "F = " << F << endl;
	}
}
