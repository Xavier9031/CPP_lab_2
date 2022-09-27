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
  bool getOutput(){
    output = performGateLogic();
    return output;
  }
  virtual bool performGateLogic(){
    return 0;
  }
  virtual void setNextPin(bool a){}

};
class UnaryGate: public LogicGate{
  protected:
    bool bool_0 = 0;
  public:
   UnaryGate(string name): LogicGate(name){
    }
  void setNextPin(bool in_0){
    bool_0 = in_0;
  }
};

class NotGate: public UnaryGate{
  public:
  NotGate(string name): UnaryGate(name){
  }
  bool performGateLogic(){
    return !bool_0;
  }
};

class BinaryGate: public LogicGate{
  protected:
    bool bool_1 = 0 ,bool_2 = 0, flag = 1;
  public:
  BinaryGate(string name): LogicGate(name){
  }
  void setNextPin(bool in_1){
    if(flag){
      bool_1 = in_1;
      flag = 0;
    }else{
      bool_2 = in_1;
    }
  }
};

class AndGate: public BinaryGate{
  public:
  AndGate(string name): BinaryGate(name){
  }
  bool performGateLogic(){
    return (bool_1 && bool_2);
  }
};
class OrGate: public BinaryGate{
  public:
  OrGate(string name): BinaryGate(name){
  }
  bool performGateLogic(){
    return (bool_1 || bool_2);
  }

};

class Connector{
  LogicGate *fromgate, *togate;
  public:
    Connector(LogicGate *fgate, LogicGate *tgate){
      fromgate = fgate;
      togate = tgate;
      tgate->setNextPin(fromgate->getOutput());
    }
};

int main() {
  AndGate g1("A");
  OrGate g2("B");
  OrGate g3("C");
  NotGate g4("B");

  g1.setNextPin(1);
  g1.setNextPin(1);
  g2.setNextPin(0);
  g2.setNextPin(0);

  Connector c1(&g1, &g3);
  Connector c2(&g2, &g3);
  Connector c3(&g3, &g4);

  cout << "Output : " << g4.getOutput() << endl;
  

  return 0;
}