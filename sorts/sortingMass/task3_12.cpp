// 12. Диагонали, параллельные главной по возрастанию с помощью сортировки чет-нечет
#include <iostream>
#include <algorithm>
#include <fstream>
#include <math.h>

using namespace std;

ifstream in("input.txt");
ofstream out("output.txt");
int n = 7;

void Sorting(int *&mas, int N)
{ //сортировка чет-нечет
    for (int i = 0; i < N; i++)
    {
        // (i % 2) ? 0 : 1 возвращает 1, если i четное, 0, если i не четное
        for (int j = (i % 2) ? 0 : 1; j + 1 < N; j += 2)
        {
            if (mas[j] > mas[j + 1])
            {
                swap(mas[j], mas[j + 1]);
            }
        }
    }
}

int **inFile()
{ //ввод из файла
    int **mas = new int *[n];
    for (int i = 0; i < n; i++)
        mas[i] = new int[n];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            in >> mas[i][j];
    return mas;
}

void OutFile(int **&mas)
{ //вывод в файл
    for (int i = 0; i < n; i++, out << endl)
        for (int j = 0; j < n; j++)
            out << mas[i][j] << " ";
}

int main()
{
    int **mas = inFile();
    int size = 2;
    bool flag = false;
    int k = n - 2;
    while (k >= 2 - n)
    {
        cout << k << " ";
        int *a = new int[size];
        int i = k >= 0 ? k : 0;
        int j = k >= 0 ? 0 : abs(k);
        cout << "i = " << i << "  j = " << j << endl;
        int d = 0;
        while (i < n && j < n)
        {
            a[d] = mas[i][j];
            i++;
            j++;
            d++;
        }
        for (int i = 0; i < size; i++)
            cout << a[i] << " ";
        cout << endl;
        Sorting(a, size);

        i = k >= 0 ? k : 0;
        j = k >= 0 ? 0 : abs(k);
        d = 0;
        while (i < n && j < n)
        {
            mas[i][j] = a[d];
            i++;
            j++;
            d++;
        }

        if (size == n || flag)
        {
            flag = true;
            size--;
        }
        else
            size++;
        k--;
    }
    OutFile(mas);
    return 0;
}
