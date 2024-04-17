#include<iostream> 

class Shape {
public:
    virtual void draw() {
        std::cerr << "Drawing a shape" << std::endl;
    }
};

class Circle : public Shape {
protected: 
    long _r;
public:
    Circle(long r) : _r(r) {}
    void draw() override {
        std::cerr << "Drawing a circle with radius: " << _r << std::endl;
    }
};

void draw_shapes(Shape *table[], size_t n) {
    for(size_t i = 0; i < n; ++i)
        table[i]->draw();
}

int main() {
    Shape* shapes[2];
    shapes[0] = new Circle(5);
    shapes[1] = new Circle(10);

    draw_shapes(shapes, 2);  // This will call the draw method of Circle for each shape

    delete shapes[0];
    delete shapes[1];
    return 0;
}