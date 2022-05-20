//Создать двусвязный список, содержащий целые числа. Отсортировать список, используя сортировку вставками.

#include <iostream>

using namespace std;

struct list // структура двусвязный список
{
    int inf;
    list* next;
    list* prev;
};

void push(list*& h, list*& t, int x) // вставка элемента в конец списка
{
    list* r = new list; // создаем новый элемент
    r->inf = x;
    r->next = NULL; // всегда последний
    if (!h && !t) // если список пуст
    {
        r->prev = NULL; // то первый элемент 
        h = r; // это голова
    }
    else
    {
        t->next = r; // r -  следующий для хвоста
        r->prev = t; // хвост - предыдущий для r
    }
    t = r; //  r хвост
}

void print(list* h, list* t) //выводит список
{
    list* p = h; // указатель на голову
    while (p) //  пока не дошли до конца списка
    {
        cout << p->inf << " ";
        p = p->next; // перехож к следующему элементу
    }
}

void del_node(list*& h, list*& t, list* r) //удаляет узел из списка 
{
    if (r == h && r == t) // если единственный элемент списка
        h = t = NULL;

    else if (r == h) // удаляем голову списка
    {
        h = h->next; // сдвиг
        h->prev = NULL;
    }

    else if (r == t) // удаляем хвост списка
    {
        t = t->prev; // сдвиг
        t->next = NULL;
    }

    else
    {
        r->next->prev = r->prev; // для следующего от r предыдущим становится r->prev

        r->prev->next = r->next; //для предыдущего от r следующим становится r->next
    }
    delete r; //  удаляем r
}

void insert_after(list*& h, list*& t, list* r, int y)
{ //вставляем после r в двусв. список
    list* p = new list;
    p->inf = y;
    if (r == t)
    {
        p->next = NULL;
        p->prev = r;
        r->next = p;
        t = p;
    }

    else
    {
        r->next->prev = p;
        p->next = r->next;
        p->prev = r;
        r->next = p;
    }
}

void insertionSort(list*& h, list*& t)
{ //сортировка вставками двусвязного списка
    /*list* i = h->next;
    list* iNext;
    while (i)
    {
        list* j = i;
        list* jPrev;
        while (j->prev)
        {
            jPrev = j->prev;
            if (j->inf > jPrev->inf)
            {
                list* jNext = j;

                int x = jPrev->inf;
                del_node(h, t, jPrev);
                print(h, t);

                insert_after(h, t, jNext, x);
                print(h, t);

                jPrev = j;
            }
            j = jPrev;
        }
        i = i->next;
    }*/

    for (list* i = h->next; i; i = i->next) {
        list* j = i;
        while ((j != h) && (j->inf < j->prev->inf)) {
            int a = j->prev->inf;
            del_node(h, t, j->prev);
            insert_after(h, t, j, a);
        }
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
    insertionSort(h, t);
    print(h, t);
    return 0;
}