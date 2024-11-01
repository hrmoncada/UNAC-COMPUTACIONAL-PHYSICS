// unguarded.hpp
class A {
public:
    A(int a) : m_a(a) {}
    void setA(int a) { m_a = a; }
    int getA() const { return m_a; }
private:
    int m_a;
};

