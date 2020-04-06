#ifndef BLACKJACKCARDGAME_H
#define	BLACKJACKGAME_H

#include "Deck.h"
#include "BlackJackCard.h"
#include "CardGame.h"
#include "Player.h"
#include <string>
#include <map>
#include <vector>

using namespace std;


class BlackJackCard : public CardGame<BlackJackCard>
{
public:
  BlackJackCard ();
  void play();
  void showStat();


private:
  Player<BlackJackCard> user;
  Player<BlackJackCard> bank;
  map<int, string> roundInfo;
  
  int calculateUserTotalValue();
  int calculateBankTotalValue();
  void stick();
  void twist();






};

#endif
