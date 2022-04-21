#include <iostream>
#include <list>

using namespace std;

int n; //вершины графа
int x; //начало обхода

struct stack
{ //стек
    int inf;
    stack *next;
};

struct queue
{
    int inf;
    queue *next;
};

void pushStack(stack *&h, int p)
{ //добавление элемента в стек
    stack *r = new stack;
    r->inf = p;
    r->next = h;
    h = r;
}

void popStack(stack *&h)
{ //удаление элемента из стека
    int i = h->inf;
    stack *r = h;
    h = h->next;
    delete r;
}

void pushQ(queue *&h, queue *&t, int p)
{ //вставка элемента в очередь
    queue *r = new queue;
    r->inf = p;
    r->next = NULL;
    if (!h && !t)
        h = t = r;
    else
    {
        t->next = r;
        t = r;
    }
}

int popQ(queue *&h, queue *&t)
{
    queue *r = h;
    int i = h->inf;
    h = h->next;
    if (!h)
        t = NULL;
    delete r;
    return i;
}

void WFS(int p, queue *&h, queue *&t, list<int> *&gr, int *&a)
{ //алгоритм обхода графа в ширину
    pushQ(h, t, p);
    while (h)
    {
        p = popQ(h, t);
        int y;
        bool fl = true;
        for (int i = 0; i < n; i++)
        {
            for (auto it = gr[i].begin(); it != gr[i].end(); ++it)
            {
                int g = *it;
                if (a[g] == 0)
                {
                    cout << g << " ";
                    a[g] = 1;
                    pushQ(h, t, g);
                    fl = false;
                }
            }
        }
        if (fl)
            p = popQ(h, t);
    }
}

void Width(list<int> *&gr, int *&a)
{ //обход графа в ширину
    cout << x << " ";
    queue *h = NULL;
    queue *t = NULL;
    WFS(x, h, t, gr, a);
    for (int i = 0; i < n; i++)
        if (a[i] != 1)
        {
            a[i] = 1;
            WFS(i, h, t, gr, a);
        }
}

void DFS(int p, stack *&h, list<int> *&gr, int *&a)
{ //алгоритм обхода в глубину начиная с вершины p
    pushStack(h, p);
    bool fl = false;
    while (h)
    {
        p = h->inf;
        int y;
        for (int g : gr[p])
        {
            if (a[g] == 0)
            {
                y = g;
                fl = true;
                break;
            }
            else
                fl = false;
        }
        if (fl)
        {
            a[y] = 1;
            pushStack(h, y);
            cout << y << " ";
        }
        else
            popStack(h);
    }
}

void Depth(list<int> *&gr, int *&a)
{ //обход в глубину
    cout << x << " ";
    stack *h = NULL;
    DFS(x, h, gr, a);
    for (int i = 0; i < n; i++)
    {
        if (a[i] != 1)
        {
            a[i] = 1;
            DFS(i, h, gr, a);
        }
    }
}

int main()
{
    cout << "Vvedite kol-vo vershin: n = ";
    cin >> n; //вершины
    cout << "Graph " << endl;
    list<int> *gr = new list<int>[n];
    for (int i = 0; i < n; i++)
    {
        int k;
        cout << "Vershina " << i << " imeet "
             << "reber: k = ";
        cin >> k;
        cout << "vvedite rebra: ";
        for (int j = 0; j < k; j++)
        {
            int x;
            cin >> x;
            gr[i].push_front(x);
        }
        cout << endl;
    }

    cout << "Obxod nachaetsya c: x = ";
    cin >> x; //обход начинать с x

    int *a = new int[n]; //массив посещённых вершин
    for (int i = 0; i < n; i++)
    {
        a[i] = i == x ? 1 : 0;
    }

    //обход в глубину
    cout << "Obxod v glybuny: ";
    Depth(gr, a);
    for (int i = 0; i < n; i++)
    {
        a[i] = i == x ? 1 : 0;
    }
    //обход в ширину
    cout << endl
         << "Obxod v shiriny: ";
    Width(gr, a);

    return 0;
}