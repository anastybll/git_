//1. �������� ����������� �������, ����������� ��������� �����.
#include<iostream>

using namespace std;

long double factorial(int n)
{
    if (n < 0) // ���� ����� ������������� �����
        return 0; // ���������� ����
    if (n == 0) // ���� ����� ����,
        return 1; // ���������� ��������� �� ���� ��� 1 
    else // �� ���� ��������� �������
        return n * factorial(n - 1); // ������ ��������
}

int main()
{
    int n;
    setlocale(LC_ALL,"rus");
    cout << "������� ����� ��� ���������� ����������: ";
    cin >> n;
    cout << "��������� ��� ����� " << n << " = " << factorial(n) << endl; // ������� ��� ���������� ���������
    return 0;
}
