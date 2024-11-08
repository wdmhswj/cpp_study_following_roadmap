#include <iostream>
#include <memory>

struct Base {
    virtual void f(int a = 7) {
        std::cout << "Base " << a << std::endl;;
    }
};
struct Derived: Base {
    virtual void f(int a) override {
        std::cout << "Derived " << a << std::endl;;
    }
};

int main() {
    std::unique_ptr<Base> ptr = std::make_unique<Derived>();
    ptr->f();
}