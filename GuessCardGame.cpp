#include "Deck.h"
#include "PlayingCard.h"
#include "CardGame.h"
#include "GuessCardGame.h"
#include "helperFunctions.h"
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;



GuessCardGame::GuessCardGame()
{
  deck.shuffleDeck();
}

void GuessCardGame::play()
{
  string inputSuit;
  string inputFace;
  string option;


  clearConsole();
  do {

    deck.shuffleDeck();
    currentCard = deck.deal();
    roundNumber++;
    roundInfo[roundNumber].push_back(currentCard);

    do {
      cout<<"Guess the suit of the card (hearts, clubs, diamonds or spades): "<<endl;
      cout<<"or type 'quit' to exit the game"<<endl;
      cin>>inputSuit;
      toUpperCase(inputSuit);
      if(!verifySuitInput(inputSuit) && inputSuit != "QUIT")
      {
        cout<<"Invalid Choice..Please try again!!"<<endl;
        continue;
      }

      break;
    } while(true);

    if(inputSuit == "QUIT") return;

    do {
      cout<<"Guess the face of the card (ace, two, three, four, five, six, seven, eight, nine, ten, jack, queen or king): "<<endl;
      cout<<"or type 'quit' to exit the game"<<endl;
      cin>>inputFace;
      toUpperCase(inputFace);

      if(!verifyFaceInput(inputFace) && inputFace != "QUIT")
      {
        cout<<"Invalid Choice..Please try again!!"<<endl;
        continue;
      }

      break;

    } while(true);

    if(inputFace == "QUIT") return;

    currentGuess.setCardFace(inputFace);
    currentGuess.setCardSuit(inputSuit);
    roundInfo[roundNumber].push_back(currentGuess);

    do {
      if(isSuitMatch() && isFaceMatch())
      {
        cout<<"Congrats!!! ... You Guessed the card correctly"<<endl;
        break;
      }
      else if(isSuitMatch() && !isFaceMatch())
      {
        cout<<endl;
        cout<<"You Guessed the Suit correctly...but"<<endl;

        if(faces[currentCard.getCardFace()] > faces[currentGuess.getCardFace()]) cout<<"The Face you guessed was too small"<<endl;
        else cout<<"The Face you guessed was too big"<<endl;

        do {
          cout<<endl;
          cout<<"Guess the face of the card again (ace, two, three, four, five, six, seven, eight, nine, ten, jack, queen or king)"<<endl;
          cout<<"or type 'quit' to exit the game"<<endl;
          cin>>inputFace;
          toUpperCase(inputFace);

          if(!verifyFaceInput(inputFace) && inputFace != "QUIT")
          {
            cout<<"Invalid Choice..Please try again!!"<<endl;
            continue;
          }

          break;

        } while(true);

        if(inputFace == "QUIT") return;

        currentGuess.setCardFace(inputFace);
        roundInfo[roundNumber].push_back(currentGuess);
        continue;
      }
      else if(isFaceMatch() && !isSuitMatch())
      {
        cout<<endl;
        cout<<"You Guessed the Face correctly...but"<<endl;
        cout<<"The Suit you guessed was wrong"<<endl;

        do {
          cout<<endl;
          cout<<"Guess the suit of the card again (hearts, clubs, diamonds or spades): "<<endl;
          cout<<"or type 'quit' to exit the game"<<endl;
          cin>>inputSuit;
          toUpperCase(inputSuit);
          if(!verifySuitInput(inputSuit) && inputSuit != "QUIT")
          {
            cout<<"Invalid Choice..Please try again!!"<<endl;
            continue;
          }

          break;
        } while(true);

        if(inputSuit == "QUIT") return;
        currentGuess.setCardSuit(inputSuit);
        roundInfo[roundNumber].push_back(currentGuess);
        continue;
      }
      else if (!isSuitMatch() && !isFaceMatch())
      {
        cout<<endl;
        cout<<"The Suit you guessed was wrong..and"<<endl;

        if(faces[currentCard.getCardFace()] > faces[currentGuess.getCardFace()]) cout<<"The Face you guessed was too small"<<endl;
        else cout<<"The Face you guessed was too big"<<endl;

        do {
          cout<<endl;
          cout<<"Guess the suit of the card again (hearts, clubs, diamonds or spades): "<<endl;
          cout<<"or type 'quit' to exit the game"<<endl;
          cin>>inputSuit;
          toUpperCase(inputSuit);
          if(!verifySuitInput(inputSuit) && inputSuit != "QUIT")
          {
            cout<<"Invalid Choice..Please try again!!"<<endl;
            continue;
          }

          break;
        } while(true);

        if(inputSuit == "QUIT") return;

        do {
          cout<<endl;
          cout<<"Guess the face of the card again (ace, two, three, four, five, six, seven, eight, nine, ten, jack, queen or king)"<<endl;
          cout<<"or type 'quit' to exit the game"<<endl;
          cin>>inputFace;
          toUpperCase(inputFace);

          if(!verifyFaceInput(inputFace) && inputFace != "QUIT")
          {
            cout<<"Invalid Choice..Please try again!!"<<endl;
            continue;
          }

          break;

        } while(true);

        if(inputFace == "QUIT") return;

        currentGuess.setCardFace(inputFace);
        currentGuess.setCardSuit(inputSuit);
        roundInfo[roundNumber].push_back(currentGuess);
        continue;
      }
    } while(true);

    do {
      cout<<endl;
      cout<<"Press 1 to play another round"<<endl;
      cout<<"Press 0 to quit the game"<<endl;
      cin>>option;

      if(option == "1") break;
      else if(option == "0") return;
      else {
        cout<<"Invalid Choice..Please try again!!"<<endl;
        continue;
      }
    } while(true);

    clearConsole();

  } while(true);
}


void GuessCardGame::showStat()
{
  clearConsole();
 cout<<endl;
 cout<<"***** Guessing Card Game Stats ******"<<endl;
 cout<<endl;

 for(auto round : roundInfo)
 {
   cout<<"ROUND: "<<round.first<<endl;
   cout<<"Target card: "<<flush;
   round.second[0].showCard();
   cout<<endl;
   cout<<"Cards Guessed: "<<endl;
   cout<<endl;
   for(auto i=1; i<round.second.size(); i++)
   {
     round.second[i].showCard();
   }
   cout<<"Number of Guesses Used: "<<(round.second.size()-1)<<endl;
   cout<<endl;
 }
}

bool GuessCardGame::isSuitMatch()
{
  return currentCard.getCardSuit() == currentGuess.getCardSuit();
}

bool GuessCardGame::isFaceMatch()
{
  return currentCard.getCardFace() == currentGuess.getCardFace();
}

bool GuessCardGame::verifySuitInput(string inputSuit)
{
  return suits.find(inputSuit) != suits.end();
}

bool GuessCardGame::verifyFaceInput(string inputFace)
{
  return faces.find(inputFace) != faces.end();
}
