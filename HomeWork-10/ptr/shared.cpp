#include <iostream>
#include<vector>

using namespace std;

class A
{
public:
    int a;
    double b;
    A(int a, int b) : a(a), b(b) {};

};
int main()
{
    vector<shared_ptr<A>> v {
            make_shared<A>(12, 12.5),
            make_shared<A>(5, 1.5),
            make_shared<A>(6, 5.5)
    };

    vector<shared_ptr<A>> v2(v.size());
    copy(v.begin(), v.end(), v2.begin());
    v.clear();
    for (const auto& s : v2)
    {
        cout << s->a << ":" << s->b << endl;
    }
}
