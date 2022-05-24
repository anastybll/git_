// �������� �����������, �������� � �������� �����������, ��������������� � ����� ��������� �� ����

#include <iostream>
#include <fstream>
#include <vector>
#include <math.h>

using namespace std;

ifstream in("input.txt");
ofstream out("output.txt");

struct date // ����
{ 
    int dd, mm, yy;
};

struct people // ������ � ��������
{
    string Surname;
    string Post;
    date DateOfBirth;
    int Experience;
    int Salary;
};

struct list // ���������� ������
{
    people inf;
    list* next;
    list* prev;
};

struct HashTable // ��� ������, � ������� �������� ���-��� � ������ � ����������� 
{ 
    list* h = NULL;
    list* t = NULL;
};

void push(list*& h, list*& t, people x) // ������� ��������� ������� � ����� ��. ������
{ 
    list* r = new list;
    r->inf = x;
    r->next = NULL;
    if (!h && !t)
    {
        r->prev = NULL;
        h = r;
    }
    else
    {
        t->next = r;
        r->prev = t;
    }
    t = r;
}

void print(list* h, list* t) // ������� ������� ��. ������
{ 
    list* p = h;
    while (p)
    {
        cout << p->inf.DateOfBirth.yy << " ";
        p = p->next;
    }
}

date StrToDate(string str) // ����������� ������ � ����� � date
{
    date ans;
    string tmp = str.substr(0, 2);
    ans.dd = atoi(tmp.c_str());
    tmp = str.substr(3, 2);
    ans.mm = atoi(tmp.c_str());
    tmp = str.substr(6, 4);
    ans.yy = atoi(tmp.c_str());
    return ans;
}

vector<people> inFile() // ���� ������ �� �����
{ 
    vector<people> x;
    people temp;
    while (in.peek() != EOF)
    {
        in >> temp.Surname >> temp.Post;
        string tmp;
        in >> tmp;
        temp.DateOfBirth = StrToDate(tmp);
        in >> temp.Experience;
        in >> temp.Salary;
        x.push_back(temp);
    }
    return x;
}

int HashFunction(int k, int sizeOfTable)
{
    int N = 16;
    double A = 0.618033;
    int h = sizeOfTable * fmod(k * A, 1);
    return h;
}

HashTable* def(vector<people> x, int sizeOfTable) //����������� �������
{ 
    HashTable* table = new HashTable[sizeOfTable];
    int cod = 0;
    for (int i = 0; i < 20; i++) //���������� �������
    {
        cod = HashFunction(x[i].DateOfBirth.yy, sizeOfTable);
        while (cod < sizeOfTable)
        {
            if (!table[cod].h)
            {
                push(table[cod].h, table[cod].t, x[i]);
                break;
            }
            else
                cod++;
        }
    }
    return table;
}

void printTable(HashTable* table, int sizeOfTable)  // ����� �������
{
    for (int i = 0; i < sizeOfTable; i++, cout << endl)
    {
        cout << "Hash code " << i << " : ";
        print(table[i].h, table[i].t);
    }
}

void print_p(people tmp)  // ������� ������ � �������� � out
{
    cout << tmp.Surname << " " << tmp.Post << " ";

    if (tmp.DateOfBirth.dd < 10)
        cout << "0" << tmp.DateOfBirth.dd << ".";
    else
        cout << tmp.DateOfBirth.dd << ".";

    if (tmp.DateOfBirth.mm < 10)
        cout << "0" << tmp.DateOfBirth.mm << ".";
    else
        cout << tmp.DateOfBirth.mm << ".";

    if (tmp.DateOfBirth.yy < 10)
        cout << "0" << tmp.DateOfBirth.yy << " ";
    else
        cout << tmp.DateOfBirth.yy << " ";

    cout << tmp.Experience << " " << tmp.Salary << endl;
}

void find(int y, HashTable*& table, int sizeOfTable)  // ������� ������ �������� � �������
{
    int cod = HashFunction(y, sizeOfTable);
    list* p = table[cod].h;
    while (true)
    {
        list* b = table[cod].h;
        if (b->inf.DateOfBirth.yy == y)
        {
            print_p(b->inf);
        }
        cod++;
    }
}

int main()
{
    setlocale(LC_ALL, "rus");
    vector<people> x = inFile();
    int sizeOfTable;
    cout << "Size of table: ";
    cin >> sizeOfTable;
    HashTable* table = def(x, sizeOfTable);
    cout << "Ititial hash table:" << endl;
    printTable(table, sizeOfTable);
    int y;
    cout << "y = ";
    cin >> y;
    find(y, table, sizeOfTable);
    return 0;
}