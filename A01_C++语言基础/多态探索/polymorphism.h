#include <iostream>

class Point{
public:
    Point(float x = 0.0);
    virtual ~Point();
    virtual Point& mult(float) = 0;
    float x() const;
    virtual float y() const;
    virtual float z() const;
protected:    
    float _x;
};

class Point2d : public Point{
public:
    Point2d(float x = 0.0, float y = 0.0)
        : Point(x), _y(y) {
            std::cout << "Point2d 构造函数被调用" << std::endl;
        }
    ~Point2d();
    Point2d& mult(float);
    float y() const;
    virtual int fun() {}
protected:
    float _y;
};

class Point3d : public Point2d{
public:
    Point3d(float x = 0.0, float y = 0.0, float z = 0.0)
        : Point2d(x, y), _z(z) {
            std::cout << "Point3d 构造函数被调用" << std::endl;
        }
    ~Point3d();
    float z() const;
protected:
    float _z;
};