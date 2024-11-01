/*
https://isocpp.org/wiki/faq/mixing-c-and-cpp
https://shawnliu.me/post/mixing-c-and-cpp-code/
https://www.modernescpp.com/index.php/c-core-guidelines-mixing-c-with-c
https://www.geeksforgeeks.org/extern-c-in-c/
*/

// This is C++ code
#include <cstdio>                // Nothing unusual in #include line

using namespace std;

// Both ways are OK!
extern "C" void hello1();

extern "C" {
    void hello2();
}

// Subroutines
void hello1(char *text1) {
    printf(text1);
}

void hello2(char *text2) {
    printf(text2);
}

// Driver
int main() {
  printf("Hello world\n");  // Nothing unusual in the call either
  hello1("Henry Moncada\n");
  hello2("Henry R. Moncada\n");
  return 0;
}
