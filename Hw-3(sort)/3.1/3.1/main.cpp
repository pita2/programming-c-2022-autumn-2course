#include <iostream>
#include <iterator>
#include <vector>

#include <random>
using namespace std;

template<typename Iterator, typename T>
void bubble_sort(const Iterator &begin, const Iterator &end, bool (*cmp)(T, T))
{
    for (auto i = begin; i != end; ++i)
    {
        for (auto j = begin; j != end; ++j)
        {
            if (cmp(*i, *j))
            {
                swap(*i, *j);
            }
        }
    }
}

bool cmp(int a, int b)
{
    return a >= b;
}

template<typename Iterator, typename T>
void super_sort(const Iterator &begin, const Iterator &end,
             void (*algo)(const Iterator &begin, const Iterator &end, bool (*cmp)(T, T)), bool (*cmp)(T, T))
{
    algo(begin, end, cmp);
}


int main(int argc, char *argv[])
{
    //genSort(v.begin(), v.end(), "bubbleSorting",[](int a, int b)->bool {return a > b;});
    vector<int> a(4);
    for (int i = 0; i < 4; ++i)
    {
        cin >> a[i];;
        cout << a[i] << " ";
    }
    cout << endl;
    super_sort(a.begin(), a.end(), bubble_sort, cmp);
    for (int i = 0; i < 4; ++i)
    {
        cout << a[i] << " ";
    }

    return EXIT_SUCCESS;
}
