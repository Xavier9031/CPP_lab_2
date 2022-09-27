#include <iostream>
#include <vector>
using namespace std;

string suits[4] = { "黑桃", "梅花", "愛心", "方塊" };
string faces[13] = { 
  "A", "2", "3", "4", "5", "6", "7",
  "8", "9", "10","J", "Q", "K"
};

class Card {
  private:
    int suit, face;
  public:
    Card(int s,int f){
      suit = s;
      face = f; 
    }
    void toString(){
      cout << suits[suit] << faces[face]<< endl;
    }
};

class Cards {
  private:
    vector<Card> cards;
    int currentCard;
  public:
    Cards(){
      for (int i = 0; i < 4; i++)
        for (int j = 0; j < 13; j++)
          cards.push_back(Card(i,j));
      }
      void shuffle(){
        srand(time(NULL));
        for(int i = 0; i < 52; i++){
          int index = i + rand()%(52-i);
          swap(cards[index], cards[i]);
        }
      }
      void show(){
        for(int i = 0; i < 6; i++){
          cards[i].toString();
        }
    }
};

int main(){   
  Cards cards;
  cout << "===== 洗牌前 =====\n";
  cards.show();
  cout << "===== 洗牌後 =====\n";
  cards.shuffle();
  cards.show();
}
