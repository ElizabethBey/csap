//7. Дана последовательность целых чисел. Удалить все четные элементы. 
//Заменить все максимальные элементы на минимальный. Найти количество элементов, кратных X.

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

bool nch(int x) { //чётное ли число
    return x % 2 == 0;
}

int x = 1;
bool kratn(int y) { //кратен ли y x 
    return y % x == 0;
}
bool not_kratn(int y) { //некратен ли y x 
    return y % x != 0;
}

int main()
{
    setlocale(LC_ALL, "rus");
    int n;
    cout << "n = "; cin >> n;

    //ввод вектора
    vector<int> vec1;
    for (int i = 0; i < n; i++) {
        cout << "a[" << i << "] = ";
        cin >> x;
        vec1.push_back(x);
    }

    cout << "Удалить все чётные: " << endl;
    vector<int> vec(vec1);
    vector<int>::iterator it = remove_if(vec.begin(), vec.end(), nch);
    vec.erase(it, vec.end()); //удаление чётных эл-тов
    for (vector<int>::iterator iter = vec.begin(); iter != vec.end(); iter++)
        cout << *iter << "  ";
    cout << endl;
    
    cout << "Замена максимальных на минимальные: " << endl;
    vec = vec1;
    int Min = *min_element(vec.begin(), vec.end()); 
    int Max = *max_element(vec.begin(), vec.end()); 
    replace(vec.begin(), vec.end(), Max, Min); //замена max на min
    for (vector<int>::iterator iter = vec.begin(); iter != vec.end(); iter++)
        cout << *iter << "  ";
    cout << endl;

    //Найти количество элементов, кратных X.
    vec = vec1;
    cout << "X = "; cin >> x;
    int count = 0;
    replace_if(vec.begin(), vec.end(), kratn, x);
    replace_if(vec.begin(), vec.end(), not_kratn, 0);
    for (vector<int>::iterator iter = vec.begin(); iter != vec.end(); iter++)
        cout << *iter << "  ";
    cout << endl;
    count = accumulate(vec.begin(), vec.end(), 0) / x;

    cout << "Кол-во эл-тов, кратных X: " << count << endl;

    system("pause");

    return 0;
}