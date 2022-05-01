//Дано идеально-сбалансированное дерево. Подсчитать сумму листьев.
#include <iostream>
#include <cmath>
#include <queue>

using namespace std;

struct tree
{
    int inf;
    tree *right;
    tree *left;
};

tree *node(int x)
{ //начальный узел
    tree *n = new tree;
    n->inf = x;
    n->left = n->right = NULL;
    return n;
}

void create(tree *&tr, int n)
{ //создание дерева
    int x;
    if (n > 0)
    {
        cin >> x;
        tr = node(x);
        int nl = n / 2;
        int nr = n - nl - 1;
        create(tr->left, nl);
        create(tr->right, nr);
    }
}

void preorder(tree *tr)
{ //прямой обход
    if (tr)
    {
        cout << tr->inf << " ";
        preorder(tr->left);
        preorder(tr->right);
    }
}

void print(tree *tr, int k)
{
    if (!tr)
        cout << "Empty tree\n";
    else
    {
        queue<tree *> cur, next;
        tree *r = tr;
        cur.push(r);
        int j = 0;
        while (cur.size())
        {
            if (j == 0)
            {
                for (int i = 0; i < (int)pow(2.0, k) - 1; i++)
                    cout << " ";
            }
            tree *buf = cur.front();
            cur.pop();
            j++;
            if (buf)
            {
                cout << buf->inf;
                next.push(buf->left);
                next.push(buf->right);
                for (int i = 0; i < (int)pow(2.0, k + 1) - 1; i++)
                    cout << " ";
            }
            if (!buf)
            {
                for (int i = 0; i < (int)pow(2.0, k + 1) - 1; i++)
                    cout << " ";
                cout << " ";
            }
            if (cur.empty())
            {
                cout << endl;
                swap(cur, next);
                j = 0;
                k--;
            }
        }
    }
}

static int Sum(tree *tr)
{
    static int sum = 0;
    if (!tr)
        return sum;
    if (!tr->left && !tr->right)
    {
        sum += tr->inf;
        return sum;
    }
    if (tr->left)
        Sum(tr->left);
    if (tr->right)
        Sum(tr->right);
}

int main()
{
    tree *tr = NULL;
    int n, x;
    cout << "n = ";
    cin >> n;
    create(tr, n);
    int k = int(log((float)n) / log((float)2.0));
    print(tr, k);
    cout << "Sum of the tree leaves " << Sum(tr);
    cout << endl;
    return 0;
}