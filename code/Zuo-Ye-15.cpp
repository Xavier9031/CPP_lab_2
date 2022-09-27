#include <iostream>
#include <string>
#include <cmath>
using namespace std;


class Person{
  protected:
    string neme;
    int age;
  public:
    virtual void getdata(){
    }
    virtual void putdata(){
    }
};

class Professor: public Person{
  private:
    int publications;
  public:
    void getdata(){
      cout << neme << " " << age << " " << publications << endl;
    }
    void putdata(){
      string name_;
      int age_, pub_;
      cin >> name_ >> age_ >> pub_;
      neme = name_;
      age = age_;
      publications = pub_;
    }
};

class Student: public Person{
  private:
    int marks[6];
  public:
    void getdata(){
      int Sum = marks[0] + marks[1] + marks[2] + marks[3] + marks[4] + marks[5] ;
      cout << neme << " " << age << " " << Sum << " " << endl;
    }
    void putdata(){
      int age_, c0,c1,c2,c3,c4,c5;
      string name_;
      cin >> name_ >> age_ >> c0 >> c1 >> c2 >> c3  >> c4 >> c5 ;
      neme = name_;
      age = age_;
      marks[0]=c0;marks[1]=c1;marks[2]=c2;marks[3]=c3;marks[4]=c4;marks[5]=c5;
    }
};


int main() {
  int n, type ,age, pub;
  int mrk[6];
  string name;

  cout << "===== Input =====\n";
  cin >> n;
  Person *per[n];
  for(int i = 0; i < n; i++){
    cin >> type;
    if(type == 1){

      per[i] = new Professor;
      per[i]->putdata();
    
    }else if (type == 2){

      per[i] = new Student;
      per[i]->putdata();

    }
  }

  cout << "===== Output =====\n";
  for(int i = 0; i < n; i++){
    per[i]->getdata();
  }
  return 0;
}