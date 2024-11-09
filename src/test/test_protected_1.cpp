#include <iostream>

class Base {
public:
    void publicFunction() {
        std::cout << "Base::publicFunction" << std::endl;
    }

protected:
    void protectedFunction() {
        std::cout << "Base::protectedFunction" << std::endl;
    }
};

class Derived : protected Base {
public:
    void callFunctions() {
        // 在派生类中可以访问基类的 protected 成员函数
        protectedFunction();
        publicFunction();
    }

    void callProtectedFunctionOfAnotherInstance(Derived& other) {
        // 不能直接调用另一个派生类实例的 protected 成员函数
        other.protectedFunction(); // 错误：不能访问 protected 成员函数
    }
};

int main() {
    Derived d1;
    // d1.callFunctions(); // 可以调用派生类的公有成员函数，该函数内部可以访问 protected 成员函数

    Derived d2;
    // d2.protectedFunction(); // 错误：不能在派生类的外部访问 protected 成员函数
    d1.callProtectedFunctionOfAnotherInstance(d2); // 错误：不能在派生类的外部访问 protected 成员函数

    return 0;
}