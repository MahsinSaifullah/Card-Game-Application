#ifndef BLACKJACKCARD_H
#define	BLACKJACKCARD_H
#include <string>
#include "PlayingCard.h"

using namespace std;

class BlackJackCard : public PlayingCard
{
public:
  BlackJackCard();
  BlackJackCard(string, string);
  int getCardValue();
  void setCardValue(int);

private:
  int cardValue;

};

#endif
