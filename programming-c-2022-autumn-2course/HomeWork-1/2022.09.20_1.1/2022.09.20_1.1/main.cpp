#include <iostream>

class Test
{
    long long ll = 1;
    double dbl = 1.0;
    float flt = 1.0;
    int in = 1;
    unsigned int ui = 1;
    short int si = 1;
    char chr = '1';
    bool bol = 0;
};


int main(int argc, const char * argv[])
{
    Test test;
    std::cout << sizeof(test);
    return 0;
}
