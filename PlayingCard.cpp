#include "PlayingCard.h"
#include <iostream>
#include <string>

using namespace std;

PlayingCard::PlayingCard(){}

PlayingCard::PlayingCard(string face, string suit)
{
  setCardFace(face);
  setCardSuit(suit);
}

string PlayingCard::getCardFace()
{
  return face;
}

string PlayingCard::getCardSuit()
{
  return suit;
}

void PlayingCard::setCardFace(string face)
{
  this->face=face;
}

void PlayingCard::setCardSuit(string suit)
{
  this->suit=suit;
}

void PlayingCard::showCard()
{
  cout<<getCardFace()<<" of "<<getCardSuit()<<endl;
}
