#include <iostream>
#include <string>
using namespace std;

class LogicGate{
  protected:
    string label;
    bool output = 0;
  public:
  LogicGate(string n){
    label = n;
  }
  void setOutput(bool ANS){
    output = ANS;
  }
  void getOutput(){
    cout << "Output: " << output << endl;
  }

};
class UnaryGate: public LogicGate{
  protected:
    bool bool_0;
  public:
    UnaryGate(string name): LogicGate(name){
      bool input_0;
      cout << "Enter Pin input for gate " << name << "--> " ;
      cin >> input_0 ;
      cout << endl;
      bool_0 = input_0;
    }

};

class NotGate: public UnaryGate{
  public:
  NotGate(string name): UnaryGate(name){
    setOutput(!bool_0);
  }
};

class BinaryGate: public LogicGate{
  protected:
    bool bool_1,bool_2;
  public:
    BinaryGate(string name): LogicGate(name){
    bool input_1, input_2;
    cout << "Enter Pin input for gate " << name << "--> " ;
    cin >> input_1 ;
    cout << endl;
    bool_1 = input_1;
    cout << "Enter Pin input for gate " << name << "--> " ;
    cin >> input_2 ;
    cout << endl;
    bool_2 = input_2;
    }


};

class AndGate: public BinaryGate{
  public:
  AndGate(string name): BinaryGate(name){
    setOutput(bool_1 && bool_2);
  }
};
class OrGate: public BinaryGate{
  public:
  OrGate(string name): BinaryGate(name){
    setOutput(bool_1 || bool_2);
  }

};

int main() {
  string name;
  while(cin >> name){
    if(name == "and"){
      AndGate g1(name);
      g1.getOutput();
    }
    else if(name == "or"){
      OrGate g1(name);
      g1.getOutput();
    }
    else if(name == "not"){
      NotGate g1(name);
      g1.getOutput();
    }
  }
}