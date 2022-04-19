//3. Дана последовательность целых чисел. Все нечетные элементы заменить нулем.
#include <iostream>
#include <vector>
#include<algorithm>

using namespace std;

bool nch(int x) { //является ли число нечётным
    return x % 2 != 0;
}

int main(){
    setlocale(LC_ALL, "rus");
    int n;
    cout << "n = "; cin >> n;
    
    //ввод вектора
    int x;
    vector<int> vec; 
    for (int i = 0; i < n; i++) {
        cout << "a[" << i << "] = ";
        cin >> x;
        vec.push_back(x);
    }
    
    //замена нечётных элементов 0
    replace_if(vec.begin(), vec.end(), nch, 0); 
    
    //вывод вектора
    for (vector<int>::iterator iter = vec.begin(); iter != vec.end(); iter++)
        cout << *iter << "  ";
    cout << endl;

    system("pause");
    return 0;
}
