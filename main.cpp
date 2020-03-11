#include "PlayingCard.h"
#include "Deck.h"
#include <iostream>
#include <vector>
#include <string>


int main()
{

  Deck<PlayingCard> deck;

  deck.shuffleDeck();

  deck.deal().showCard();
  deck.deal().showCard();
  deck.deal().showCard();

  cout<<deck.remainingCards()<<endl;







  return 0;
}
