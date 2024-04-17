#include<iostream> 

class Circle {
protected: 
    long _r;
public:
    Circle(long r) : _r(r) {}
    void draw() {
        std::cerr << "Drawing a circle with radius: " << _r << std::endl;
    }
};

class Drawable {
public:
  void draw() {
    std::cerr << "Drawable instance" << std::endl;
  }
};

template<typename T> 
void draw_template(T table[],size_t n) {
  for(size_t i=0;i<n;++i) {
    table[i].draw();
  }
} 


int main() {
  Drawable table_d[1]={Drawable()};
  Circle   table_c[2]={Circle(10),Circle(5)};

  draw_template(table_d,1);
  draw_template(table_c,2);

  return 0;
}