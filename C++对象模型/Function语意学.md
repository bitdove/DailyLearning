## 引言

在C++中，有三种成员函数,按照加入C++的先后顺序排列如下：
- nonstatic member functions
- virtual member functions
- static member functions
经过编译器的处理之后，这三种成员函数的调用方式是不相同的，下边我们一个一个看。

我们提供这样一个类Point3d，作例子：
```cpp
class Point3d {
public:
    float magnitude() const;
private:
    float _x;
    float _y;
    float _z;
}

float Point3d::magnitude() const{
    return sqrt(_x * _x + _y * _y + _z * _z);
}
```

## Nonstatic Member Functions

C++有这样一个设计准则：非静态成员函数至少要和一般的非成员函数有相同的效率。也就是说，如下两个函数：

```cpp
float magnitude3d(const Point3d* _this){...} //非成员函数
float Point3d::magnitude3d() const {...}     //成员函数
```
选择第二个函数不应该给程序带来性能上的损失，否则我还不如直接选第一个函数（不让它做类的成员函数）。

那编译器是怎么保证这个原则的呢？答案是编译器内部会把成员函数转换为对等的非成员函数。
举个例子，下面是magnitude()的非成员函数版定义：
```cpp
float magnitude(const Point3d* _this){
    return sqrt(_this->_x * _this->_x +
                _this->_y * _this->_y +
                _this->_z * _this->_z);
}
```
乍一看，成员函数版应该效率更高，因为它直接取用_x,_y,_z这三个成员，而非成员函数版要通过指针间接取用。其实不然，因为成员函数版会被编译器内化为非成员函数版，转化步骤如下;
1. 改写函数原型，安插一个额外的参数（this指针）到成员函数。
    - 非const的非静态成员函数改写如下：
        ```cpp
        Point3d::magnitude(Point3d *const this)
        ```
    > 即添加了一个指针常量this。
    - const的非静态成员函数改写如下：
        ```cpp
        Point3d::magnitude(const Point3d* const this)
        ```
    > 即添加一个指向常量的指针常量。
2. 把每一个对非静态数据成员的存取操作改成通过this指针来存取：
    ```cpp
    {
        return sqrt(
            this->_x * this->_x +
            this->_y * this->_y +
            this->_z * this->_z
        );
    }
    ```
3. 将成员函数重新写成一个外部函数。将函数名称通过“mangling”，使它称为程序中独一无二的词汇：
    ```cpp
    extern magnitude__7Point3dFv(register Point3d* const this);
    ```