#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Point{
  private:
    float x, y;
    static float p1[2], p2[2], max_distance;
  public:
    Point(int in_x, int in_y){
      x = in_x;
      y = in_y;
    };
    float operator-(Point b){
      float tmp_x, tmp_y, distance;
      tmp_x = x - b.get_x();
      tmp_y = y - b.get_y();
      distance = sqrt(tmp_x*tmp_x + tmp_y*tmp_y);
      return distance;
    };
    float get_x(){
      return x;
    }
    float get_y(){
      return y;
    }
    float get_md(){
      return max_distance;
    }
    void set_p(float x1, float x2, float y1, float y2, float md){
      p1[0] = x1;
      p1[1] = x2;
      p2[0] = y1;
      p2[1] = y2;
      max_distance = md;
    }
    void show(){
      cout << "Point: (" << p1[0] << ", " <<  p1[1] << ")" << endl;
      cout << "Point: (" << p2[0] << ", " <<  p2[1] << ")" << endl;
      cout << "distance: " << max_distance;
    }
};

float Point::p1[2];
float Point::p2[2];
float Point::max_distance = 0;

int main() {
  vector <Point> points;
  float distance, x ,y;
  while(cin >> x >> y){
    points.push_back(Point(x,y));
  }

  for(int i = 0; i < points.size(); i++){
    for(int j = i+1; j < points.size(); j++){
      distance = points[i] - points[j];
      if(distance > points[0].get_md()){
        points[0].set_p(points[i].get_x(), points[i].get_y(), points[j].get_x(), points[j].get_y(), distance);
      }
    }
  }

  points[0].show();
  return 0;
}