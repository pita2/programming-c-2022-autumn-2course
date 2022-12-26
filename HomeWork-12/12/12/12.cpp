#include <iostream>
#include <vector>
#include <cmath>
#include <chrono>
#include <thread>

using namespace std;
bool is_prime(int n = 1234567)
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
    std::thread thr1(is_prime, 1234567);
    std::thread thr2(bs, 12345.5);
    thr1.join();
    thr2.join();
    
    
    auto end = chrono::high_resolution_clock::now();

    chrono::duration<float> duration = end - start;
    cout << "Duration: " << duration.count() << 's' << endl;

    return 0;
}

