// FILE:  player.h
// written by Roger Priebe
// 1/22/08 (revised 9/2/08)
// This class represents a player in a card game that takes "tricks"
// The "Books" represent a container for holding tricks

#ifndef _PLAYER_H
#define _PLAYER_H

#include <iostream>
#include <string>
#include <vector>


#include "card.h"
using namespace std;


class Player
{
public:
    Player();

    Player(string name);

    /*
    * Pre: Player has been assigned valid name
    * Post: Returns character name as string
    */
    string getName() const {
        return myName;
    }

    /*
    * Pre: Parameter passed is a valid card
    * Post: Puts card into character's myHand vector
    */
    void addCard(Card c);  //adds a card to the hand

    /*
    * Pre: Passed 2 valid input cards
    * Post: Puts cards into character's myBook vector
    */
    void bookCards(Card c1, Card c2);

    /*
    * Pre: Player's myHand filled with proper cards
    * Post: Memory addresses c1 and c2 are assigned values of any pair of cards found in hand
    */
    //this function will check a players hand for a pair.
    //If a pair is found, it returns true and populates the two variables with the cards tha make the pair.
    bool checkHandForBook(Card &c1, Card &c2);

    /*
    * Pre: Player's myHand has valid cards in it, valid Card c is passed
    * Post: Returns true if myHand has card of same rank in hand, false if not
    */
    // comment out if you decide to not use it
    //Does the player have a card with the same rank as c in her hand?
    bool rankInHand(Card c) const;

    /*
    * Pre: myHand filled with proper Cards
    * Post: Random card is selected from player's myHand and is returned
    */
    //uses some strategy to choose one card from the player's
    //hand so they can say "Do you have a 4?"
    Card chooseCardFromHand() const;

    /*
    * Pre: myHand filled with proper cards
    * Post: Returns true if c matches (same suit and rank) any cards in myHand
    */
    //Does the player have the card c in her hand?
    bool cardInHand(Card c) const;

    /*
    * Pre: Valid card c passed, myHand has valid cards
    * Post: Erases card c from myHand if it is found, returns card
    */
    //Remove the card c from the hand and return it to the caller
    Card removeCardFromHand(Card c);

    /*
    * Pre: myHand is filled with proper cards
    * Post: Returns a string of all cards from myHand
    */
    string showHand() const;

    /*
    * Pre: myBook is filled with proper cards
    * Post: Returns a string of all cards from myBook
    */
    string showBooks() const;

    /*
    * Pre: myHand is filled with proper cards
    * Post: Returns number of cards in myHand
    */
    int getHandSize() const;

    /*
    * Pre: myBook is filled with proper cards
    * Post: Returns number of cards in myBook
    */
    int getBookSize() const;

    //OPTIONAL
    // comment out if you decide to not use it
    //this function will check a players hand for a pair.
    //If a pair is found, it returns true and populates the two variables with the cards tha make the pair.
    //bool checkHandForPair(Card &c1, Card &c2);

    //OPTIONAL
    // comment out if you decide to not use it
    //Does the player have a card with the same rank as c in her hand?
    //e.g. will return true if the player has a 7d and the parameter is 7c

    //bool sameRankInHand(Card c) const;


private:

    vector <Card> myHand;
    vector <Card> myBook;

    string myName;

};


#endif