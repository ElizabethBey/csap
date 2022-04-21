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
