#ifndef PLAYER_H
#define	PLAYER_H
#include <vector>
#include <string>

using namespace std;

template<class cardType>
class Player
{
public:
  vector<cardType> *getCardInHand()
  {
    return &cardInHand;
  }

  void showCardInHand()
  {
    for(cardType card : cardInHand)
    {
      card.showCard();
    }
  }

  void takeCard(cardType card)
  {
    cardInHand.push_back(card);
  }

  void clearHand()
  {
    cardInHand.clear();
  }

  int numOfCardsInHand()
  {
    return cardInHand.size();
  }


private:
  vector<cardType> cardInHand;


};

#endif
