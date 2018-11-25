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

template <class C> class Deck {
	C *next;
	private:
		Deck();
	public:
		void shuffle();
		C* getNext();
		bool isEmpty() const;
};

#endif