//
// Created by Austin on 11/8/2019.
//
#include "deck.h"
#include <time.h>

Deck::Deck(){
    int deckIndex = 0;      //deckIndex is used solely within Deck constructor
    myIndex = 0;        //myIndex is used when dealing cards out
    //Assume a new deck is ordered with Ace spades, Ace hearts, Ace diamonds, Ace clubs, 2 spades...
    //Only printing ace of spades???
    srand(time(0));
    for (int i = 1; i < 14; i++){
        myCards[deckIndex] = Card(i, Card::spades);
        deckIndex++;
        myCards[deckIndex] = Card(i, Card::hearts);
        deckIndex++;
        myCards[deckIndex] = Card(i, Card::diamonds);
        deckIndex++;
        myCards[deckIndex] = Card(i, Card::clubs);
        deckIndex++;
    }

    /*
    //Debugging
    for (int i = 0; i < 52; i++) {
        cout << myCards[i] << endl;
    }
     */
}      // pristine, sorted deck


void Deck::shuffle(){

    for (int i = 0; i < SIZE*2; i++){
        int index1 = rand() % SIZE;
        int index2 = rand() % SIZE;
        Card temp;

        temp = myCards[index1];
        myCards[index1] = myCards[index2];
        myCards[index2] = temp;
    }

    /*
    //Debugging
    for (int i = 0; i < 52; i++) {
        cout << myCards[i] << endl;
    }
     */
}   // shuffle the deck, all 52 cards present


Card Deck::dealCard(){
    Card returnCard;
    if (myIndex < SIZE){
        returnCard = myCards[myIndex];
        myIndex++;
        return(returnCard);
    }
    else{
        return(Card(0, Card::spades));      //What do we return here???
    }
}   // get a card, after 52 are dealt, fail

int  Deck::size() const{
    return (SIZE - myIndex);
} // # cards left in the deck
