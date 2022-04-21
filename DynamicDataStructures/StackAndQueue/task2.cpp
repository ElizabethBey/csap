//в стеке перед каждым мин вставить новый элемент
#include <iostream>

using namespace std;

struct stack
{ //стек
    int inf;
    stack *next;
};

void push(stack *&h, int x)
{ //добавление элемента в стек
    stack *r = new stack;
    r->inf = x;
    r->next = h;
    h = r;
}

int pop(stack *&h)
{ //удаление элемента из стека
    int i = h->inf;
    stack *r = h;
    h = h->next;
    delete r;
    return i;
}

void reverse(stack *&h)
{ //обращение стека
    stack *head1 = NULL;
    while (h)
        push(head1, pop(h));
    h = head1;
}

int minEl(stack *h)
{ //поиск мин элемента
    stack *tmp = NULL;
    int x, min = pop(h);
    push(tmp, min);
    while (h)
    {
        x = pop(h);
        if (x < min)
            min = x;
        push(tmp, x);
    }
    reverse(tmp);
    h = tmp;
    return min;
}

stack *result(stack *h)
{ //вставка нового элемента перед каждым мин
    int min = minEl(h);
    stack *tmp = NULL;
    int a, x;
    cout << "a = ";
    cin >> a;
    while (h)
    {
        x = pop(h);
        push(tmp, x);
        if (x == min)
            push(tmp, a);
    }
    return tmp;
}

int main()
{
    int n;
    cout << "n = ";
    cin >> n;
    stack *head = NULL;
    int x;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        push(head, x);
    }
    head = result(head);
    while (head)
        cout << pop(head) << " ";
    return 0;
}
