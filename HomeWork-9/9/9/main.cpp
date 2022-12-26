#include <iostream>
#include <functional>
#include <cmath>
#include <type_traits>
using namespace std;

template <typename Tfunc, typename... Targ>
class logg
{
private:
    function<Tfunc(Targ...)> f;

public:
    logg(function<Tfunc(Targ...)> f)
    {
        this->f = f;
    }
    
    Tfunc operator() (Targ... args)
    {
        print(args...);
        return f(args...);
    }
    inline void print() {}
    
    template <class First, class... Other>
    void print(First first, Other... args)
    {
      cout << first << " ";
      print(args...);
    }
    
    template <class... TT>
    void print(TT&... other)
    {
      print(other...);
    }
    
};

int f(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    return f(b, a % b);
}

double sm(int a, int b, double c)
{
    return a + b + c;
}


int main()
{
    int y = 2000, m = 12, d = 21;
    int a = 1440;
    int b = 3680;
    logg <int, int, int> F(f);
    cout << F(a, b) << endl;
    logg <double, int, int, double> SM(sm);
    cout << SM(y, m, 1.5) << endl;
}
