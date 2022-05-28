#include<iostream>
#include<cmath>

using namespace std;

int main()
{
    int n;
    cout << "n = ";
    cin >> n;
    for (int i = 2; i <= n; i++)
        for (int j = 2; j <= i; j++)
        {// проверка на простое число
            if (i % j == 0)
                break;
            else if (i == j + 1)
                cout << i << " ";
        }
}

