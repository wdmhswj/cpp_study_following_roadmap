//
//  重载运算符
//

#include <iostream>


class Complex
{
    private:
        float real;
        float imag;
    
    public:
        Complex(float r=0, float i=0): real(r), imag(i) {}

        // 重载 + 运算符
        Complex operator+(const Complex& other)
        {
            return Complex(real+other.real, imag+other.imag);
        }

        void display() const
        {
            std::cout<<"("<<real<<", "<<imag<<")"<<std::endl;
        }
};


class MyClass
{
    private:
        int* data;
    public:
        MyClass(int value)
        {
            data = new int(value);
        }

        // 重载 = 运算符
        MyClass& operator=(const MyClass& other)
        {
            if(this!=&other)
            {
                delete data;    // 释放已有资源
                data = new int(*other.data);    // 分配新资源并复制数据
            }
            return *this;   // 
        }

        void display() const
        {
            std::cout<<*data<<std::endl;
        }

        ~MyClass()
        {
            delete data;
        }
};

class Counter
{
    private:
        int count;
    public:
        Counter(): count(0) {}

    // 前置递增运算符
    Counter& operator++()
    {
        ++count;
        return *this;
    }

    // 后置递增运算符
    Counter operator++(int)
    {
        Counter temp = *this;
        ++count;
        return temp;
    }
    void display() const {
        std::cout << "Count: " << count << std::endl;
    }
};
int main()
{
    Complex c1(3.5, 2.5);
    Complex c2(1.5, 4.5);

    Complex c3 = c1 + c2;  // 使用重载的 + 运算符
    c3.display();  // 输出 (5, 7)

    MyClass obj1(10);
    MyClass obj2(20);

    obj2 = obj1;  // 使用重载的 = 运算符
    obj2.display();  // 输出 10

    Counter c;
    c.display();  // Count: 0

    ++c;  // 使用前置递增
    c.display();  // Count: 1

    c++;  // 使用后置递增
    c.display();  // Count: 2

    return 0;
}