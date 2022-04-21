//Удалить из очереди слова, совпадающие с последним словом
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

void task(queue *&h, queue *&t)
{
    string last = t->inf;
    string s;
    queue *h1 = NULL, *t1 = NULL;
    while (h)
    {
        s = pop(h, t);
        if (s != last)
            push(h1, t1, s);
    }
    h = h1;
    t = t1;
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
