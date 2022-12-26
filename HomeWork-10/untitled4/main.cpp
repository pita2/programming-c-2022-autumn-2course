#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <fstream>
using namespace std;


int main(int argc, const char * argv[])
{
    map <string, string> m1;
    map <string, string> m2;
    set <string> s;
    string d;
    map <char, vector<string>> first;
    ifstream in("dict.txt");

    if (!in.is_open())
    {
        cout << "Not open" << endl;
        return 0;
    }
    string s1, s2;
    while (in >> s1 >> s2)
    {
        m1[s1] = s2;
        m2[s2] = s1;
        s.insert(s1);
        s.insert(s2);
        char c1 = s1[0];
        char c2 = s2[0];
        first[c1].push_back(s1);
        first[c2].push_back(s2);
    }
    in.close();

    while (true)
    {
        cout << "Ведите 1, а далее слово, чтобы перевести его в шифр цезаря" << endl;
        cout << "Ведите 2, а далее слово, чтобы перевести его из шифра цезаря обратно" << endl;
        cout << "Ведите 3, а далее слово, чтобы найти его в словаре" << endl;
        cout << "Ведите 4, а далее букву, чтобы исполнить поиск по первой букве" << endl;
        cout << "Ведите 5, чтобы завершить программу" << endl;

        int k;
        cin >> k;
        if (k == 5)
        {
            break;
        }
        if (k == 1)
        {
            string p;
            cin >> p;
            if (s.find(p) != s.end())
            {
                cout << m1[p] << endl;
            }
            else
            {
                cout << "Вашего слова нет в словаре" << endl;
            }
        }
        if (k == 2)
        {
            string p;
            cin >> p;
            if (s.find(p) != s.end())
            {
                cout << m2[p] << endl;
            }
            else
            {
                cout << "Вашего слова нет в словаре" << endl;
            }
        }
        if (k == 3)
        {
            string p;
            cin >> p;
            if (s.find(p) != s.end())
            {
                cout << "Слово " << p << " есть в словаре" << endl;
            }
            else
            {
                cout << "Вашего слова нет в словаре" << endl;
            }
        }
        if (k == 4)
        {
            char p;
            cin >> p;
            for (auto i: first[p])
            {
                cout << i << " ";
            }
            cout << endl;
        }
    }


    return 0;
}
