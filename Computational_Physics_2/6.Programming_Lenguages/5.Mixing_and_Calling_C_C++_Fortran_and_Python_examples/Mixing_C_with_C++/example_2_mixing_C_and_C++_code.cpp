/*
https://www.modernescpp.com/index.php/c-core-guidelines-mixing-c-with-c
https://isocpp.org/wiki/faq/mixing-c-and-cpp
https://shawnliu.me/post/mixing-c-and-cpp-code/
https://www.geeksforgeeks.org/extern-c-in-c/

CPL.3: If you must use C for interfaces, use C++ in the calling code using such interfaces
In contrast to C, C++ supports function overloading. This means that you can define a function having the same name but different parameters. The compiler picks the right function when a function is invoked.

// functionOverloading.cpp
*/

#include <iostream>  
  
void print(int) { 
    std::cout << "int" << std::endl; 
} 

void print(double) { 
    std::cout << "double" << std::endl; 
} 

void print(const char*) { 
    std::cout << "const char* " << std::endl; 
} 

void print(int, double, const char*) { 
    std::cout << "int, double, const char* " << std::endl; 
} 

  
int main() { 
 
    std::cout << std::endl;   

    print(10); 
    print(10.10); 
    print("ten"); 
    print(10, 10.10, "ten");

    std::cout << std::endl;

}
