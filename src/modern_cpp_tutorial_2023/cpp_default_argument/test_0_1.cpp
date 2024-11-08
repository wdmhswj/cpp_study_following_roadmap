#include <iostream>

void f(int, int = 6, int);
void f(int, int, int = 10);
void f(int = 4, int, int);
void f(int a, int b, int c) {
    std::cout << a << " " << b << " " << c << std::endl;
}

int main() {
    f();


    return 0;
}