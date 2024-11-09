#include <iostream>

class Base {
protected:
    int protectedMember;

public:
    Base(int value) : protectedMember(value) {}
    virtual bool equals(const Base* other) const = 0;
};

class DerivedPublic : public Base {
public:
    DerivedPublic(int value) : Base(value) {}

    void show() {
        std::cout << "Protected member in DerivedPublic: " << protectedMember << std::endl;
    }

    bool equals(const Base* other) const override {
        return protectedMember == static_cast<const DerivedPublic*>(other)->protectedMember;
    }
};

class DerivedProtected : protected Base {
public:
    DerivedProtected(int value) : Base(value) {}

    void show() {
        std::cout << "Protected member in DerivedProtected: " << protectedMember << std::endl;
    }

    bool equals(const Base* other) const override {
        return protectedMember == static_cast<const DerivedProtected*>(other)->protectedMember;
    }
};

class DerivedPrivate : private Base {
public:
    DerivedPrivate(int value) : Base(value) {}

    void show() {
        std::cout << "Protected member in DerivedPrivate: " << protectedMember << std::endl;
    }

    bool equals(const Base* other) const override {
        return protectedMember == static_cast<const DerivedPrivate*>(other)->protectedMember;
    }
};

int main() {
    DerivedPublic dp(10);
    dp.show();

    DerivedPublic dp2(10);
    std::cout << "dp equals dp2: " << dp.equals(&dp2) << std::endl;

    DerivedProtected dpr(20);
    dpr.show();

    DerivedProtected dpr2(20);
    // std::cout << "dpr equals dpr2: " << dpr.equals(&dpr2) << std::endl; 

    DerivedPrivate dpv(30);
    dpv.show();

    DerivedPrivate dpv2(30);
    // std::cout << "dpv equals dpv2: " << dpv.equals(&dpv2) << std::endl;


    return 0;
}