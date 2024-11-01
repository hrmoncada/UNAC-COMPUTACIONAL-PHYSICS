#include <string>

class Foo {
public:
    Foo(int a, int b);
    ~Foo();

    int bar(int c) const;
    double baz(double d) const;
private:
    int a;
    int b;
};

void foo_speaker(std::string s);
