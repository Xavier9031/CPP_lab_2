#include <iostream>
#include <string>
using namespace std;

int main() {
  string a;
  while(cin >> a){
    int b[10] = {0};
    for(int i = 0;i < a.size(); i++){
      b[int(a[i])-48]++;
    }
    for(int i = 0; i < 10; i++){
      cout << i << "=>" << b[i] << endl;
    }
  }
}