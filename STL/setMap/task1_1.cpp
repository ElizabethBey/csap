// 1. Найти все такие цифры, которые встречаются только в двузначных числах
#include <iostream>
#include <set>

using namespace std;

bool dv(int x)
{ //является ли двузначным числом
    return x < 100 && x > 9;
}

set<int> set_update(set<int> s, int x)
{ //добавляет цифры числа во множество
    s.insert(x % 10);
    s.insert(x / 10);
    return s;
}

int main()
{
    setlocale(LC_ALL, "rus");
    int n;
    cout << "n = ";
    cin >> n;

    int c;
    set<int> s;
    for (int i = 0; i < n; i++)
    {
        cout << "a[" << i << "] = ";
        cin >> c;
        if (dv(c))
            s = set_update(s, c);
    }

    cout << "Number of different digits in two-digits numbers: " << s.size() << endl;
    for (set<int>::iterator it = s.begin(); it != s.end(); it++)
        cout << *it << "  ";
    cout << endl;

    system("pause");
    return 0;
}
