#include "polymorphism.h"

int main(){
    Point* ptr = new Point3d;
    ptr->z();
    delete ptr;
    Point2d p2;
    Point3d p3;
}