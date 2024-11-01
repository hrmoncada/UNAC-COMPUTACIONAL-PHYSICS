// guarded.hpp:
#ifndef __GUARDED_HPP
#define __GUARDED_HPP

class A {
public:
    A(int a) : m_a(a) {}
    void setA(int a) { m_a = a; }
    int getA() const { return m_a; }
private:
    int m_a;
};

#endif // __GUARDED_HPP
