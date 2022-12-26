#include <iostream>
#include <memory>
std::string g[5];
class A
{
private:
    int a;
    double b;
public:
    A(int a, int b) : a(a), b(b) {};

};
class B
{
private:
    std::string a;
    char b;
    int i;
public:
    B(std::string a, char b, int i)
    {
        a = a;
        b = b;
        g[i] = a;
    }
};

void func(std::unique_ptr<A> a, std::unique_ptr<B> b)
{

}
int main() {
    func(std::unique_ptr<A>(new A(2, 4.5)), std::unique_ptr<B>(new B("qwerty", 'c', 9)));
    func(std::make_unique<A>(2, 4.5), std::make_unique<B>("qwerty", 'c', 9));
}
//порядок
//new A()
//new B()
//std::unique_ptr<A>(...)
//std::unique_ptr<B>(...)
//при создании B может выкинуться исключение, тогда память, выделенная под А не освободится,
// так как указатель не был создан и мы не пишем delete
//make_unique предотвращает это