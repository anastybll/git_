//Дан многочлен 𝑃(𝑥) степени 𝑛. Получить его производную 𝑃′(𝑥)

#include <iostream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "rus");
    int a[30][30], i, g, n; // делаем размерность пирамиды
    cout << "n =  ";
    cin >> n;
    n = n + 1;

    cout << endl;
    // заполняем массив 1
    for (i = 0; i < 30; i++) 
    {
        a[0][i] = 1; 
        a[i][0] = 1;
    }
    // заполняем массив остальными эл-ми
    for (i = 1; i < n; i++)
        for (g = 1; g < n; g++)
            a[i][g] = a[i - 1][g] + a[i][g - 1];

    for (g = 0; g <= n - 1; g++) 
    {
        cout << a[g][n - 1 - g] << ' ';
    }
    cout << endl;
   
    // вывод 
    for (g = 0; g <= n - 1; g++)
    {
        if (g != 0)
            cout << g * a[g][n - 1 - g] << ' ';
    }
    cout << endl;
}
