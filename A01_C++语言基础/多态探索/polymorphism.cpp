#include "polymorphism.h"

Point::~Point(){
    std::cout << "Point 析构函数被调用" << std::endl;
}

float Point::x() const {
    std::cout << "Point x()被调用" << std::endl;
    return _x;
}

float Point::y() const {
    std::cout << "Point y()被调用" << std::endl;
    return 0;
}

float Point::z() const {
    std::cout << "Point z()被调用" << std::endl;
    return 0;
}

Point::Point(float x ){
    _x = x;
    std::cout << "Point 构造函数被调用" << std::endl;
}

Point2d::~Point2d(){
    std::cout << "Point2d 析构函数被调用" << std::endl;
}

Point2d& Point2d::mult(float){
    
}

float Point2d::y() const {
    std::cout << "Point2d y()被调用" << std::endl;
    return _y;
}

Point3d::~Point3d(){
    std::cout << "Point3d 析构函数被调用" << std::endl;
}


float Point3d::z() const {
    std::cout << "Point3d z()被调用" << std::endl;
    return _z;
}