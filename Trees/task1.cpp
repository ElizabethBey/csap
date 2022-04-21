//Дано дерево. Удалить нечетные элементы
#include <iostream>

using namespace std;

struct tree
{
    int inf;
    tree *right;
    tree *left;
    tree *parent;
};

tree *node(int x)
{ //начальный узел
    tree *n = new tree;
    n->inf = x;
    n->left = n->right = NULL;
    n->parent = NULL;
    return n;
}

void insert(tree *&tr, int x)
{ //вставка
    tree *n = node(x);
    if (!tr)
        tr = n;
    else
    {
        tree *y = tr;
        while (y)
        {
            if (n->inf > y->inf)
                if (y->right)
                    y = y->right;
                else
                {
                    n->parent = y;
                    y->right = n;
                    break;
                }
            else if (n->inf < y->inf)
                if (y->left)
                    y = y->left;
                else
                {
                    n->parent = y;
                    y->left = n;
                    break;
                }
        }
    }
}

void inorder(tree *tr)
{ //симметричный обход
    if (tr)
    {
        inorder(tr->left);
        cout << tr->inf << " ";
        inorder(tr->right);
    }
}
