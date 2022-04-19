#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

ifstream in("input.txt");
ofstream out("output.txt");

struct date
{ //дата
    int dd, mm, yy;
};

struct people
{ //данные о человеке
    string Surname;
    string Post;
    date DateOfBirth;
    int Experience;
    int Salary;
};

date StrToDate(string str)
{ //преобразует строку с датой в date
    date ans;
    string tmp = str.substr(0, 2);
    ans.dd = atoi(tmp.c_str());
    tmp = str.substr(3, 2);
    ans.mm = atoi(tmp.c_str());
    tmp = str.substr(6, 4);
    ans.yy = atoi(tmp.c_str());
    return ans;
}

vector<people> inFile()
{ //ввод данных из файла
    vector<people> x;
    people temp;
    while (in.peek() != EOF)
    {
        in >> temp.Surname >> temp.Post;
        string tmp;
        in >> tmp;
        temp.DateOfBirth = StrToDate(tmp);
        in >> temp.Experience;
        in >> temp.Salary;
        x.push_back(temp);
    }
    return x;
}

void print_p(people tmp)
{ //выводит данные о человеке в out
    out << tmp.Surname << " " << tmp.Post << " ";

    if (tmp.DateOfBirth.dd < 10)
        out << "0" << tmp.DateOfBirth.dd << ".";
    else
        out << tmp.DateOfBirth.dd << ".";

    if (tmp.DateOfBirth.mm < 10)
        out << "0" << tmp.DateOfBirth.mm << ".";
    else
        out << tmp.DateOfBirth.mm << ".";

    if (tmp.DateOfBirth.yy < 10)
        out << "0" << tmp.DateOfBirth.yy << " ";
    else
        out << tmp.DateOfBirth.yy << " ";

    out << tmp.Experience << " " << tmp.Salary << endl;
}

void SortingByCounting(vector<people> &x)
{ //сортирует и выводит данные в out
    vector<vector<people>> counting(100);
    for (vector<people>::iterator it = x.begin(); it != x.end(); it++)
    {
        people p = *it;
        counting[p.DateOfBirth.yy].push_back(p);
    }
    int n = x.size();
    x.clear();
    x.resize(n);
    for (vector<vector<people>>::iterator it = counting.begin(); it != counting.end(); it++)
    {
        vector<people> tmp = *it;
        for (vector<people>::iterator it1 = tmp.begin(); it1 != tmp.end(); it1++)
        {
            people p = *it1;
            x.push_back(p);
        }
    }
    for (vector<people>::iterator it = x.begin(); it != x.end(); it++)
    {
        people tmp = *it;
        if (tmp.Surname != "")
            print_p(tmp);
    }
}

int main()
{
    setlocale(LC_ALL, "rus");
    vector<people> x = inFile();
    SortingByCounting(x);
    return 0;
}
