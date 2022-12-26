#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include "vVector.h"

using namespace std;

class A
{
public:
    int a;
    string s;
};

int main()
{
    int n = 0;
    cin >> n;
    vVector<A> f(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> f[i].a >> f[i].s;
        cout << f[i].a  << " " << f[i].s << endl;
    }

    ofstream of("1.txt");
    of.rdbuf()->sputn(reinterpret_cast<char*>(&n), sizeof(n));

    for(int i = 0; i < n; ++i)
    {
        of.rdbuf()->sputn(reinterpret_cast<char*>(&f[i]), sizeof(A));
    }
    of.close();
    return 0;
}
