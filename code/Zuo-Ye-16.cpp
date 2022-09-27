//學號: 1082414 姓名: 張恆達
/*延續作業#11、作業#14，繼承BinaryGate實作NANDGate，並繼承LogicGate實作一個用NAND設計的SR Flip-Flop Circuit*/

#include <iostream>
#include <string>
using namespace std;

//邏輯閘
class LogicGate{
  protected:
    string label; //閘名
    bool output = 0;//輸出值(預設false)
  public:
  //建構子
  LogicGate(string n){
    label = n;
  }
  //設定輸出值
  void setOutput(bool ANS){
    output = ANS;
  }
  //取得運算結果
  bool getOutput(){
    output = performGateLogic();
    return output;
  }
  //執行運算(虛擬函式)
  virtual bool performGateLogic(){
    return 0;
  }
  //設定輸入(虛擬函式)
  virtual void setNextPin(bool a){}

};

//單一變數的邏輯閘(繼承LogicGate)
class UnaryGate: public LogicGate{
  protected:
    bool bool_0 = 0;//輸入值(預設false)
  public:
  //建構子
   UnaryGate(string name): LogicGate(name){
    }
  //設定輸入值
  void setNextPin(bool in_0){
    bool_0 = in_0;
  }
};

//NOT運算(繼承UnaryGate)
class NotGate: public UnaryGate{
  public:
  //建構子
  NotGate(string name): UnaryGate(name){
  }
  //執行運算並回傳結果
  bool performGateLogic(){
    return !bool_0;
  }
};

//雙變數的邏輯閘(繼承LogicGate)
class BinaryGate: public LogicGate{
  protected:
    //輸入值1, 輸入值2, 判斷點
    bool bool_1 = 0 ,bool_2 = 0, flag = 1;
  public:
  //建構子
  BinaryGate(string name): LogicGate(name){
  }
  //用flag判斷地一個輸入還是第二個輸入並設定輸入值
  void setNextPin(bool in_1){
    if(flag){
      bool_1 = in_1;
      flag = 0;
    }else{
      bool_2 = in_1;
    }
  }
};

//AND運算(繼承BinaryGate)
class AndGate: public BinaryGate{
  public:
  //建構子
  AndGate(string name): BinaryGate(name){
  }
  //執行運算並回傳結果
  bool performGateLogic(){
    return (bool_1 && bool_2);
  }
};

//OR運算(繼承BinaryGate)
class OrGate: public BinaryGate{
  public:
  //建構子
  OrGate(string name): BinaryGate(name){
  }
  //執行運算並回傳結果
  bool performGateLogic(){
    return (bool_1 || bool_2);
  }
};

//NOR運算(繼承BinaryGate)
class NorGate: public BinaryGate{
  public:
  //建構子
  NorGate(string name): BinaryGate(name){
  }
  //執行運算並回傳結果
  bool performGateLogic(){
    return (!(bool_1 || bool_2));
  }
};

//NAND運算(繼承BinaryGate)
class NANDGate: public BinaryGate{
  public:
  //建構子
  NANDGate(string name): BinaryGate(name){
  }
  //執行運算並回傳結果
  bool performGateLogic(){
    return (!(bool_1 && bool_2));
  }
};

//連接器
class Connector{
  //從fromgat接到togate
  LogicGate *fromgate, *togate;
  public:
  //建構子
    Connector(LogicGate *fgate, LogicGate *tgate){
      fromgate = fgate;
      togate = tgate;
      tgate->setNextPin(fromgate->getOutput());
    }
};

//用NANDGate實作SRGate
class SRGate: public LogicGate{
  protected:
  //先預設S, R, Q 為 false
    bool S = 0, R = 0, Q = 0;
  public:
  //多形建構子依輸入數量判斷輸入設定
  SRGate(string name, int s_, int r_, int q_): LogicGate(name){
    S = s_;
    R = r_;
    Q = q_;
  }
  SRGate(string name, int s_, int r_): LogicGate(name){
    S = s_;
    R = r_;
  }
  //執行運算並回傳結果
  bool performGateLogic(){
    bool ans_bool ;

    //建立SRGATE電路
    NANDGate g1("A");
    NANDGate g2("B");
    NotGate g3("C");
    NotGate g4("D");

    g3.setNextPin(R);
    g1.setNextPin(g3.getOutput());
    g1.setNextPin(Q);

    g2.setNextPin(g1.getOutput());
    g4.setNextPin(S);
    g2.setNextPin(g4.getOutput());

    ans_bool = g2.getOutput();

    //回傳結果
    return (ans_bool);
  }
};

//主函式
int main() {
  SRGate s1("SR",0,0);
  bool q1 = s1.getOutput();
  cout << "000 => " << q1 <<endl;

  SRGate s2("SR",0,0,q1);
  bool q2 = s2.getOutput();
  cout << "000 => " << q2 <<endl;

  SRGate s3("SR",1,0,q2);
  bool q3 = s3.getOutput();
  cout << "100 => " << q3 <<endl;

  SRGate s4("SR",0,1,q3);
  bool q4 = s4.getOutput();
  cout << "011 => " << q4 <<endl;

  return 0;
}