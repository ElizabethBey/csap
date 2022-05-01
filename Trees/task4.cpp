//Дано дерево. Определить высоту узла X
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

int height(tree *node)
{
    //максимальная длина пути от узла до листа
    if (!node)
        return 0;
    else if (!node->left && !node->right)
        return 0;
    else
    {
        int hl = height(node->left);
        int hr = height(node->right);
        cout << node->left->inf << " "
             << "hL " << hl << " hR " << hr << endl;
        if (hl > hr)
            return hl + 1;

        else
            return hr + 1;
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

void find(tree *tr, int x, tree *&res)
{ //найти узел
    if (tr)
    {
        if (tr->inf == x)
        {
            res = tr;
        }
        else
        {
            find(tr->left, x, res);
            find(tr->right, x, res);
        }
    }
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
    cout << "Node: ";
    cin >> x;
    tree *res;
    find(tr, x, res);
    if (res)
        x = height(res);
    cout << x;
    cout << endl;
    return 0;
}