/* 
	deck.h
	
	CSI 2372 Project
	Memory Card Game - Memoarrr!
	
	Group 36
	Member 1: Huong Pham
	Student Number: 7831858
	
	Member 2: Matthew Choi
	Student Number: 8250803
*/

#ifndef DECK_H
#define DECK_H

#include <vector>

using std::vector;

template <class C>
class Deck {
	friend class CardDeck;
	friend class RewardDeck;
	
	vector<C> myvector;
	typename vector<C>::iterator it;

	public:
		void shuffle();
		C* getNext();
		bool isEmpty() const;
};

#endif
