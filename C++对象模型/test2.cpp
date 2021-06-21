#include <iostream>

class X {
public:
    static int static_fun_X();
    int non_static_fun_X();
    virtual int virtual_fun_X(){
        std::cout << "virtual_fun_X() from X" << std::endl;
    };
private:
    static int static_data_X;
    int non_static_data_X;
};

class Y : public virtual X {
public:
    static int static_fun_Y();
    int non_static_fun_Y();
    virtual int virtual_fun_Y(){
        std::cout << "virtual_fun_Y() from Y" << std::endl;
    }
    virtual int virtual_fun_X(){
        std::cout << "virtual_fun_X() from Y" << std::endl;
    }
private:
    static int static_data_Y;
    int non_static_data_Y;
};

class Z : public virtual X {
public:
    static int static_fun_Z();
    int non_static_fun_Z();
    virtual int virtual_fun_Z(){
        std::cout << "virtual_fun_Z() from Z" << std::endl;
    };
private:
    static int static_data_Z;
    int non_static_data_Z;
};

class A : public Y, public Z {
public:
    static int static_fun_A();
    int non_static_fun_A();
    virtual int virtual_fun_A(){
        std::cout << "virtual_fun_A() from A" << std::endl;
    }
    virtual int virtual_fun_Z(){
        std::cout << "virtual_fun_Z() from A" << std::endl;
    }
    virtual int virtual_fun_X(){
        std::cout << "virtual_fun_X() from A" << std::endl;
    }
private:
    static int static_data_A;
    int non_static_data_A;
};

int main(){
    X x;
    Y y;
    Z z;
    A a;
    x.virtual_fun_X(); //X类对象调用自己的函数
    y.virtual_fun_X(); //Y类对象调用重写之后的父类函数
    z.virtual_fun_X(); //Z类对象调用父类函数
    a.virtual_fun_Y(); //A类对象调用父类Y的函数
    a.virtual_fun_Z(); //A类对象调用重写之后的父类Z的函数
    a.virtual_fun_X(); //A类对象调用重写之后的父类X的函数
    std::cout << "sizeof(X) == " << sizeof(X) << std::endl;
    std::cout << "sizeof(Y) == " << sizeof(Y) << std::endl;
    std::cout << "sizeof(Z) == " << sizeof(Z) << std::endl;
    std::cout << "sizeof(A) == " << sizeof(A) << std::endl;
}