#include "PlayingCard.h"
#include "BlackJackCard.h"
#include <iostream>
#include <string>

using namespace std;

BlackJackCard::BlackJackCard(){}

BlackJackCard::BlackJackCard(string face, string suit) : PlayingCard (face, suit)
{
    if(face == "ACE") setCardValue(1);
    else if(face == "TWO") setCardValue(2);
    else if(face == "THREE") setCardValue(3);
    else if(face == "FOUR") setCardValue(4);
    else if(face == "FIVE")setCardValue(5);
    else if(face == "SIX") setCardValue(6);
    else if(face == "SEVEN") setCardValue(7);
    else if(face == "EIGHT") setCardValue(8);
    else if(face == "NINE") setCardValue(9);
    else if( face == "TEN") setCardValue(10);
    else if( face == "JACK") setCardValue(10);
    else if( face == "QUEEN") setCardValue(10);
    else if( face == "KING") setCardValue(10);
}

int BlackJackCard::getCardValue()
{
  return cardValue;
}


void BlackJackCard::setCardValue(int cardValue)
{
  this->cardValue=cardValue;
}
