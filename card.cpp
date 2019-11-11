//
// Created by Austin on 11/8/2019.
//

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


#include <iostream>
#include <string>
#include <sstream>
#include "card.h"

using namespace std;

enum Suit {spades, hearts, diamonds, clubs};

Card::Card() {
    myRank = 1;
    mySuit = spades;
}// default, ace of spades

Card::Card(int rank, Suit s){
    myRank = rank;
    mySuit = s;
}

string Card::toString() const{               // return string version e.g. Ac 4h Js
    //return(suitString(mySuit));
    return(rankString(myRank) + suitString(mySuit));

}



int  Card::getRank()                 const{
    return(myRank);
} // return rank, 1..13
string Card::suitString(Suit s)      const{
    if (s == spades){
        return("s");
    }
    else if (s == hearts){
        return("h");
    }
    else if (s == diamonds){
        return("d");
    }
    else {
        return("c");
    }
}  // return "s", "h",...

string Card::rankString(int r)       const{
    if(r == 1) {
        return("A");
    }
    else if (r == 11){
        return("J");
    }
    else if (r == 12){
        return("Q");
    }
    else if (r == 13){
        return("K");
    }
    else{
        stringstream s;
        s<<r;
        return(s.str());
    }
}  // return "A", "2", ..."Q"


bool Card::operator == (const Card& rhs) const{
    if (myRank == rhs.myRank && mySuit == rhs.mySuit){
        return true;
    }
    else
        return false;
 }
bool Card::operator != (const Card& rhs) const{
    if (myRank != rhs.myRank && mySuit != rhs.mySuit){
        return true;
    }
    else
        return false;
}


ostream& operator << (ostream& out, const Card& c){
    out<<c.toString();
    return out;
}



