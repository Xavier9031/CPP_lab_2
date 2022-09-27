#include <iostream>
#include <string>
using namespace std;

template <typename T>
  class A {
  T *data;
  int _size;
  int _index = 0;
  public:
    A(int size){
      _size = size;
	    data = new T [size];
    };
    void setValue(int index, T value){
      _index = index;
      data[_index] = value;
      _index++;
    };
    void setValue(T value){
      data[_index] = value;
      _index++;
    };
    int getValue(int index){
      return data[index];
    };

};

int main() {
  A<int> intA(3);
  intA.setValue(1);
  intA.setValue(2);
  intA.setValue(3);
  for(int i = 0; i < 3; i++){
    cout << intA.getValue(i) << " ";
  }

  cout << "\n";

  A<double> doubleA(3);
  doubleA.setValue(1);
  doubleA.setValue(2);
  doubleA.setValue(0,999);
  doubleA.setValue(3);
  doubleA.setValue(4);
  for(int i = 0; i < 3; i++){
    cout << doubleA.getValue(i) << " ";
  }
}