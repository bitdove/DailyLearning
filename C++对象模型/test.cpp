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

int main(){
    A a;
    std::cout << "sizeof(a) == " << sizeof(A) << std::endl;
    return 0;
}