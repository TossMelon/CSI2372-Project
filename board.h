/* 
	CSI 2372 Project
	Memory Card Game - Memoarrr!
	
	Group 36
	Member 1: Huong Pham
	Student Number: 7831858
	
	Member 2: Matthew Choi
	Student Number: 8250803
*/

#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <string>
#include <array>
#include "card.h"
#include "carddeck.h"

enum Letter{
	A, B, C, D, E
};
enum Number{
	One, Two, Three, Four, Five
};

using std::ostream;
using std::string;

class Board
{
	string** strArray;
	CardDeck* cDeck;
	
	public:
		Board(); //Board constructor
		bool isFaceUp(const Letter&, const Number&);
		bool turnFaceUp(const Letter&, const Number&);
		bool turnFaceDown(const Letter&, const Number&);
		Card* getCard(const Letter&, const Number&);
		void setCard(const Letter&, const Number&, Card*);
		void reset();
		friend ostream &operator<<(ostream &out, const Board &b);
};

#endif
