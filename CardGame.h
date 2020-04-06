#ifndef CARDGAME_H
#define	CARDGAME_H

#include "Deck.h"
#include <string>
#include <vector>

using namespace std;

template<class cardType>
class CardGame
{
public:
  virtual void play() = 0;
  virtual void showStat() = 0;


protected:
  Deck<cardType> deck;

};

#endif
