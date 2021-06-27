#pragma pack(1)
#include <iostream>

class Animal{
public:
    int data_Animal;
};

class Beauty : public virtual Animal{
public:
    int data_Beauty;
};

class Fish : public virtual Animal{
public:
    int data_Fish;
};

class BeautyFish : public Beauty, public Fish{
public:
    int data_BeautyFish;
};
#pragma pack()

int main(){
    Animal a;
    Beauty b;
    Fish f;
    BeautyFish bf;
    bf.data_Animal = 10;
    bf.data_Beauty = 100;
    bf.data_Fish = 1000;
    bf.data_BeautyFish = 10000;
    std::cout << "sizeof(Animal) == " << sizeof(Animal) << std::endl;
    std::cout << "sizeof(Beauty) == " << sizeof(Beauty) << std::endl;
    std::cout << "sizeof(Fish) == " << sizeof(Fish) << std::endl;
    std::cout << "sizeof(BeautyFish) == " << sizeof(BeautyFish) << std::endl;
}