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
	public:
		Game(); //Game constructor
		int getRound();
		void addPlayer(const Player&);
		Player& getNextPlayer(Side);
		const Card* getPreviousCard();
		const Card* getCurrentCard();
		void setCurrentCard(const Card*);
		friend ostream &operator << (ostream &out, const Game &g);
};

#endif
