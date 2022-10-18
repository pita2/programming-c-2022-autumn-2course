#include <iostream>
#include <random>
#include <ctime>
#include "ArrayList.cpp"

using namespace std;

int main(int argc, char* argv[])
{
    srand(time(0));
    ArrayList<string> a;
    for (int i = 0; i < 10; ++i)
    {
        a.pushend("jjf");
    }
    a.print();
    //cout << a << endl;
    
    a.insert("'Abcd'", 7);
    a.print();
    
    //std::cout << a << std::endl;
    return EXIT_SUCCESS;
}
