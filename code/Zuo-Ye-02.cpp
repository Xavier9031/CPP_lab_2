#include <iostream>
#include <string>
using namespace std;

int main() {
  string a;
  int max = 0;
  while(cin >> a){
    int b[52] = {0};
    for(int i = 0;i < a.size(); i++){
      if(int(a[i]<91)){
        b[int(a[i])-65]++;
      }else{
        b[int(a[i])-71]++;
      }
    }
    for(int i = 0 ; i < 52; i++){
      if(b[i]>max){
        max = b[i];
      }
    }
    for(int j = 1; j <= max; j++){
      for(int i = 0; i < 52; i++){
        if(b[i] == j){
          if(i < 26){
            cout << char(i+65) << "=>" << b[i] << endl;
          }else{
            cout << char(i+71) << "=>" << b[i] << endl;
          }
        }
      }
    }
    
  }
}