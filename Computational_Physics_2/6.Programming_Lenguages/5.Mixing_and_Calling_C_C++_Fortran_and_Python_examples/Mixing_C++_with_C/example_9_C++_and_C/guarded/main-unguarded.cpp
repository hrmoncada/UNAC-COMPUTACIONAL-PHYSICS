#include "unguarded.hpp"
#include "unguarded.hpp"

int main(int argc, char* argv[]) {
    A a(5);
    a.setA(0);
    return a.getA();
}
