#ifndef DECK_H
#define	DECK_H
#include "PlayingCard.h"
#include <algorithm>
#include <random>
#include <chrono>
#include <vector>
#include <string>

using namespace std;

template<class cardType>
class Deck
{
public:
  Deck()
  {
    vector<string> suits= {"HEARTS", "CLUBS", "DIAMONDS", "SPADES"};
    vector<string> faces = {"TWO","THREE","FOUR","FIVE","SIX","SEVEN","EIGHT","NINE","TEN","JACK","QUEEN","KING","ACE"};


    for (string suit : suits)
    {

        for (string face : faces)
        {
            cardType newCard(face, suit);

            cards.push_back(newCard);
        }
    }

  }

  void shuffleDeck()
  {
    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    default_random_engine range_(seed);
    shuffle(begin(cards), end(cards), range_);
  }

  cardType deal()
  {
    cardType lastCard = cards.back();
    cards.pop_back();

    return lastCard;
  }

  void resetDeck()
  {
    cards.clear();

    vector<string> suits= {"HEARTS", "CLUBS", "DIAMONDS", "SPADES"};
    vector<string> faces = {"TWO","THREE","FOUR","FIVE","SIX","SEVEN","EIGHT","NINE","TEN","JACK","QUEEN","KING","ACE"};


    for (string suit : suits)
    {

        for (string face : faces)
        {
            cardType newCard(face, suit);

            cards.push_back(newCard);
        }
    }
  }

  int remainingCards()
  {
    return cards.size();
  }

private:
  vector<cardType> cards;

};

#endif
