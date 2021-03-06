/* 
	deck.cpp
	
	CSI 2372 Project
	Memory Card Game - Memoarrr!
	
	Group 36
	Member 1: Huong Pham
	Student Number: 7831858
	
	Member 2: Matthew Choi
	Student Number: 8250803
*/

#include "deck.h"
#include <algorithm> //random_shuffle
#include <vector>
#include <stdlib.h> //srand
#include <time.h> //time

using std::random_shuffle;
using std::srand;

//Shuffles the cards in the deck
template <class C>
void Deck<C>::shuffle() {
	srand(time(0)); //set seed 
	random_shuffle(myvector.begin(), myvector.end()); //shuffle deck
	it = myvector.begin(); //set pointer to first card in deck
	counter = 0;
}

//Return the next card by pointer
//Return nullptr if no more cards are available
template <class C>
C* Deck<C>::getNext() {
	if(counter== 0) {
		counter = 1;
		return &(*it);
	} else if (it == myvector.end()) {
		return nullptr;
	} else {
		return &(*it++);	
	}
}

//Returns true if the deck is empty
template <class C>
bool Deck<C>::isEmpty() const {
	return myvector.empty();
}
