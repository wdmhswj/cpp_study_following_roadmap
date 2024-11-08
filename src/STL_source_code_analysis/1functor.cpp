#include <iostream>
using namespace std;

template <class T>
struct my_plus {
    T operator()(const T& x, const T& y) const {
        return x + y;
    }
};

template <class T>
struct my_minus {
    T operator()(const T& x, const T& y) const {
        return x - y;
    }
};

int main() {
    my_plus<int> plus_int;
    cout << plus_int(3, 5) << endl;

    my_minus<int> minus_int;
    cout << minus_int(3, 5) << endl;

    return 0;
}