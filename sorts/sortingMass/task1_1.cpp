// 1 Солбцы по возрастанию с помощью быстрой сортировки
#include <iostream>
#include <algorithm>
#include <fstream>

using namespace std;

ifstream in("input.txt");
ofstream out("output.txt");
int n = 4;

void quicksort(int *mas, int first, int last)
{
    int mid, count;
    int f = first, l = last;
    mid = mas[(f + l) / 2]; //вычисление опорного элемента
    do
    {
        while (mas[f] < mid)
            f++;
        while (mas[l] > mid)
            l--;
        if (f <= l) //перестановка элементов
        {
            swap(mas[l], mas[f]);
            f++;
            l--;
        }
    } while (f < l);
    if (first < l)
        quicksort(mas, first, l);
    if (f < last)
        quicksort(mas, f, last);
}

int **inFile()
{ //ввод из файла
    int **mas = new int *[n];
    for (int i = 0; i < n; i++)
        mas[i] = new int[n];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            in >> mas[j][i];
    return mas;
}

void OutFile(int **&mas)
{ //вывод в файл
    for (int j = 0; j < n; j++, out << endl)
        for (int i = 0; i < n; i++)
            out << mas[i][j] << " ";
}

int main()
{
    int **mas = inFile();
    for (int i = 0; i < n; i++)
        quicksort(mas[i], 0, n - 1);
    OutFile(mas);
    return 0;
}
