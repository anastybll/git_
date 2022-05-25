// 2. Дана последовательность целых чисел. Найти все такие цифры, которые встречаются в двузначных числах, 
// но не встречаются в трехзначных.

#include <iostream>
#include <set>
#include <algorithm>
#include <iterator>

using namespace std;

set <int> set_n(int n)
{
    set <int> S;
    while (n != 0) 
    {
        S.insert(n % 10);
        n /= 10;
    }
    return S;
}

int main() 
{
    setlocale(LC_ALL,"rus");
    set <int> s1, s0, s, res;
    int n, a;
    cout << "n=";
    cin >> n;
    

    cout << "Введите числа" << endl;
    for (int i = 0; i < n; i++) {
        cout << "a[" << i << "]=";
        cin >> a;
        s = set_n(a);
        if (a > 99 && a <= 999) // условие
            s0.insert(s.begin(), s.end());
        if (a > 9 && a <= 99)
            s1.insert(s.begin(), s.end());
    }

    set_difference(s1.begin(), s1.end(), s0.begin(), s0.end(), inserter(res, res.begin()));
    cout << "цифры, которые встречаются в двузначных числах, но не встречаются в трехзначных:" << endl; // вывод
    for (set<int>::iterator it = res.begin(); it != res.end(); it++)
        cout << *it << " ";
    system("pause");
    return 0;
}