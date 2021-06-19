## C++对象基本模型
所谓C++对象模型，可以理解为对于各种支持的底层实现机制，这里我们简单关注C++对象在内存中的布局。
C++类的成员可以归纳为两大类五小类：
- 成员函数
    - 静态成员函数(static member functions)
    - 非静态成员函数(non-static member functions)
    - 虚成员函数(virtual member functions)
- 数据成员
    - 静态数据成员(static data members)
    - 非静态数据成员(non-static data members)

那么，我们可以定义这样一个类Base，在不考虑继承的情况下，它囊括了所有可能的成员。
```c++
class Base{
public:
    static int fun_1(); //static member function
    int fun_2(); //non-static member function
    virtual int fun_3(){} //virtual member function
private:
    static int data_1; //static data member
    int data_2; //non-static data member
};
```
对于这样一个类Base，实例化后，它的对象占多少字节呢？先给出答案：
- 在32位机器上，sizeof(Base)得到的值为8；
- 在64位机器上，sizeof(Base)得到的值为16。

为什么是这样的值呢？这是由C++对象模型所决定的。在C++对象模型中：
- 非静态数据成员（如data_2）由类的每个对象各自保存；
- 静态数据成员只分配一次内存，由类的所有对象共用；
- 静态成员函数和非静态成员函数存储在代码段；
- 虚成员函数则以以下2个步骤支持之：
    - 类产生一堆指向虚成员函数的指针，这些指针放在一个表中，称为虚函数表(virtual table)。
    - 类的每个对象都存储一个指针vptr，它指向虚函数表。
