#include <iostream>
using namespace std;
class A
{
private:
    int x = 1;
    int y = 10;
    int z = 100;
    void printX()
    {
        cout << this->x;
    }
    void printY()
    {
        cout << this->y;
    }void printZ()
    {
        cout << this->z;
    }
};

int main(int argc, const char * argv[])
{
    A obj;
    int* t = (int*)(&obj);
    *t = 2;
    t++;
    *t = 20;
    t++;
    *t = 200;
    
    
    
    return 0;
}


