#include <iostream>

using namespace std;

struct list
{ // описание структуры
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

void output(list *h, list *t)
{
    list *p = h;
    while (p)
    {
        cout << p->inf << " ";
        p = p->next;
    }
}

void outputReverseList(list *h, list *t)
{ // обратный порядок
    list *p = t;
    while (p)
    {
        cout << p->inf << " ";
        p = p->prev;
    }
}

void reverse(list *&h, list *&t)
{
    list *temp = h;
    swap(h, t);
    while (temp)
    {
        swap(temp->next, temp->prev);
        temp = temp->prev;
    }
}

list *find(list *&h, list *&t)
{ // нахождение четного элемента
    list *p = t;
    while (p->inf % 2)
        p = p->prev;

    return p;
}

list *find_min(list *&h, list *&t)
{ // нахождение минимального элемента
    list *p = h;
    list *p1 = p;
    while (p)
    {
        if (p->inf < p1->inf)
            p1 = p;
        p = p->next;
    }
    return p1;
}

list *find_max(list *&h, list *&t)
{ // нахождение максимального элемента
    list *p = h;
    list *p1 = p;
    while (p)
    {
        if (p->inf >= p1->inf)
            p1 = p;
        p = p->next;
    }
    return p1;
}

void insert_after(list *&h, list *&t, list *r, int y)
{ // вставка
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
void list_copy(list *&h1, list *&t1, list *&h, list *&t)
{
    list *p = h;
    while (p)
    {
        push(h1, t1, p->inf);
        p = p->next;
    }
}
void del_node(list *&h, list *&t, list *r)
{ // удаление

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

int main()
{
    int n, x;
    cout << "n = ";
    cin >> n;
    cout << "List: ";
    list *h = NULL;
    list *t = NULL;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        push(h, t, x);
    }

    list *h1 = h;
    list *t1 = t;

    h1 = h;
    t1 = t;
    cout << endl
         << "1 - reverse list: ";
    outputReverseList(h1, t1);

    h1 = h;
    t1 = t;
    list *p = find(h1, t1);
    cout << endl
         << "2 - find last even: " << p->inf;

    h1 = NULL;
    t1 = NULL;
    list_copy(h1, t1, h, t);
    del_node(h1, t1, find_min(h1, t1));
    cout << endl
         << "3 - delete first min: ";
    output(h1, t1);

    h1 = h;
    t1 = t;
    insert_after(h1, t1, find_max(h1, t1), 0);
    cout << endl
         << "4 - insert zero after last max: ";
    output(h1, t1);

    return 0;
}
