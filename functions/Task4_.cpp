//18. ��������� ����������� �������, ���������� ��������� �������
#include <iostream>

using namespace std;

void f(const char c = 'A', const int step = 1) 
{
    for (int i = 'A'; i <= 'A' + 4 * ('Z' - 'A'); i++) // ������� ��� �������� �������
        cout << ((i > c && i < 2 * 'Z' - c) || (i > 2 * ('Z' - 'A') + c && i < 4 * 'Z' - 2 * 'A' - c) ? '-' : c);
    cout << endl;

    if (c == 'Z') // ������� ��� �������� �������
        f(c - 1, -1);
    else if (c != 'A' || step != -1) // ����������� ������ ��������� �������
        f(c + step, step);
}

int main()
{
    f(); // ����� �������
}