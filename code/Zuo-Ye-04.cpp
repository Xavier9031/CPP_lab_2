#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;



class Book {
  private:
    int price;
  public:
    void set(int p);
    double get(void);
    
};
void Book::set(int p){
  price = p;
};
double Book::get(void){
  return price ;

};

void swap(Book &n, Book &k){
  Book i = n;
  n = k;
  k = i;
}

int main() {
  srand(time(NULL));

  int n = 10;
  Book books[n];

  books[0].set(30);
  for(int i = 0; i < n; i++){
    books[i].set(rand() % 1000);
  }

  for(int i = 0; i < n; i++){
    for(int j = i; j < n; j++){
      if(books[i].get() > books[j].get()){
        swap(books[i], books[j]);
      }
    }
  }

  for(int i = 0; i < n; i++){
    cout << books[i].get() << endl;
  }


}