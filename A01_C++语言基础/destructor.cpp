#include <iostream>

class Base_Member{
public:
    Base_Member(){
        std::cout << "      Base_Member Constructor" << std::endl;
    }
    ~Base_Member(){
        std::cout << "      Base_Member Destructor" << std::endl;
    }
};

class Derived_Member{
public:
    Derived_Member(){
        std::cout << "      Derived_Member Constructor" << std::endl;
    }
    ~Derived_Member(){
        std::cout << "      Derived_Member Destructor" << std::endl;
    }
};


class Base{
public:
    Base(){
        std::cout << "      Base Constructor" << std::endl;
    }
    virtual ~Base(){
        std::cout << "      Base Destructor" << std::endl;
    }
private:
    Base_Member bm;
};

class Derived : public Base{
public:
    Derived(){
        std::cout << "      Derived Constructor" << std::endl;
    }
    ~Derived(){
        std::cout << "      Derived Destructor" << std::endl;
    }
private:
    Derived_Member dm;
};

int main(){
    //派生类指针指向派生类对象
    std::cout << "------派生类指针指向派生类对象------" << std::endl;
    Derived* pDerived = new Derived();
    delete pDerived;
    std::cout << std::endl;

    //派生类指针不可以指向基类对象

    //基类指针指向基类对象
    std::cout << "------基类指针指向基类对象------" << std::endl;
    Base* pBase1 = new Base();
    delete pBase1;
    std::cout << std::endl;

    //基类指针指向派生类对象
    std::cout << "------基类指针指向派生类对象------" << std::endl;
    Base* pBase2 = new Derived();
    delete pBase2;
    std::cout << std::endl;
}