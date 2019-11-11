//
// Created by Austin on 11/8/2019.
//

// FILE:  player.h
// written by Roger Priebe
// 1/22/08 (revised 9/2/08)
// This class represents a player in a card game that takes "tricks"
// The "Books" represent a container for holding tricks

#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>

#include "card.h"
#include "deck.h"
#include "player.h"

Player::Player(){
    srand(time(0));
}

Player::Player(string name) {
    myName = name;
    srand(time(0));
}

void Player::addCard(Card c){
    myHand.push_back(c);
}  //adds a card to the hand

void Player::bookCards(Card c1, Card c2){
    myBook.push_back(c1);
    myBook.push_back(c2);
}

//OPTIONAL
// comment out if you decide to not use it
//this function will check a players hand for a pair.
//If a pair is found, it returns true and populates the two variables with the cards tha make the pair.

bool Player::checkHandForBook(Card &c1, Card &c2){
    for (int i = 0; i < getHandSize(); i++){
        for (int j = i+1; j < getHandSize(); j++){
            if (myHand[i].getRank() == myHand[j].getRank()){
                c1 = myHand[i];
                c2 = myHand[j];
                return true;
            }
        }
    }
    return false;
}

//OPTIONAL
// comment out if you decide to not use it
//Does the player have a card with the same rank as c in her hand?
bool Player::rankInHand(Card c) const{
    for (int i = 0; i < getHandSize(); i++){
        if (c.getRank() == myHand[i].getRank()){
            return true;
        }
    }
    return false;
}

//uses some strategy to choose one card from the player's
//hand so they can say "Do you have a 4?"
Card Player::chooseCardFromHand() const{
    int cardIndex = rand() % getHandSize();
    return myHand[cardIndex];
}

//Does the player have the card c in her hand?
bool Player::cardInHand(Card c) const{
    for (int i = 0; i < getHandSize(); i++){
        if (c == myHand[i]){
            return true;
        }
    }
    return false;
}

//Remove the card c from the hand and return it to the caller
Card Player::removeCardFromHand(Card c){
    Card tempReturn;
    for (int i = 0; i < getHandSize(); i++){
        if (c == myHand[i]){
            tempReturn = myHand[i];
            myHand.erase(myHand.begin() + i);
            return tempReturn;
        }
    }
    return tempReturn;
}


string Player::showHand() const{
    string hand;
    for (int i = 0; i < getHandSize(); i++){
        hand = hand + myHand[i].toString() + "\n";
    }
    return hand;
}

string Player::showBooks() const{
    string book;
    for (int i = 0; i < getBookSize(); i=i+2){
        book = book + myBook[i].toString() + myBook[i+1].toString() + "\n";
    }
    return book;
}

int Player::getHandSize() const{
    return myHand.size();
}
int Player::getBookSize() const{
    return myBook.size();
}

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


