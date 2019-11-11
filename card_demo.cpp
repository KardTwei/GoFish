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
    int numCards = 7;

    Player p1("Joe");
    Player p2("Jane");

    Deck d;  //create a deck of cards
    d.shuffle();

    dealHand(d, p1, numCards);
    //cout<<d.size()<<endl;
    dealHand(d, p2, numCards);
    //cout<<d.size()<<endl;

    cout << p1.getName() <<" has : " << p1.showHand() << endl;
    cout << p2.getName() <<" has : " << p2.showHand() << endl;

    Card c1;
    Card c2;

    for (int i = 0; i < 3; i++) {           //3 because starting with 7 cards allows max of 3 pairs
        if (p1.checkHandForBook(c1, c2)) {
            p1.bookCards(c1, c2);
            p1.removeCardFromHand(c1);
            p1.removeCardFromHand(c2);
        }
        if (p2.checkHandForBook(c1, c2)) {
            p2.bookCards(c1, c2);
            p2.removeCardFromHand(c1);
            p2.removeCardFromHand(c2);
        }
    }

    cout << p1.getName() <<" has in hand: " << p1.showHand() << endl;
    cout << p1.getName() <<" has booked: " << p1.showBooks() << endl;
    cout << p2.getName() <<" has in hand: " << p2.showHand() << endl;
    cout << p2.getName() <<" has booked : " << p2.showBooks() << endl;

    bool p1Turn = true;
    bool p2Turn = false;
    Card p1Card;
    Card p2Card;

    while ((p1.getBookSize() + p2.getBookSize()) < (52)){

        while(p1Turn && ((p1.getBookSize() + p2.getBookSize()) < (52))) {
            p1Card = p1.chooseCardFromHand();
            cout << p1.getName() << " asks - Do you have a " << p1Card.rankString(p1Card.getRank()) << "?" << endl;

            if (p2.rankInHand(p1Card)) {
                Card r1(p1Card.getRank(), Card::spades);
                Card r2(p1Card.getRank(), Card::clubs);
                Card r3(p1Card.getRank(), Card::hearts);
                Card r4(p1Card.getRank(), Card::diamonds);

                if (p2.cardInHand(r1)) {
                    p2Card = r1;
                } else if (p2.cardInHand(r2)) {
                    p2Card = r2;
                } else if (p2.cardInHand(r3)) {
                    p2Card = r3;
                } else if (p2.cardInHand(r4)) {
                    p2Card = r4;
                }

                cout << p2.getName() << " says - Yes. I have a " << p2Card.rankString(p2Card.getRank()) << "." << endl;
                p1.bookCards(p1Card, p2Card);
                p1.removeCardFromHand(p1Card);
                p2.removeCardFromHand(p2Card);
                cout << p1.getName() << " books the " << p2Card.rankString(p2Card.getRank()) << "." << endl;

                if (p1.getHandSize() == 0 && d.size() > 0){
                    p1.addCard(d.dealCard());
                }
                if (p2.getHandSize() == 0 && d.size() > 0){
                    p2.addCard(d.dealCard());
                }
            }
            else{
                cout << p2.getName() << " says - Go Fish " << endl;
                if (d.size() > 0) {
                    Card newCard = d.dealCard();
                    p1.addCard(newCard);
                    cout << p1.getName() << " draws " << newCard << endl;
                    if (p1.checkHandForBook(c1, c2)) {
                        p1.bookCards(c1, c2);
                        p1.removeCardFromHand(c1);
                        p1.removeCardFromHand(c2);
                    }
                }
                if (p1.getHandSize() == 0 && d.size() > 0){
                    p1.addCard(d.dealCard());
                }

                p1Turn = false;
                p2Turn = true;
            }

            cout << p1.getName() <<" has in hand: " << p1.showHand() << endl;
            cout << p1.getName() <<" has booked: " << p1.showBooks() << endl;
            cout << p2.getName() <<" has in hand: " << p2.showHand() << endl;
            cout << p2.getName() <<" has booked : " << p2.showBooks() << endl;
            cout << "Deck size: " << d.size() << endl;

        }


        while(p2Turn && ((p1.getBookSize() + p2.getBookSize()) < (52))) {
            p2Card = p2.chooseCardFromHand();
            cout << p2.getName() << " asks - Do you have a " << p2Card.rankString(p2Card.getRank()) << "?" << endl;

            if (p1.rankInHand(p2Card)) {
                Card r1(p2Card.getRank(), Card::spades);
                Card r2(p2Card.getRank(), Card::clubs);
                Card r3(p2Card.getRank(), Card::hearts);
                Card r4(p2Card.getRank(), Card::diamonds);

                if (p1.cardInHand(r1)) {
                    p1Card = r1;
                } else if (p1.cardInHand(r2)) {
                    p1Card = r2;
                } else if (p1.cardInHand(r3)) {
                    p1Card = r3;
                } else if (p1.cardInHand(r4)) {
                    p1Card = r4;
                }

                cout << p1.getName() << " says - Yes. I have a " << p1Card.rankString(p1Card.getRank()) << "." << endl;
                p2.bookCards(p1Card, p2Card);
                p1.removeCardFromHand(p1Card);
                p2.removeCardFromHand(p2Card);
                cout << p2.getName() << " books the " << p1Card.rankString(p1Card.getRank()) << "." << endl;

                if (p2.getHandSize() == 0 && d.size() > 0){
                    p2.addCard(d.dealCard());
                }
                if (p1.getHandSize() == 0 && d.size() > 0){
                    p1.addCard(d.dealCard());
                }
            }
            else{
                cout << p1.getName() << " says - Go Fish " << endl;
                if (d.size() > 0) {
                    Card newCard = d.dealCard();
                    p2.addCard(newCard);
                    cout << p2.getName() << " draws " << newCard << endl;
                    if (p2.checkHandForBook(c1, c2)) {
                        p2.bookCards(c1, c2);
                        p2.removeCardFromHand(c1);
                        p2.removeCardFromHand(c2);
                    }
                }
                if (p2.getHandSize() == 0 && d.size() > 0){
                    p2.addCard(d.dealCard());
                }

                p1Turn = true;
                p2Turn = false;
            }
            cout << p1.getName() <<" has in hand: " << p1.showHand() << endl;
            cout << p1.getName() <<" has booked: " << p1.showBooks() << endl;
            cout << p2.getName() <<" has in hand: " << p2.showHand() << endl;
            cout << p2.getName() <<" has booked : " << p2.showBooks() << endl;
            cout << "Deck size: " << d.size() << endl;
        }

        cout << "ended" << endl;
    }


    cout << "success!!" << endl;
    /*
    //Test of toString
    Card c1(3, Card::hearts);
    cout<<c1;
    //
    Deck d;
    d.shuffle();
    cout<<endl;

    for (int i = 0; i < 52; i ++){
       cout<<d.dealCard()<<endl;
       cout<<d.size()<<endl;
    }
     */

    return EXIT_SUCCESS;

}



void dealHand(Deck &d, Player &p, int numCards)
{
    for (int i=0; i < numCards; i++)
        p.addCard(d.dealCard());
}



