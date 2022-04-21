//Создать двусвязный список, содержащий целые числа. Удалить все элементы,
//совпадающие с последним элементом списка.
#include <iostream>

using namespace std;

struct list
{ //двусвязный список
    int inf;
    list *next;
    list *prev;
};

void push(list *&h, list *&t, int x)
{ //добавляет элемент в конец дв. списка
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
{ //выводит двусв. список
    list *p = h;
    while (p)
    {
        cout << p->inf << " ";
        p = p->next;
    }
}

void del_node(list *&h, list *&t, list *r)
{ //удаляет узел из двусв. списка
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

void task(list *&h, list *&t, int x)
{ // удаляет все эл-ты, совпадающие с последним
    list *p = h;
    list *n;
    while (p)
    {
        n = p->next;
        if (p->inf == x)
            del_node(h, t, p);
        p = n;
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
    task(h, t, x);
    print(h, t);
    return 0;
}