//7. Создайте функцию, которая для заданных 𝑛 и 𝑚 (1 ≤ 𝑛 ≤ 𝑚) 
//вычисляет количество всех различных размещений из 𝑚 элементов по 𝑛, используя рекуррентное соотношение
#include <iostream>

using namespace std;

int funct(int n, int m) 
{
    if (n == 1) // условие для рекуррентного соотношения
        return m;
    if (n > 1)
        return funct(n - 1, m) * (m - n + 1);// рекуррентное соотношение
    
}

int main()
{
    int n, m;
    cout << "m = "; 
    cin >> m;
    cout << "n = ";
    cin >> n;

    if (n > m) cout << "invalid input" << endl;
    else
        cout << funct(n, m) << endl; // вызов функции 
    return 0;
}
