#ifndef BLACKJACKCARDGAME_H
#define	BLACKJACKCARDGAME_H

#include "Deck.h"
#include "BlackJackCard.h"
#include "CardGame.h"
#include "Player.h"
#include <string>
#include <map>
#include <vector>

using namespace std;


class BlackJackCardGame : public CardGame<BlackJackCard>
{
public:
  BlackJackCardGame ();
  void play();
  void showStat();


private:
  Player<BlackJackCard> user;
  Player<BlackJackCard> bank;
  map<int, string> roundInfo;
  int roundNumber=0;

  int calculateUserTotalValue();
  int calculateBankTotalValue();
  int winCount();





};

#endif
