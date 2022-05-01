// Дано дерево. Вывести путь от корня до узла X.
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

tree *find(tree *tr, int x)
{                            //поиск
    if (!tr || x == tr->inf) //нашли или дошли до конца ветки
        return tr;
    if (x < tr->inf)
        return find(tr->left, x); //ищем по левой ветке
    else
        return find(tr->right, x); //ищем по правой ветке
}

int main()
{
    int n, x;
    cout << "n = ";
    cin >> n;
    tree *Tree = NULL;
    for (int i = 0; i < n; i++)
    {
        cout << i << " : ";
        cin >> x;
        insert(Tree, x);
    }
    inorder(Tree);
    cout << endl;
    return 0;
}