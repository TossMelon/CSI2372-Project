/* 
	carddeck.cpp
	
	CSI 2372 Project
	Memory Card Game - Memoarrr!
	
	Group 36
	Member 1: Huong Pham
	Student Number: 7831858
	
	Member 2: Matthew Choi
	Student Number: 8250803
*/

#include "carddeck.h"
#include "deck.h"

Deck<Card> cDeck; //Create variable to hold card deck
bool cExist = false; //false --> carddeck has not yet been made

//Makes card deck with appropriate cards
template <class Card>
static CardDeck& make_CardDeck() {
	if(cExist == false) {
		//Create and add all 5 Crab cards to card deck
		cDeck.myvector.push_back(new Card('C','r'));
		cDeck.myvector.push_back(new Card('C','g'));
		cDeck.myvector.push_back(new Card('C','p'));
		cDeck.myvector.push_back(new Card('C','b'));
		cDeck.myvector.push_back(new Card('C','y'));
		
		//Create and add all 5 Penguin cards to card deck
		cDeck.myvector.push_back(new Card('P','r'));
		cDeck.myvector.push_back(new Card('P','g'));
		cDeck.myvector.push_back(new Card('P','p'));
		cDeck.myvector.push_back(new Card('P','b'));
		cDeck.myvector.push_back(new Card('P','y'));
		
		//Create and add all 5 Octopus cards to card deck
		cDeck.myvector.push_back(new Card('O','r'));
		cDeck.myvector.push_back(new Card('O','g'));
		cDeck.myvector.push_back(new Card('O','p'));
		cDeck.myvector.push_back(new Card('O','b'));
		cDeck.myvector.push_back(new Card('O','y'));
		
		//Create and add all 5 Turtle cards to card deck
		cDeck.myvector.push_back(new Card('T','r'));
		cDeck.myvector.push_back(new Card('T','g'));
		cDeck.myvector.push_back(new Card('T','p'));
		cDeck.myvector.push_back(new Card('T','b'));
		cDeck.myvector.push_back(new Card('T','y'));
		
		//Create and add all 5 Walrus cards to card deck
		cDeck.myvector.push_back(new Card('W','r'));
		cDeck.myvector.push_back(new Card('W','g'));
		cDeck.myvector.push_back(new Card('W','p'));
		cDeck.myvector.push_back(new Card('W','b'));
		cDeck.myvector.push_back(new Card('W','y'));
		
		//Shuffle card deck
		cDeck.shuffle();
		
		//Card deck now exists, disallows anymore card decks from being formed this game
		cExist == true;
	}
	
	return cDeck;
}
