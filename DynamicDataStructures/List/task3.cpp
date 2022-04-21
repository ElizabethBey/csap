//Создать двусвязный список, содержащий целые числа. Отсортировать список,
//используя сортировку вставками.
#include <iostream>

using namespace std;

struct list
{
    int inf;
    list *next;
    list *prev;
};

void push(list *&h, list *&t, int x)
{
    list *r = new list;
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

void print(list *h, list *t)
{
    list *p = h;
    while (p)
    {
        cout << p->inf << " ";
        p = p->next;
    }
}

void del_node(list *&h, list *&t, list *r)
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

void insert_after(list *&h, list *&t, list *r, int y)
{ //вставляем после r
    list *p = new list;
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

void insertionSort(list *&h, list *&t)
{
    list *i = h->next;
    list *iNext;
    while (i)
    {
        // iNext = i->next;
        list *j = i;
        list *jPrev;
        while (j->prev)
        {
            jPrev = j->prev;
            if (j->inf > jPrev->inf)
            {
                list *jNext = j;
                cout << endl
                     << j->inf << " > " << jPrev->inf << endl;
                int x = jPrev->inf;
                del_node(h, t, jPrev);
                print(h, t);

                cout << endl
                     << jNext->inf << endl;
                insert_after(h, t, jNext, x);
                print(h, t);

                jPrev = j;
            }
            j = jPrev;
        }
        cout << "i = " << i->inf << endl;
        i = i->next;
    }
}

int main()
{
    int n;
    cout << "n = ";
    cin >> n;
    list *h = NULL;
    list *t = NULL;
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