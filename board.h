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

enum class Letter{
	A, B, C, D, E
};
enum class Number{
	One, Two, Three, Four, Five
};

const string faceAnimal[5]{"C", "P", "O", "T", "W"};
const string faceBackground[5]{"R", "G", "P", "B", "Y"};

using std::ostream;
using std::string;

class Board
{
	string** strArray;
	Card* cPrev;
	Card* cArray[25];
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
