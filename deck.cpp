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
#include <iostream>
#include <algorithm>
#include <vector>

//Shuffles the cards in the deck
template <class C>
void Deck<C>::shuffle() {
	std::random_shuffle(myvector.begin(), myvector.end());
	it = myvector.begin();
}

//Return the next card by pointer
//Return nullptr if no more cards are available
template <class C>
C* Deck<C>::getNext() {
	if(it == myvector.end()) {
		return nullptr;
	}
	std::cout<<"SUCCESS!"<<std::endl;
	//++it;
	C* c = &(*it);
	return c;
}

//Returns true if the deck is empty
template <class C>
bool Deck<C>::isEmpty() const {
	return myvector.empty();
}

template <class C>
void Deck<C>::addCard(C card) {
	myvector.push_back(card);
}
