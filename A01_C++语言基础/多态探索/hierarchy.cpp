#pragma pack(1)
#include <iostream>

class Animal{
public:
    virtual ~Animal(){}
private:
    int data_Animal;
};

class Beauty : public virtual Animal{
public:
    ~Beauty(){}
private:
    int data_Beauty;
};

class Fish : public virtual Animal{
public:
    ~Fish(){}
private:
    int data_Fish;
};

class BeautyFish : public Beauty, public Fish{
public:
    ~BeautyFish(){}
private:
    int data_BeautyFish;
};
#pragma pack()

int main(){
    Animal a;
    Beauty b;
    Fish f;
    BeautyFish bf;
    std::cout << "sizeof(Animal) == " << sizeof(Animal) << std::endl;
    std::cout << "sizeof(Beauty) == " << sizeof(Beauty) << std::endl;
    std::cout << "sizeof(Fish) == " << sizeof(Fish) << std::endl;
    std::cout << "sizeof(BeautyFish) == " << sizeof(BeautyFish) << std::endl;
}