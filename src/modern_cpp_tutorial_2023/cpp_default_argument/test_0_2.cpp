#include<iostream>

template <class... T>
struct X {
    void f(int n = 0, T...) {
        std::cout << n << std::endl;
    }
};

template<class... Args>
void f_(int n = 6, Args... args) {
    std::cout << n << std::endl;
}

int main() {
    X().f();
    X<int>().f(1, 2);

    f_();
    f_(3, "hello");
    
}