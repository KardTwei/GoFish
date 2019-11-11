//File Name: card.h
//
//Written by Owen Astrachan and Roger Priebe
// This class represents a playing card, i.e., "ace of spades"
// a Card is constructed from a rank (int in range 1..13)
// and a suit (Card::spades, Card::hearts, Card::diamonds,
// Card::clubs)
//
// Cards should be created by a Deck (see deck.h), a Deck returns
// good cards
// The function toString() converts a card to a string, e.g., to print
//
// Accessor functions include
//
// int GetRank()      -- returns 1, 2, ..., 13 for ace, two, ..., king
//
// bool SameSuitAs(c) -- returns true if same suit as Card c
//
// string suitString() -- returns "s", "h", "d" or "c"
//
// Note that the Ace is represented by 1 and the King by 13

#ifndef _CARD_H
#define _CARD_H

#include <iostream>
#include <string>
using namespace std;

class Card
{
public:


    enum Suit {spades, hearts, diamonds, clubs};

    Card();          // default, ace of spades

    Card(int rank, Suit s);

    /*
     * Pre: rankString function has been properly written
     * Post: Will concatenate myRank and suitString into a string (after rankString and suitString are applied to them)
    */
    string toString()              const;  // return string version e.g. Ac 4h Js

    /*
     * Pre: myRank of card has been assigned a proper value
     * Post: returns rank of card as int
    */
    int  getRank()                 const;  // return rank, 1..13

    /*
     * Pre: mySuit of card has been assigned proper value
     * Post: Returns suit of card as a string.  Spades = s, hearts = h, clubs = c, diamonds = d
    */
    string suitString(Suit s)      const;  // return "s", "h",...

    /*
     * Pre: Passed a valid int 1-13
     * Post: returns rank of card as string (A=1, J=11, Q=12, K=12, other numbers 2-10 are displayed as themselves)
    */
    string rankString(int r)       const;  // return "A", "2", ..."Q"


    bool operator == (const Card& rhs) const;
    bool operator != (const Card& rhs) const;



private:

    int myRank;
    Suit mySuit;


};

ostream& operator << (ostream& out, const Card& c);



#endif