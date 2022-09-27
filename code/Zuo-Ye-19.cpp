#include <iostream>
#include <vector>
using namespace std;

template <typename T>
  class Stack {
  vector<T> elems;
  int topIndex = -1;
  public:
    void push(T _in){
      elems.push_back(_in);
      topIndex++;
    };
    T pop(){
      T temp = elems[topIndex];
      elems.pop_back();
      topIndex--;
      return temp;
    };

    T top(){
      return elems[topIndex];
    };

};

int main() {

  Stack<int> intStack;
  intStack.push(1);
  intStack.push(2);
  intStack.push(3);
  cout << intStack.pop() << endl;
  cout << intStack.top() << endl;

  Stack<string> stringStack;
  stringStack.push("hello");
  stringStack.push("world");
  cout << stringStack.top() << endl;
  
}