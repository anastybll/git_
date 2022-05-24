// открытое хеширование, метод деления по месяцу 

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

ifstream in("input.txt");
ofstream out("output.txt");

struct date //дата
{ 
    int dd, mm, yy;
};

struct people //данные о человеке
{ 
    string Surname;
    string Post;
    date DateOfBirth;
    int Experience;
    int Salary;
};

struct list //двусвязный список
{ 
    people inf;
    list* next;
    list* prev;
};

struct HashTable //тип данных, в котором хранится хеш-код и список с информацией
{ 
    list* h = NULL;
    list* t = NULL;
};

void push(list*& h, list*& t, people x) // функция добавляет элемент в конец дв. списка
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

void print(list* h, list* t) // функция выводит дв. список
{ 
    list* p = h;
    while (p)
    {
        cout << p->inf.DateOfBirth.mm << " ";
        p = p->next;
    }
}

void del_node(list*& h, list*& t, list* r) // функция удаляет узел из двусв. списка
{ 
    if (r == h && r == t)
        h = t = NULL;
    else if (r == h)
    {
        h = h->next;
        h->prev = NULL;
    }
    else if (r == t)
    {
        t = t->prev;
        t->next = NULL;
    }
    else
    {
        r->next->prev = r->prev;
        r->prev->next = r->next;
    }
    delete r;
}

date StrToDate(string str) // функция преобразует строку с датой в date
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

vector<people> inFile() //ввод данных из файла
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
    return k % sizeOfTable;
}

HashTable* def(vector<people> x, int sizeOfTable) //определение таблицы
{ 
    HashTable* table = new HashTable[sizeOfTable];
    int cod = 0;
    for (int i = 0; i < 20; i++) //заполнение таблицы
    { 
        cod = HashFunction(x[i].DateOfBirth.mm, sizeOfTable);

        push(table[cod].h, table[cod].t, x[i]);
    }
    return table;
}

void printTable(HashTable* table, int sizeOfTable) // функция вывода таблицы
{ 
    for (int i = 0; i < sizeOfTable; i++, cout << endl)
    {
        cout << "Hash code " << i << " : ";
        print(table[i].h, table[i].t);
    }
}

void del(int m, HashTable*& table, int sizeOfTable) // функция удаления элемента из таблицы
{ 
    int cod = HashFunction(m, sizeOfTable);
    list* p = table[cod].h;
    while (p)
    {
        if (p->inf.DateOfBirth.mm == m)
        {
            del_node(table[cod].h, table[cod].t, p);
            return;
        }
        p = p->next;
    }
}

list* find(int m, HashTable*& table, int sizeOfTable)  // функция поиска элемента в таблице
{
    int cod = HashFunction(m, sizeOfTable);
    list* p = table[cod].h;
    while (p)
    {
        if (p->inf.DateOfBirth.mm == m)
            return p;
        p = p->next;
    }
    return NULL;
}

void print_p(people tmp) //выводит данные о человеке в out
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

void printToOutput(HashTable*& table, int sizeOfTable)
{
    for (int i = 0; i < sizeOfTable; i++)
    {
        list* p = table[i].h;
        while (p)
        {
            people tmp = p->inf;
            out << tmp.Surname << " " << tmp.Post << " ";
            if (tmp.DateOfBirth.dd < 10)
                out << "0" << tmp.DateOfBirth.dd << ".";
            else
                out << tmp.DateOfBirth.dd << ".";

            if (tmp.DateOfBirth.mm < 10)
                out << "0" << tmp.DateOfBirth.mm << ".";
            else
                out << tmp.DateOfBirth.mm << ".";

            if (tmp.DateOfBirth.yy < 10)
                out << "0" << tmp.DateOfBirth.yy << " ";
            else
                out << tmp.DateOfBirth.yy << " ";
            out << tmp.Experience << " " << tmp.Salary << endl;
            p = p->next;
        }
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
    int m;
    cout << "m = ";
    cin >> m;
    if (!find(m, table, sizeOfTable))
        cout << "m is not found!" << endl;
    else
    {
        cout << "m is found!" << endl;
        list* p = find(m, table, sizeOfTable);
        while (p)
        {
            print_p(p->inf);
            del(m, table, sizeOfTable);
            p = find(m, table, sizeOfTable);
        }
    }
    cout << "After delete: " << endl;
    printTable(table, sizeOfTable);
    printToOutput(table, sizeOfTable);

    return 0;
}