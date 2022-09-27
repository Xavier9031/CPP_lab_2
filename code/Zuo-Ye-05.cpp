#include <iostream>
using namespace std;

class Rectangle {
  private:
    int length;
    int width;
  public:
    void set_length(int l);
    void set_width(int w);
    void draw(void);
};
void Rectangle::draw(void){
  for(int i = 0; i < length; i++){
    cout << '*';
  }
  cout << "\n";
  for(int i = 0; i < (width-2); i++){
    cout << '*';
    for(int i = 0; i < (length-2); i++){
      cout << ' ';
    }
    cout << "*\n";
  }
  for(int i = 0; i < length; i++){
    cout << '*';
  }
  cout << "\n";
};
void Rectangle::set_length(int l){
  length = l;
};
void Rectangle::set_width(int w){
  width = w;
};

int main() {
  Rectangle R1;
  int a, b;
  cin >> a >> b;
  R1.set_length(a);
  R1.set_width(b);
  R1.draw();
}