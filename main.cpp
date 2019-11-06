// FILE: card_demo.cpp
// This is a small demonstration program showing how the Card and Deck classes are used.
#include <iostream>    // Provides cout and cin
#include <cstdlib>     // Provides EXIT_SUCCESS
#include "card.h"
#include "player.h"
#include "deck.h"

using namespace std;


// PROTOTYPES for functions used by this demonstration program:
void dealHand(Deck &d, Player &p, int numCards);


int main( )
{
    Card c;
    cout << c.getRank()  << endl;

    Card d(1, Card::spades);
    Card e(11, Card::diamonds);
    Card f(12, Card::hearts);
    Card g(13, Card::clubs);
    Card h(13, Card::clubs);

    cout << d.getRank()  << endl;
    cout << e.getRank()  << endl;
    cout << f.getRank()  << endl;
    cout << g.getRank()  << endl;

    cout << c.toString() << endl;
    cout << d.toString() << endl;
    cout << e.toString() << endl;
    cout << f.toString() << endl;
    cout << g.toString() << endl;

    cout << (g==h) << endl;
    cout << (g!=h) << endl;


    Deck deck;

    int numCards = 7;
    Player p1("Sarah");
    Player p2("Maddi");
    deck.shuffle();
    dealHand(deck, p1, numCards);
    dealHand(deck, p2, numCards);
    cout << p1.getName() <<" has : " << p1.showHand() << endl;
    cout << p2.getName() <<" has : " << p2.showHand() << endl;

    Card check1;
    Card check2;

    while(p1.checkHandForBook(check1, check2)){
        p1.bookCards(check1, check2);
        p1.removeCardFromHand(check1);
        p1.removeCardFromHand(check2);
    }
    while(p2.checkHandForBook(check1, check2)){
        p2.bookCards(check1, check2);
        p2.removeCardFromHand(check1);
        p2.removeCardFromHand(check2);
    }

    cout << p1.getName() <<" has : " << p1.showHand() << endl;
    cout << p2.getName() <<" has : " << p2.showHand() << endl;

    cout << p1.getName() <<" booked : " << p1.showBooks() << endl;
    cout << p2.getName() <<" booked : " << p2.showBooks() << endl;

    Card chosenCard;
    int rankChosenCard;
    string rankStringChosenCard;
    Card cardToBeRemoved;
    int goFish=0;
    while(deck.size()!=0) {

        while(goFish!=1) {
            chosenCard = p1.chooseCardFromHand();
            rankChosenCard = chosenCard.getRank();
            rankStringChosenCard = chosenCard.rankString(rankChosenCard);

            cout << p1.getName() << " asks- Do you have a " << rankStringChosenCard << endl;

            if (p2.rankInHand(chosenCard)) {
                cout << p2.getName() << " says - Yes. I have a " << rankStringChosenCard << "." << endl;
                Card spade(chosenCard.getRank(), Card::spades);
                Card heart(chosenCard.getRank(), Card::hearts);
                Card club(chosenCard.getRank(), Card::clubs);
                Card diamond(chosenCard.getRank(), Card::diamonds);

                if(p2.cardInHand(spade)){
                    cardToBeRemoved=p2.removeCardFromHand(spade);
                }
                else if(p2.cardInHand(heart)){
                    cardToBeRemoved=p1.removeCardFromHand(heart);
                }
                else if(p2.cardInHand(club)){
                    cardToBeRemoved=p1.removeCardFromHand(club);
                }
                else if(p2.cardInHand(diamond)){
                    cardToBeRemoved=p1.removeCardFromHand(diamond);
                }

                p1.addCard(cardToBeRemoved);
            }
            else {
                cout << p2.getName() << " says- Go Fish" << endl;
                p1.addCard(deck.dealCard());
                goFish=1;
                cout<<p1.showHand()<<endl;
            }
            while(p1.checkHandForBook(check1, check2)){
                p1.bookCards(check1, check2);
                p1.removeCardFromHand(check1);
                p1.removeCardFromHand(check2);
            }
            if(p1.getHandSize() == 0){
                p1.addCard(deck.dealCard());
                goFish=1;
            }
            cout << p1.getName() <<" has : " << p1.showHand() << endl;
            cout << p2.getName() <<" has : " << p2.showHand() << endl;

            cout << p1.getName() <<" booked : " << p1.showBooks() << endl;
            cout << p2.getName() <<" booked : " << p2.showBooks() << endl;
        }
        while(goFish!=0) {

            chosenCard = p2.chooseCardFromHand();
            rankChosenCard = chosenCard.getRank();
            rankStringChosenCard = chosenCard.rankString(rankChosenCard);

            cout << p2.getName() << " asks- Do you have a " << rankStringChosenCard << endl;

            if (p1.rankInHand(chosenCard)) {
                cout << p1.getName() << " says - Yes. I have a " << rankStringChosenCard << "." << endl;

                Card spade(chosenCard.getRank(), Card::spades);
                Card heart(chosenCard.getRank(), Card::hearts);
                Card club(chosenCard.getRank(), Card::clubs);
                Card diamond(chosenCard.getRank(), Card::diamonds);

                if(p1.cardInHand(spade)){
                    cardToBeRemoved=p1.removeCardFromHand(spade);
                }
                else if(p1.cardInHand(heart)){
                    cardToBeRemoved=p1.removeCardFromHand(heart);
                }
               else if(p1.cardInHand(club)){
                    cardToBeRemoved=p1.removeCardFromHand(club);
                }
               else if(p1.cardInHand(diamond)){
                    cardToBeRemoved=p1.removeCardFromHand(diamond);
                }

                p2.addCard(cardToBeRemoved);
            }
            else {
                cout << p1.getName() << " says- Go Fish" << endl;
                p2.addCard(deck.dealCard());
                goFish=0;
                cout<<p2.showHand()<<endl;
            }
            while(p2.checkHandForBook(check1, check2)){
                p2.bookCards(check1, check2);
                p2.removeCardFromHand(check1);
                p2.removeCardFromHand(check2);
            }
            if(p2.getHandSize() == 0){
                p2.addCard(deck.dealCard());
                goFish=0;
            }
            cout << p1.getName() <<" has : " << p1.showHand() << endl;
            cout << p2.getName() <<" has : " << p2.showHand() << endl;

            cout << p1.getName() <<" booked : " << p1.showBooks() << endl;
            cout << p2.getName() <<" booked : " << p2.showBooks() << endl;
        }

    }


    if(p1.getBookSize()>p2.getBookSize()){
        cout << p1.getName() << "Wins!"<<endl;
    }
    else if(p1.getBookSize()<p2.getBookSize()){
        cout << p2.getName() << "Wins!"<<endl;
    }
    else{
        cout << "DRAW!" <<endl;
    }
    return EXIT_SUCCESS;
}



void dealHand(Deck &d, Player &p, int numCards) {

    for (int i=0; i < numCards; i++)
        p.addCard(d.dealCard());
}