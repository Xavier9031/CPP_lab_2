#include <iostream>
#include <cmath>
using namespace std;

template<typename T, int Dim>
  class Point{
    protected:
      T *data;
    public:

      Point(){
        data = new T [Dim];
      };

      T operator-(Point<T,Dim> &b){
        T ds = 0;
        for(int i = 0; i < Dim; i++){
          ds += (data[i]- b.data[i])*(data[i]- b.data[i]);
        }
        return sqrt(ds);
      };

      void show(){
        for(int i = 0; i < Dim; i++){
          cout << data[i] <<' ';
        }
        cout << endl;
      }
  };

template<typename T>
  class Point2D:public Point<T, 2>{
    public:
      Point2D(): Point<T,2>(){
      }
      Point2D(T _x, T _y): Point<T,2>(){
        Point<T,2>::data[0] = _x;
        Point<T,2>::data[1] = _y;
      }
  };

template<typename T>
  class Point3D:public Point<T, 3>{
    public:
      Point3D(): Point<T,3>(){
      }
      Point3D(T _x, T _y, T _z): Point<T,3>(){
        Point<T,3>::data[0] = _x;
        Point<T,3>::data[1] = _y;
        Point<T,3>::data[2] = _z;
      } 
  };


int main() {
  Point2D<int> p2a(1,1);
  Point2D<int> p2b;

  p2a.show();
  p2b.show();
  cout << p2a - p2b << endl;
  cout << p2b - p2a << endl;

  cout << "==========" << endl;

  Point3D p3a(1.2,2.4,3.6);
  Point<double, 3> p3b;

  p3a.show();
  p3b.show();
  cout << p3a - p3b << endl;
  cout << p3b - p3a << endl;
}