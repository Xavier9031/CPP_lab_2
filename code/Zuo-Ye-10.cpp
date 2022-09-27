#include <iostream>
#include <cmath>
using namespace std;

class twoDPoint{
  protected:
    double x, y;
  public:
    twoDPoint(double in_x, double in_y){
      x = in_x;
      y = in_y;
    };
    double operator-(twoDPoint b){
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

class threeDPoint: public twoDPoint{
  private:
    double z;
  public:
    threeDPoint(double in_x, double in_y, double in_z) : twoDPoint(in_x, in_y), z(in_z) {}
    double operator-(threeDPoint b){
      double tmp_x, tmp_y, tmp_z, distance;
      tmp_x = x - b.get_x();
      tmp_y = y - b.get_y();
      tmp_z = z - b.get_z();
      distance = sqrt(tmp_x*tmp_x + tmp_y*tmp_y + tmp_z*tmp_z);
      return distance;
    };
    double get_z(){
      return z;
    }
};

int main() {
  twoDPoint p1(5, 0), p2(0,12);
  cout << p1 - p2 << endl;
  
  threeDPoint p3(1, 1, 1), p4(2,3, 4);
  cout << p3 - p4 << endl;
}