#include <iostream>
#include <string>
using namespace std;

struct Node{
  char c;
  int ascii;
  int count;
};

int main() {
  string s;
  Node nodes[52];
  for(int i = 0; i < 26; i++){
    nodes[i] = {
      char(i+65),
      i+65,
      0
    };
  }
  for(int i = 26; i < 52; i++){
    nodes[i] = {
      char(i+71),
      i+71,
      0
    };
  }

  while(getline(cin,s)){
    for(int i = 0;i < s.size(); i++){
      if(int(s[i]<91)){
        nodes[int(s[i])-65].count++;
      }else{
        nodes[int(s[i])-71].count++;
      }
    }
    for(int i = 0; i < 52; i++){
        if(nodes[i].count != 0){
          cout << nodes[i].c << "=>" << nodes[i].count << endl;
        }
      }
  }
}