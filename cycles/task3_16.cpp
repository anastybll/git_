#include<iostream>

using namespace std;

 int main()
 {
 const int N = 4; //����� ������
 for (int i = 1; i <= N; i++) //�����
 {
	 for (int j = 1; j <= i; j++)
		 cout << i << " ";
	 cout << endl;
	 for (int j = 1; j <= i; j++)
		 cout << i * 2 << " ";
	 cout << endl;
 }
 }

