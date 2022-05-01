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

tree *find(tree *tr, int x)
{                            //поиск
    if (!tr || x == tr->inf) //нашли или дошли до конца ветки
        return tr;
    if (x < tr->inf)
        return find(tr->left, x); //ищем по левой ветке
    else
        return find(tr->right, x); //ищем по правой ветке
}

tree *Min(tree *tr)
{ //поиск min
    if (!tr->left)
        return tr; //нет левого ребенка
    else
        return Min(tr->left); //идем по левой ветке до конца
}

tree *Max(tree *tr)
{ //поиск max
    if (!tr->right)
        return tr; //нет правого ребенка
    else
        return Max(tr->right); //идем по правой ветке до конца
}

tree *Next(tree *tr, int x)
{
    tree *n = find(tr, x);
    if (n->right)
        return Min(n->right);
    tree *y = n->parent;
    while (y && n == y->right)
    {
        n = y;
        y = y->parent;
    }
    return y;
}

tree *Prev(tree *tr, int x)
{ //поиск предыдущего
    tree *n = find(tr, x);
    if (n->left)             //если есть левый ребенок
        return Max(n->left); // max по левой ветке
    tree *y = n->parent;     //родитель
    while (y && n == y->left)
    {          //пока не дошли до корня или узел - левый ребенок
        n = y; //идем вверх по дереву
        y = y->parent;
    }
    return y; //возвращаем родителя
}

void Delete(tree *&tr, tree *v)
{ //удаление узла
    tree *p = v->parent;
    if (!p)
        tr = NULL;
    else if (!v->left && !v->right)
    {
        if (p->left == v)
            p->left = NULL;
        if (p->right == v)
            p->right = NULL;
        delete v;
    }
    else if (!v->left || !v->right)
    {
        if (!p)
        {
            if (!v->left)
            {
                tr = v->right;
                v->parent = NULL;
            }
            else
            {
                tr = v->left;
                v->parent = NULL;
            }
        }
        else
        {
            if (!v->left)
            {
                if (p->left == v)
                    p->left = v->right;
                else
                    p->right = v->right;
                v->right->parent = p;
            }
            else
            {
                if (p->left == v)
                    p->left = v->left;
                else
                    p->right = v->left;
                v->left->parent = p;
            }
            delete v;
        }
    }
    else
    {
        tree *succ = Next(tr, v->inf);
        v->inf = succ->inf;
        if (succ->parent->left == succ)
        {
            succ->parent->left = succ->right;
            if (succ->right)
                succ->right->parent = succ->parent;
        }
        else
        {
            succ->parent->right = succ->right;
            if (succ->right)
                succ->right->parent = succ->parent;
        }
        delete succ;
    }
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
    x = Min(Tree)->inf;
    do
    {
        tree *y = Next(Tree, x);
        if (x % 2 != 0 && find(Tree, x))
            Delete(Tree, find(Tree, x));
        if (y)
            x = y->inf;
        else
            break;
        if (!Next(Tree, x) && x % 2 != 0)
            Delete(Tree, find(Tree, x));
    } while (find(Tree, x));
    inorder(Tree);
    cout << endl;
    return 0;
}