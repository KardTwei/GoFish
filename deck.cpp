//
// Created by Austin on 11/8/2019.
//
#include "deck.h"

Deck::Deck(){
    int deckIndex = 0;
    //Assume a new deck is ordered with Ace spades, Ace hearts, Ace diamonds, Ace clubs, 2 spades...
    //Only printing ace of spades???
    for (int i = 1; i < 14; i++){
        myCards[deckIndex] = Card(i, Card::spades);
        cout<<myCards[deckIndex]<<endl;
        deckIndex++;
        myCards[deckIndex] = Card(i, Card::hearts);
        cout<<myCards[deckIndex]<<endl;
        deckIndex++;
        myCards[deckIndex] = Card(i, Card::diamonds);
        cout<<myCards[deckIndex]<<endl;
        deckIndex++;
        myCards[deckIndex] = Card(i, Card::clubs);
        cout<<myCards[deckIndex]<<endl;
        deckIndex++;
    }
}      // pristine, sorted deck

/*
void shuffle();   // shuffle the deck, all 52 cards present
Card dealCard();   // get a card, after 52 are dealt, fail

int  size() const; // # cards left in the deck
 */