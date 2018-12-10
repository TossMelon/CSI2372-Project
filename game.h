/*
	CSI 2372 Project
	Memory Card Game - Memoarrr!

	Group 36
	Member 1: Huong Pham
	Student Number: 7831858

	Member 2: Matthew Choi
	Student Number: 8250803
*/

#ifndef GAME_H
#define GAME_H



#include <iostream>

#include "board.h"
#include "card.h"
#include "player.h"
#include "carddeck.h"

using std::ostream;


class Game
{
	Board b;
	int round, numPlayers;
	Player *playerArray;
	Card *cPrev, *cCurrent;
	bool expertDisplay;
	public:
		Game(); //Game constructor
		int getRound() const;
		void nextRound(); //increments the number of rounds and resets the Game state for the next round
		void addPlayer(const Player&);
		Player& getPlayer(Side) const;
		Card* getPreviousCard() const;
		Card* getCurrentCard() const;
		void setCurrentCard(Card*);
		Card* getCard(const Letter&, const Number&);
		void setCard(const Letter&, const Number&, Card*);
		friend ostream &operator << (ostream &out, const Game &g);
};

#endif
