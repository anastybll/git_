//  Построить треугольник Паскаля. Используя треугольник Паскаля, вычислить 2 в степени 𝑘.
#include <iostream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "rus");
    int a[30][30], n, i, g,m, l=0;
    cout << "n = ";
    cin >> n;
    n = n + 1;
    // заполняем массив 1
    for (i = 0; i < 30; i++) {
        a[0][i] = 1;
        a[i][0] = 1;
    }
    // заполняем массив остальными эл-ми
    for (i = 1; i < n; i++)
        for (g = 1; g < n; g++)
            a[i][g] = a[i - 1][g] + a[i][g - 1];
    //вывод
    for (g = 0; g <= n - 1; g++)
    {
        cout << a[g][n - 1 - g] <<' ';
        l += a[g][n - 1 - g];
    }
    cout << endl;
    cout << l << ' ';
    cout << endl;
   
}
