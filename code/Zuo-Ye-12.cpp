#include <iostream>
#include <cmath>
using namespace std;

class Shape{
  public:
  virtual void get_size(){
    cout << "Print class area: " << endl;
  }
};

class Point{
  protected:
    double x, y;
  public:
    Point(double in_x, double in_y){
      x = in_x;
      y = in_y;
    };
    double operator-(Point b){
      double tmp_x, tmp_y, distance;
      tmp_x = x - b.get_x();
      tmp_y = y - b.get_y();
      distance = sqrt(tmp_x*tmp_x + tmp_y*tmp_y);
      return distance;
    };
    double get_x(){
      return x;
    }
    double get_y(){
      return y;
    }
};

class Square{
  protected:
    double Square_Area;
  public:
    Square(Point p1, Point p2){
      double line = p1-p2;
      Square_Area = line*line;
    };
};

class Cube:public Square, public Shape{
  private:
    double cube_size;
  public:
    Cube(Point p1,Point p2, Point p3): Square(p1,p2){
      double high = p1-p3;
      cube_size = Square_Area*high;
    };
    void get_size(){
    cout << "Print cube area: " << cube_size << endl;
  }
};

class Circle{
  protected:
    double Circle_Area;
  public:
    Circle(Point p1, Point p2){
      double line = p1-p2;
      Circle_Area = line*line*M_PI;
    };
};

class Cylinder:public Circle, public Shape{
  private:
    double Cylinder_size;
  public:
    Cylinder(Point p1, Point p2, Point p3): Circle(p1,p2){
      double high = p1-p3;
      Cylinder_size = Circle_Area*high;
    };
    void get_size(){
    cout << "Print cylinder area: " << Cylinder_size << endl;
  }
};

int main() {
  Cube cube(Point(0,0),Point(0,5),Point(5,0));
  Shape *s1 = &cube;
  s1->get_size();

  Cylinder cylinder(Point(0,0),Point(0,5),Point(5,0));
  Shape *s2 = &cylinder;
  s2->get_size();

  return 0;
}