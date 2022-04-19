#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

bool IsNumber(const string &s)
{ //проверяет является ли строка числом
    return all_of(s.begin(), s.end(), [](const char &c)
                  { return isdigit(c); });
}

int main()
{
    ifstream file("text3.txt");
    map<string, int> mp;
    string s;
    bool flag = true;
    int first_digit;
    while (file.peek() != EOF)
    {
        getline(file, s, ' ');
        if (flag && IsNumber(s))
        {
            first_digit = stoi(s);
            flag = false;
        }
        if (!IsNumber(s))
        {
            map<string, int>::iterator it = mp.find(s);
            if (it == mp.end())
                mp.insert(make_pair(s, 1));
            else
                it->second += 1;
        }
    }
    for (map<string, int>::iterator it = mp.begin(); it != mp.end(); it++)
    {
        cout << "Key: " << it->first << " - value: " << it->second << endl;
    }
    cout << endl;
    for (map<string, int>::iterator it = mp.begin(); it != mp.end(); it++)
    {
        if (it->second == first_digit)
            cout << "Word " << it->first << " occurs " << first_digit << " times" << endl;
    }
    cout << endl;
    return 0;
}
