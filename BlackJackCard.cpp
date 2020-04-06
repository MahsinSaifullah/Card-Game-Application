#include "PlayingCard.h"
#include "BlackJackCard.h"
#include <iostream>
#include <string>

using namespace std;

BlackJackCard::BlackJackCard(){}

BlackJackCard::BlackJackCard(string face, string suit) : PlayingCard (face, suit)
{
  switch (face) {
    case "ACE": setCardValue(1);
    break;

    case "TWO": setCardValue(2);
    break;

    case "THREE": setCardValue(3);
    break;

    case "FOUR": setCardValue(4);
    break;

    case "FIVE": setCardValue(5);

    case "SIX": setCardValue(6);
    break;

    case "SEVEN": setCardValue(7);
    break;

    case "EIGHT": setCardValue(8);
    break;

    case "NINE": setCardValue(9);
    break;

    case "TEN": setCardValue(10);
    break;

    case "JACK": setCardValue(10);
    break;

    case "QUEEN": setCardValue(10);
    break;

    case "KING": setCardValue(10);
    break;

  }
}

int BlackJackCard::getCardValue()
{
  return cardValue;
}


void BlackJackCard::setCardValue(int cardValue)
{
  this->cardValue=cardValue;
}
