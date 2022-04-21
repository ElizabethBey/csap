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

int result(string s)
{
    stack *head = NULL;
    int i = 0;
    while (i < s.length())
    {
        if (isdigit(s[i]))
        {
            char c = s[i];
            int x = c - '0';
            push(head, x);
            x = 0;
        }
        else
        {
            int a = pop(head), b = pop(head);
            cout << "a = " << a << " b = " << b << " c = " << s[i] << endl;
            switch (s[i])
            {
            case '*':
                push(head, a * b);
                break;
            case '+':
                push(head, a + b);
                break;

            case '-':
                push(head, b - a);
                break;

            case '/':
                push(head, b / a);
                break;

            default:
                break;
            }
        }
        i++;
    }

    return head->inf;
}

int main()
{
    string s;
    cout << "Expressoin: ";
    cin >> s;

    cout << result(s);

    return 0;
}