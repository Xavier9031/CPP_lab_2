#include <iostream>
#include <vector>
using namespace std;

class Set{
  private:
    vector <int> elements;
  public:
    Set operator|(Set b){
      Set tmp;
      for(int i = 0; i < elements.size(); i++){
        tmp.add(elements[i]);
      }
      for(int i = 0; i < b.get_elements().size(); i++){
        if(tmp.contain(b.get_elements()[i])){
          tmp.add(b.get_elements()[i]);
        }
      }
      return tmp;
    };
    Set operator&(Set b){
      Set tmp;
      for(int i = 0; i < b.get_elements().size(); i++){
        if(b.contain(elements[i])){
          tmp.add(b.get_elements()[i]);
        }
      }
      return tmp;
    };

    vector<int> get_elements(){
      return elements;
    }
    void set_elements(vector<int> in_elements){
      elements = in_elements;
    }

    void add(int x){
      elements.push_back(x);
    }
    bool contain(int x){
      bool t = true;
      for(int i = 0; i < elements.size(); i++){
        if(elements[i] == x){
          t = false;
          break;
        }
      }
      return t;
    }
    
    void show(){
      for(int i = 0; i < elements.size(); i++){
        cout << elements[i] << ' ';
      }
      cout << endl;
    }
};


int main() {
  vector <int> A_list = {1,2};
  vector <int> B_list = {2,4};

  Set A, B, C;
  A.set_elements(A_list);
  B.set_elements(B_list);

  C = A|B;
  C.show();

  C = A&B;
  C.show();
}