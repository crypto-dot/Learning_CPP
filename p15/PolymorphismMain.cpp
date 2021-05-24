//
// Created by Carlos Arbizu on 4/29/21.
//
#include <iostream>
using std::cout;
using std::endl;
#include <vector>
using std::vector;

class Shape {

public:
    virtual void draw() =0;
    virtual void rotate()=0;
    virtual ~Shape() {};
};

class Open_Shape : public Shape{
public:
    virtual ~Open_Shape() {};
};

class Closed_Shape : public Shape {
public:
    virtual ~Closed_Shape() {};
};
class Line : public Open_Shape{
private:
    size_t num_of_rotations {0};
public:
    virtual void draw() override{
        if(num_of_rotations % 2 ==0){
            cout << "-----" << endl;
        }
        else{
            for (size_t i{0}; i < 4; i++) {
                cout << "|" << endl;
            }
        }
    }
    virtual void rotate() override{
        ++num_of_rotations;
    }
    virtual ~Line() {};
};
class Circle : public Closed_Shape{
public:
    virtual void draw() override{
        cout << "drawing circle" << endl;
    }
    virtual void rotate() override{
        cout << "rotating circle" << endl;
    }
    virtual ~Circle() {};
};

class Square : public Closed_Shape{
public:
    virtual void draw() override{
        cout << "drawing square" << endl;
    }
    virtual void rotate() override{
        cout << "rotating square" << endl;
    }

};
void refreshShapes(const vector<Shape *> &shapes){
    for(const auto &shape : shapes){
        shape->draw();
    }
}
int main(){

    Line *line = new Line;
    line->draw();
    line->rotate();
    line->draw();
    Shape *p1 = new Circle();
    Shape *p2 = new Square();
    Shape *p3 = new Line();

    vector <Shape *> shapes {p1,p2,p3};
    refreshShapes(shapes);

    delete p1;
    delete p2;
    delete p3;

    return 0;
}