// Создать стек, содержащий целые числа. В новый стек сначала вывести четные, потом нечетные числа
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

stack *result(stack *&h)
{
    stack *ch = NULL;
    stack *n = NULL;
    while (h)
    {
        int x = pop(h);
        if (x % 2 == 0)
            push(ch, x);
        else
            push(n, x);
    }
    while (n)
    {
        int x = pop(n);
        push(h, x);
    }
    while (ch)
    {
        int x = pop(ch);
        push(h, x);
    }
    cout << endl;
    return h;
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
    reverse(head);
    head = result(head);
    while (head)
        cout << pop(head) << " ";
    return 0;
}
