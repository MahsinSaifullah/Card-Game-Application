#include "Deck.h"
#include "BlackJackCard.h"
#include "CardGame.h"
#include "BlackJackCardGame.h"
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

//clears the terminal
void clearConsole()
{
  cout << "\033[2J\033[1;1H";;
}

//converts each letter of the string to uppercase
void toUpperCase(string &mystring)
{
  transform(mystring.begin(), mystring.end(), mystring.begin(), ::toupper);
}


BlackJackCardGame::BlackJackCardGame()
{
  deck.shuffleDeck();
}

void BlackJackCardGame::play()
{
  string input;

  do {
    clearConsole();
    deck.resetDeck();
    deck.shuffleDeck();
    user.clearHand();
    bank.clearHand();

    user.takeCard(deck.deal());
    user.takeCard(deck.deal());

    bank.takeCard(deck.deal());
    bank.takeCard(deck.deal());

    do {
      cout<<"Your Hand is..."<<endl;
      cout<<endl;
      user.showCardInHand();
      cout<<"Total Value = "<<calculateUserTotalValue();
      cout<<endl;
      cout<<"Do you want [s]tick, [t]wist or [q]uit the game?"<<endl;
      cin>>input;
      toUpperCase(input);

      if(input == "S" || calculateUserTotalValue() > 21 || user.numOfCardsInHand() >= 5) break;
      else if(input == "T")
      {
        user.takeCard();
        continue;
      }
      else if(input == "Q") return;
      else
      {
        cout<<"Invalid Choice...Please try again"<<endl;
        cout<<endl;
        continue;
      }
    } while(true);






  } while(true);

}


void BlackJackCardGame::showStat()
{
  clearConsole();

}

int BlackJackCardGame::calculateUserTotalValue()
{
  vector<BlackJackCard> *userCards = user.getCardInHand();
  int totalValue = 0;

  for(auto card : *userCards) totalValue += card.getCardValue();

  return totalValue;
}

int BlackJackCardGame::calculateBankTotalValue()
{
  vector<BlackJackCard> *bankCards = bank.getCardInHand();
  int totalValue = 0;

  for(auto card : *bankCards) totalValue += card.getCardValue();

  return totalValue;
}
