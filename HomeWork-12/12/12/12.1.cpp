#include <iostream>
#include <vector>
#include <cmath>
#include <chrono>

using namespace std;

bool is_prime(int n)
{
    for (int i = 2; i < n; ++i)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}

long double bs(long double c)
{
    long double l = 0;
    long double r = c;
    long double eps = 1e-7;
    while (r - l > eps)
    {
        long double mid = (l + r) / 2;
        long double x = mid;
        if (x * x + sqrt(x) > c)
        {
            r = mid;
        }
        else
        {
            l = mid;
        }
    }
    return l;
}

int main()
{
    auto start = chrono::high_resolution_clock::now();
    
    bool a = is_prime(1234567);
    long double b = bs(1234.5);
    
    cout << "1 func: "<< a << "   2 func: " << b << endl;
    
    auto end = chrono::high_resolution_clock::now();

    chrono::duration<float> duration = end - start;
    cout << "Duration: " << duration.count() << 's' << endl;

    return 0;
}
