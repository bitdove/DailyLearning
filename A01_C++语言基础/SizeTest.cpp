#include <iostream>

int main(int argc, char* argv[]){
    std::cout << "sizeof(bool) = " << sizeof(bool) << std::endl
              << "sizeof(char) = " << sizeof(char) << std::endl
              << "sizeof(short int) = " << sizeof(short int) << std::endl
              << "sizeof(int) = " << sizeof(int) << std::endl
              << "sizeof(unsigned int) = " << sizeof(unsigned int) << std::endl
              << "sizeof(unsigned long) = " << sizeof(unsigned long) << std::endl
              << "sizeof(long) = " << sizeof(long) << std::endl
              << "sizeof(long long) = " << sizeof(long long) << std::endl
              << "sizeof(float) = " << sizeof(float) << std::endl
              << "sizeof(double) = " << sizeof(double) << std::endl
              << "sizeof(long double) = " << sizeof(long double) << std::endl;
    return 0;
}