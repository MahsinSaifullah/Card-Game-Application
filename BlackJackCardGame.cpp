#include "Deck.h"
#include "BlackJackCard.h"
#include "CardGame.h"
#include "BlackJackCardGame.h"
#include "helperFunctions.h"
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;




BlackJackCardGame::BlackJackCardGame()
{
  deck.shuffleDeck();
}

void BlackJackCardGame::play()
{
  string input;

  do {
    clearConsole();
    cout<<"********* BLACK JACK **************"<<endl;
    cout<<endl;
    roundNumber++;
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
      cout<<"Total Value = "<<calculateUserTotalValue()<<endl;
      cout<<endl;
      cout<<"Do you want [s]tick, [t]wist or [q]uit the game?"<<endl;
      cin>>input;
      toUpperCase(input);

      if(input == "S" || calculateUserTotalValue() >= 21 || user.numOfCardsInHand() >= 5) break;
      else if(input == "T")
      {
        user.takeCard(deck.deal());
        if(calculateUserTotalValue() >= 21) break;
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

    if(calculateUserTotalValue() > 21)
    {
      cout<<"Your Hand is..."<<endl;
      cout<<endl;
      bank.showCardInHand();
      cout<<"BUST!!!"<<endl;
      cout<<endl;
      cout<<"Bad Luck, the bank won"<<endl;
      cout<<endl;
      roundInfo[roundNumber] = "Lost";
     }
     else if(calculateUserTotalValue() == 21)
     {
       cout<<"Your Hand is..."<<endl;
       cout<<endl;
       user.showCardInHand();
       cout<<"Total Value = "<<calculateUserTotalValue()<<endl;
       cout<<endl;
       cout<<"!!!! BLACK JACK !!!!"<<endl;
       cout<<"Well done...you won"<<endl;
       cout<<endl;
       roundInfo[roundNumber] = "Won";
     }
     else{
       cout<<"Bank's Hand is..."<<endl;
       cout<<endl;
       user.showCardInHand();
       cout<<"Total Value = "<<calculateBankTotalValue();
       cout<<endl;
       while (calculateBankTotalValue()<=calculateUserTotalValue() && calculateBankTotalValue()<=21 && bank.numOfCardsInHand() < 5 )
       {
         bank.takeCard(deck.deal());
         cout<<endl;
         cout<<"The bank draws a card..."<<endl;
         cout<<endl;
         bank.showCardInHand();
         cout<<"Total Value = "<<calculateBankTotalValue();
         cout<<endl;
       }

       if(calculateBankTotalValue() > 21)
       {
         cout<<endl;
         cout<<"BUST..."<<endl;
         cout<<endl;
         cout<<"Well done, you won!!!"<<endl;
         roundInfo[roundNumber] = "Won";
       }
       else if(calculateUserTotalValue() > calculateBankTotalValue())
       {
         cout<<endl;
         cout<<"Well done, you won!!!"<<endl;
         roundInfo[roundNumber] = "Won";
       }
       else if(calculateUserTotalValue() == calculateBankTotalValue() && user.numOfCardsInHand() >= bank.numOfCardsInHand())
       {
         cout<<endl;
         cout<<"Well done, you won!!!"<<endl;
         roundInfo[roundNumber] = "Won";
       }
       else
       {
         cout<<endl;
         cout<<"Bad Luck, the bank won"<<endl;
         cout<<endl;
         roundInfo[roundNumber] = "Lost";
       }

     }

     do {
       cout<<endl;
       cout<<"Do you want to play again ([y]es or [n]o) ?"<<endl;
       cin>>input;
       toUpperCase(input);

       if(input == "Y") break;
       else if(input == "N") return;
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
  cout<<endl;
  cout<<"***** BlackJack Card Game Stats ******"<<endl;
  cout<<endl;
  cout<<"Total Rounds Played: "<<roundInfo.size()<<endl;
  cout<<"Won: "<<winCount()<<endl;
  cout<<"Lost: "<<(roundInfo.size() - winCount())<<endl;
  cout<<"---------------------------------"<<endl;

  for(auto round : roundInfo)
  {
    cout<<"Round "<<round.first<<": "<<round.second<<endl;
  }

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

int BlackJackCardGame::winCount()
{
  int count=0;

  for(auto round : roundInfo)
  {
    if(round.second == "Won") count++;
  }

  return count;
}
