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
#include <algorithm>

//Shuffles the cards in the deck
template <class C>
void Deck<C>::shuffle() {
	std::random_shuffle(card.begin(), card.end());
}

//Returns the next card or reward by pointer
//Return nullptr if no more cards/rewards are available
template <class C>
C* Deck<C>::getNext() {
	return current->next;
}

//Returns true if the deck is empty
template <class C>
bool Deck<C>::isEmpty() const {
	if(this.getNext() == nullptr) {
		return true;
	}
	return false;
}


