//������� ���������� ������, ���������� ����� �����. ������� ��� ������ �����.

#include <iostream>

using namespace std;

struct list // ��������� ���������� ������
{ 
    int inf;
    list* next;
    list* prev;
};

void push(list*& h, list*& t, int x) // ������� �������� � ����� ������
{ 
    list* r = new list; // ������� ����� �������
    r->inf = x;
    r->next = NULL; // ������ ���������
    if (!h && !t) // ���� ������ ����
    {
        r->prev = NULL; // �� ������ ������� 
        h = r; // ��� ������
    }
    else
    {
        t->next = r; // r -  ��������� ��� ������
        r->prev = t; // ����� - ���������� ��� r
    }
    t = r; //  r �����
}

void print(list* h, list* t) //������� ������
{ 
    list* p = h; // ��������� �� ������
    while (p) //  ���� �� ����� �� ����� ������
    {
        cout << p->inf << " ";
        p = p->next; // ������� � ���������� ��������
    }
}

void del_node(list*& h, list*& t, list* r) //������� ���� �� ������ 
{ 
    if (r == h && r == t) // ���� ������������ ������� ������
        h = t = NULL;

    else if (r == h) // ������� ������ ������
    {
        h = h->next; // �����
        h->prev = NULL;
    }

    else if (r == t) // ������� ����� ������
    {
        t = t->prev; // �����
        t->next = NULL;
    }

    else
    {
        r->next->prev = r->prev; // ��� ���������� �� r ���������� ���������� r->prev

        r->prev->next = r->next; //��� ����������� �� r ��������� ���������� r->next
    }
    delete r; //  ������� r
}

void task(list*& h, list*& t) // ������� ��� �������� ���� ������ ����� �� ������
{ 
    list* p = h; 
    list* n;
    while (p)
    {
        n = p->next;
        if (p->inf % 2 == 0)
            del_node(h, t, p);
        p = n;
    }
}

int main()
{
    int n;
    cout << "n = ";
    cin >> n;

    list* h = NULL;
    list* t = NULL;

    int x;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        push(h, t, x);
    }
    task(h, t);
    print(h, t);

    return 0;
}

