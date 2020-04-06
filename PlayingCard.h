#ifndef PLAYINGCARD_H
#define	PLAYINGCARD_H
#include <string>

using namespace std;

class PlayingCard
{
public:
  PlayingCard();
  PlayingCard(string, string);
  string getCardFace();
  string getCardSuit();
  void setCardFace(string);
  void setCardSuit(string);
  void showCard();

private:
  string face;
  string suit;

};

#endif
