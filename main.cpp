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

    int numCards = 5;
    Player p1("Joe");
    Player p2("Jane");
    deck.shuffle();
    dealHand(deck, p1, numCards);
    dealHand(deck, p2, numCards);
    cout << p1.getName() <<" has : " << p1.showHand() << endl;
    cout << p2.getName() <<" has : " << p2.showHand() << endl;

    Card chosenCard= p1.chooseCardFromHand();
    cout << p1.getName() <<" asks- Do you have a " << chosenCard <<endl;

    if(p2.cardInHand(chosenCard)){
        cout << p2.getName() <<"says - Yes. I have a " << chosenCard << "."<< endl;
        p2.removeCardFromHand(chosenCard);
        p1.addCard(chosenCard);
    }
    else{
        cout << p2.getName() <<"says- Go Fish"<< endl;
    }
    return EXIT_SUCCESS;
}



void dealHand(Deck &d, Player &p, int numCards) {

    for (int i=0; i < numCards; i++)
        p.addCard(d.dealCard());
}