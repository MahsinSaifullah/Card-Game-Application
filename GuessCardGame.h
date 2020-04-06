#ifndef GUESSCARDGAME_H
#define	GUESSCARDGAME_H

#include "Deck.h"
#include "PlayingCard.h"
#include "CardGame.h"
#include <string>
#include <map>
#include <vector>

using namespace std;


class GuessCardGame: public CardGame<PlayingCard>
{
public:
  GuessCardGame();
  void play();
  void showStat();


private:
  map<string, int> suits {{"HEARTS", 0}, {"CLUBS", 1}, {"DIAMONDS", 2}, {"SPADES", 3}};
  map<string, int> faces {{"ACE", 0},{"TWO",1},{"THREE", 2},{"FOUR",3},{"FIVE", 4},{"SIX",5},{"SEVEN",6},{"EIGHT",7},{"NINE",8},{"TEN",9},{"JACK",10},{"QUEEN",11},{"KING",12}};
  map<int, vector<PlayingCard>> roundInfo;
  PlayingCard currentCard;
  PlayingCard currentGuess;
  int roundNumber=0;

  bool verifySuitInput(string);
  bool verifyFaceInput(string);
  bool isSuitMatch();
  bool isFaceMatch();




};

#endif
