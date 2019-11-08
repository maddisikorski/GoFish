// FILE: card_demo.cpp
// This is a small demonstration program showing how the Card and Deck classes are used.
#include <iostream>    // Provides cout and cin
#include <cstdlib>     // Provides EXIT_SUCCESS
#include <fstream>
#include "card.h"
#include "player.h"
#include "deck.h"

using namespace std;


// PROTOTYPES for functions used by this demonstration program:
void dealHand(Deck &d, Player &p, int numCards);


int main( )
{
    ofstream oFile;
    oFile.open("test.out");
    if(oFile.is_open()) {
        oFile << "Output test!!!" << endl;

        Deck deck;

        cout<<"PLAYING";

        int numCards = 7;
        Player p1("Sarah");
        Player p2("Maddi");
        deck.shuffle();
        dealHand(deck, p1, numCards);
        dealHand(deck, p2, numCards);
        oFile << p1.getName() << " has : " << p1.showHand() << endl;
        oFile << p2.getName() << " has : " << p2.showHand() << endl;

        Card check1;
        Card check2;

        while (p1.checkHandForBook(check1, check2)) {
            p1.bookCards(check1, check2);
            p1.removeCardFromHand(check1);
            p1.removeCardFromHand(check2);
        }
        while (p2.checkHandForBook(check1, check2)) {
            p2.bookCards(check1, check2);
            p2.removeCardFromHand(check1);
            p2.removeCardFromHand(check2);
        }

        oFile << p1.getName() << " has : " << p1.showHand() << endl;
        oFile << p2.getName() << " has : " << p2.showHand() << endl;

        oFile << p1.getName() << " booked : " << p1.showBooks() << endl;
        oFile << p2.getName() << " booked : " << p2.showBooks() << endl;

        Card chosenCard;
        Card spade;
        Card heart;
        Card diamond;
        Card club;
        int rankChosenCard;
        int continueCheck = 1;
        string rankStringChosenCard;
        Card cardToBeRemoved;
        int goFish = 0;

        while (p1.getHandSize() > 0 || p2.getHandSize() > 0) {

            while (goFish != 1 && continueCheck == 1) {
                if (p1.getHandSize() == 0 && deck.size() != 0) {
                    p1.addCard(deck.dealCard());
                }
                chosenCard = p1.chooseCardFromHand();
                rankChosenCard = chosenCard.getRank();
                rankStringChosenCard = chosenCard.rankString(rankChosenCard);

                oFile << p1.getName() << " asks- Do you have a " << rankStringChosenCard << endl;

                if (p2.rankInHand(chosenCard)) {
                    oFile << p2.getName() << " says - Yes. I have a " << rankStringChosenCard << "." << endl;
                    spade = Card(rankChosenCard, Card::spades);
                    heart = Card(rankChosenCard, Card::hearts);
                    club = Card(rankChosenCard, Card::clubs);
                    diamond = Card(rankChosenCard, Card::diamonds);


                    if (p2.cardInHand(spade)) {
                        cardToBeRemoved = p2.removeCardFromHand(spade);
                    } else if (p2.cardInHand(heart)) {
                        cardToBeRemoved = p2.removeCardFromHand(heart);
                    } else if (p2.cardInHand(club)) {
                        cardToBeRemoved = p2.removeCardFromHand(club);
                    } else if (p2.cardInHand(diamond)) {
                        cardToBeRemoved = p2.removeCardFromHand(diamond);
                    }

                    p1.addCard(cardToBeRemoved);


                } else {
                    oFile << p2.getName() << " says- Go Fish" << endl;
                    if (deck.size() != 0) {
                        p1.addCard(deck.dealCard());
                        oFile << p1.getName() << " added : " << p1.showHand() << endl;
                    }
                    goFish = 1;
                }

                while (p1.checkHandForBook(check1, check2)) {
                    p1.bookCards(check1, check2);
                    p1.removeCardFromHand(check1);
                    p1.removeCardFromHand(check2);
                }

                if (p1.getHandSize() == 0 && deck.size() != 0) {
                    p1.addCard(deck.dealCard());
                    oFile << "deck size:" << deck.size() << endl;
                    goFish = 1;
                } else if (p1.getHandSize() == 0 && p2.getHandSize() == 0 && deck.size() == 0) {
                    continueCheck = 0;
                    goFish = 1;
                }
                oFile << p1.getName() << " has : " << p1.showHand() << endl;
                oFile << p2.getName() << " has : " << p2.showHand() << endl;

                oFile << p1.getName() << " booked : " << p1.showBooks() << endl;
                oFile << p2.getName() << " booked : " << p2.showBooks() << endl;
            }


            while (goFish != 0 && continueCheck == 1) {
                if (p2.getHandSize() == 0 && deck.size() != 0) {
                    p2.addCard(deck.dealCard());
                }
                chosenCard = p2.chooseCardFromHand();
                rankChosenCard = chosenCard.getRank();
                rankStringChosenCard = chosenCard.rankString(rankChosenCard);

                oFile << p2.getName() << " asks- Do you have a " << rankStringChosenCard << endl;

                if (p1.rankInHand(chosenCard)) {
                    oFile << p1.getName() << " says - Yes. I have a " << rankStringChosenCard << "." << endl;
                    spade = Card(rankChosenCard, Card::spades);
                    heart = Card(rankChosenCard, Card::hearts);
                    club = Card(rankChosenCard, Card::clubs);
                    diamond = Card(rankChosenCard, Card::diamonds);

                    if (p1.cardInHand(spade)) {
                        cardToBeRemoved = p1.removeCardFromHand(spade);
                    } else if (p1.cardInHand(heart)) {
                        cardToBeRemoved = p1.removeCardFromHand(heart);
                    } else if (p1.cardInHand(club)) {
                        cardToBeRemoved = p1.removeCardFromHand(club);
                    } else if (p1.cardInHand(diamond)) {
                        cardToBeRemoved = p1.removeCardFromHand(diamond);
                    }
                    p2.addCard(cardToBeRemoved);
                } else {
                    oFile << p1.getName() << " says- Go Fish" << endl;
                    oFile << "deck size:" << deck.size() << endl;
                    if (deck.size() != 0) {
                        p2.addCard(deck.dealCard());
                    }
                    goFish = 0;
                    oFile << p2.showHand() << endl;
                }

                while (p2.checkHandForBook(check1, check2)) {
                    p2.bookCards(check1, check2);
                    p2.removeCardFromHand(check1);
                    p2.removeCardFromHand(check2);
                }

                if (p2.getHandSize() == 0 && deck.size() != 0) {
                    p2.addCard(deck.dealCard());
                    oFile << "deck size:" << deck.size() << endl;
                    goFish = 0;
                    oFile << p2.getName() << " added : " << p2.showHand() << endl;
                } else if (p1.getHandSize() == 0 && p2.getHandSize() == 0 && deck.size() == 0) {
                    continueCheck = 0;
                    goFish = 0;
                }
                oFile << p1.getName() << " has : " << p1.showHand() << endl;
                oFile << p2.getName() << " has : " << p2.showHand() << endl;

                oFile << p1.getName() << " booked : " << p1.showBooks() << endl;
                oFile << p2.getName() << " booked : " << p2.showBooks() << endl;
            }

        }

        cout <<"\n";

        if (p1.getBookSize() > p2.getBookSize()) {
            cout << p1.getName() << " Wins!" << endl;
        } else if (p1.getBookSize() < p2.getBookSize()) {
            cout << p2.getName() << " Wins!" << endl;
        } else {
            cout << "DRAW!" << endl;
        }
        oFile.close();
        return EXIT_SUCCESS;
    }
}



void dealHand(Deck &d, Player &p, int numCards)
{
    for (int i=0; i < numCards; i++)
        p.addCard(d.dealCard());
}