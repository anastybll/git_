#include<iostream>;

using namespace std;

int main() {
	setlocale(LC_ALL, "rus");
	int a,b,c,h, r, S, P, selection;
	const double PI = 3.141592653589793; 
	// ������� ����
	cout << "�������� ��� ������" << endl <<
		"1. ����" << endl <<
		"2. �������" << endl <<
		"3. �����������" << endl << 
		"4. �������������" << endl;
	cin >> selection;
	// � ����������� �� ������ � ���� ������ ����������� ������ ��� ����������� ������� � ��������� 
	switch (selection)
	{
	case 1:
		cout << "������� ������ = ";
		cin >> r;
		// �������� �� ������ ���� ������
		if (r < 1) {
			cout << "������ ����� ������";
			break;
		}
		S = PI * r * r; // ���������� ������� ������
		P = 2 * PI * r; // ���������� �������� ������
		cout << "������� = " << S << endl;
		cout << "����� = " << P << endl;
		break;
	case 2:
		cout << "������� �������� ������� a = ";
		cin >> a;
		if (a < 1) {
			cout << "������ ����� ������";
			break;
		}
		S = a * a;
		P = 4 * a;
		cout << "������� = " << S << endl;
		cout << "�������� = " << P << endl;
		break;
	case 3:
		cout << "������� �������� ������� a = ";
		cin >> a;
		cout << "������� �������� ������� b = ";
		cin >> b;
		cout << "������� �������� ������� � = ";
		cin >> c;
		cout << "������� �������� ������ h = ";
		cin >> h;
		if (a < 1 || b < 1 || c < 1 || h < 1) {
			cout << "������ ����� ������";
			break;
		}
		S = 0.5 * a * h;
		P = a + b + c;
		cout << "������� = " << S << endl;
		cout << "�������� = " << P << endl;
		break;
	case 4:
		cout << "������� �������� ������� a = ";
		cin >> a;
		cout << "������� �������� ������� b = ";
		cin >> b;
		if (a < 1 || b < 1) {
			cout << "������ ����� ������";
			break;
		}
		S = a * b;
		P = 2 * (a + b);
		cout << "������� = " << S << endl;
		cout << "�������� = " << P << endl;
		break;

	default:
		cout << "������, ����� ���� �����������" << endl;
		break;
	}

}
