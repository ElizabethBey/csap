// 10. Нечетные строки по убыванию, четные по возрастанию помощью гномьей сортировки.
#include <iostream>
#include <algorithm>
#include <fstream>

using namespace std;

ifstream in("input.txt");
ofstream out("output.txt");
int n = 4;

void GnomSort(int *mas, int marker)
{ //гномья сортировка
    int i = 0;
    while (i < n)
    {
        bool flag = marker % 2 == 0 ? mas[i - 1] <= mas[i] : mas[i - 1] >= mas[i];
        if (i == 0 || flag)
            ++i;
        else
        {
            swap(mas[i], mas[i - 1]);
            --i;
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
    for (int i = 0; i < n; i++)
        GnomSort(mas[i], i);
    OutFile(mas);
    return 0;
}
