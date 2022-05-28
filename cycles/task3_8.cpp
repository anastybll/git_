#include <iostream>
#include <cmath>

using namespace std;

int main() 
{
    int N, i = 1, t = 0, n;
    cout << "N = ";
    cin >> N;
    while (i <= N) 
    {
        n = t + i + (i - 1); //выражение для нахождения квадрата числа
        t = n;
        cout << "i = " << i << " N^2 = " << n << endl;
        i++;
    }
}
