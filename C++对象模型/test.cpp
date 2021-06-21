#include <iostream>

class A{
public:
    static int fun_1();
    int fun_2();
    virtual int fun_3(){}
private:
    static int data_1;
    int data_2;
};

class X {
    int data_X;
};
class Y : public virtual X {
    int data_Y;
};
class Z : public virtual X {
    int data_Z;
};
class B : public Y, public Z {
    int data_B;
};

int main(){
    A a;
    X x, xx;
    std::cout << "sizeof(a) == " << sizeof(A) << std::endl;
    std::cout << "sizeof(X) == " << sizeof(X) << std::endl;
    std::cout << "sizeof(Y) == " << sizeof(Y) << std::endl;
    std::cout << "sizeof(Z) == " << sizeof(Z) << std::endl;
    std::cout << "sizeof(B) == " << sizeof(B) << std::endl;
    return 0;
}