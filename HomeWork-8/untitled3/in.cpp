#include <iostream>
#include <sstream>
#include <fstream>
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
    ifstream of("1.txt");
    vVector<A> rf;
    int size = 0;
    of.rdbuf()->sgetn(reinterpret_cast<char*>(&size), sizeof(size));
    rf.resize(size);
    for (int i = 0; i < size; ++i)
    {
        of.rdbuf()->sgetn(reinterpret_cast<char*>(&rf[i]), sizeof(A));
    }

    for (int i = 0; i < size; ++i)
    {
        cout << rf[i].a  << " " << rf[i].s << endl;
    }
}
