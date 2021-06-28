#include <iostream>

class Mammal{
private:
    int temperature;
};

class Bear : public  Mammal{
private:
    int claw;
};

class Cat : public  Mammal{
private:
    int color;
};

class Panda : public Bear, public Cat{
private:
    int skin;
};

int main(){
    Mammal mammal;
    Bear bear;
    Cat cat;
    Panda panda;
    std::cout << "sizeof(Mammal) == " << sizeof(Mammal) << std::endl;
    std::cout << "sizeof(Bear) == " << sizeof(Bear) << std::endl;
    std::cout << "sizeof(Cat) == " << sizeof(Cat) << std::endl;
    std::cout << "sizeof(Panda) == " << sizeof(Panda) << std::endl;
}