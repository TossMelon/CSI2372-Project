/* 
	
	
	CSI 2372 Project
	Memory Card Game - Memoarrr!
	
	Group 36
	Member 1: Huong Pham
	Student Number: 7831858
	
	Member 2: Matthew Choi
	Student Number: 8250803
*/

#ifndef CARDDECK_H
#define CARDDECK_H

#include "deck.h"
#include "card.h"

class CardDeck: public Deck<Card> {
	public:
		static CardDeck& make_CardDeck();
};

#endif
