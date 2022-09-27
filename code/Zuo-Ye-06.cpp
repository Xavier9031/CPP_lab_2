#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime> 
using namespace std;

int fuc_rand(){
  srand( time(NULL) );
  int x = rand() % (999 - 100 + 1) + 100;
  return x;
}

class Book{
  private:
    string title, author ;
    int price ;
    static int max_price;
    static string max_price_title; 
  public:
    Book(string t, int p = fuc_rand() , string a = ""){
        title = t;
        author = a;
        price = p;
        max();
      };
      void max(){
        if(price >= max_price){
          max_price = price;
          max_price_title = title;
        }
      }
    void f(){
      cout << "the max price book is "<< max_price_title << " ( " << max_price << " )";
    }
};

int Book::max_price = 0;
string Book::max_price_title = "";

int main() {
  Book b1("AAA");
  Book b2("BBB", 123);
  Book b3("CCC", 369, "Bob");
  b3.f();
  
}