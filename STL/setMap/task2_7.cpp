#include <iostream>
#include <fstream>
#include <set>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string lower(string s)
{ //приводит все буквы слова к нижнему регистру
    int i = 0;
    while (s[i])
    {
        if (isupper(s[i]))
            s[i] = tolower(s[i]);
        i++;
    }
    return s;
}

int main()
{
    set<string> vopr, voskl, pov;
    string razd = ".!?";
    ifstream file("text.txt");
    string str;
    while (file.peek() != EOF)
    {
        getline(file, str);
        int k = str.find_first_of(razd, 0); // индекс разделителя
        // поиск предложений
        bool flag = true;
        while (flag)
        {
            string sentence = str.substr(0, k) + " ";
            char tmp = str[k];
            if (str.size() > k + 2)
                str = str.substr(k + 2);
            else
                flag = false;
            // поиск слов
            int k1 = sentence.find_first_of(" ", 0);
            while (k1 != string::npos)
            {
                string word = sentence.substr(0, k1);
                switch (tmp)
                {
                case '.':
                    pov.insert(lower(word));
                    break;
                case '!':
                    voskl.insert(lower(word));
                    break;
                case '?':
                    vopr.insert(lower(word));
                    break;
                default:
                    break;
                }
                sentence = sentence.substr(k1 + 1);
                k1 = sentence.find_first_of(" ", 0);
            }
            k = str.find_first_of(razd, 0);
        }
    }

    cout << " ! " << endl;
    for (auto it = voskl.begin(); it != voskl.end(); it++)
        cout << *it << "  ";
    cout << endl;

    cout << " . " << endl;
    for (auto it = pov.begin(); it != pov.end(); it++)
        cout << *it << "  ";
    cout << endl;

    cout << " ? " << endl;
    for (auto it = vopr.begin(); it != vopr.end(); it++)
        cout << *it << "  ";
    cout << endl;

    //объдинение слов из воскл и вопр предложений
    vector<string> unionv(vopr.size() + voskl.size());
    vector<string>::iterator it = set_union(vopr.begin(), vopr.end(), voskl.begin(), voskl.end(), unionv.begin());
    unionv.resize(it - unionv.begin());
    //проверка нет ли в пов. предл.
    auto newEnd = remove_if(unionv.begin(), unionv.end(), [&](string c)
                            { return find(pov.begin(), pov.end(), c) != pov.end(); });
    unionv.erase(newEnd, unionv.end());

    cout << "Number ((! + ?) - .) : " << unionv.size() << endl
         << "Words: ";
    for (auto it = unionv.begin(); it != unionv.end(); it++)
        cout << *it << "  ";
    cout << endl;

    return 0;
}
