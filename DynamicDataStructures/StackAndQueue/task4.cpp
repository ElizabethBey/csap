//Удалить из очереди слова, оставив только первые вхождения
#include <iostream>
#include <string>

using namespace std;

struct queue
{
    string inf;
    queue *next;
};

void push(queue *&h, queue *&t, string x)
{ //вставка элемента в очередь
    queue *r = new queue;
    r->inf = x;
    r->next = NULL;
    if (!h && !t)
        h = t = r;
    else
    {
        t->next = r;
        t = r;
    }
}

string pop(queue *&h, queue *&t)
{
    queue *r = h;
    string i = h->inf;
    h = h->next;
    if (!h)
        t = NULL;
    delete r;
    return i;
}

void task(queue *&head, queue *&tail)
{
    queue *resh = NULL, *rest = NULL;
    queue *h = NULL, *t = NULL;
    while (head)
    {
        string s = pop(head, tail);
        push(resh, rest, s);
        while (head)
        {
            string x = pop(head, tail);
            if (x != s)
                push(h, t, x);
        }
        head = h;
        tail = t;
        h = NULL;
        t = NULL;
    }
    head = resh;
    tail = rest;
}

int main()
{
    int n;
    cout << "n = ";
    cin >> n;
    string s;
    queue *head = NULL;
    queue *tail = NULL;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        push(head, tail, s);
    }
    task(head, tail);
    while (head && tail)
        cout << pop(head, tail) << " ";
    return 0;
}
