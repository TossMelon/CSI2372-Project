/*
	rules.h

	CSI 2372 Project
	Memory Card Game - Memoarrr!

	Group 36
	Member 1: Huong Pham
	Student Number: 7831858

	Member 2: Matthew Choi
	Student Number: 8250803
*/

#ifndef RULES_H
#define RULES_H

#include "game.h"
#include "player.h"

//Check if a selection of a player is valid
class Rules
{
	protected:
		int nPlayers, playerCounter;

	public:
		Rules(int numPlayers); //Rules constructor
		bool isValid(const Game& g);
		bool gameOver(const Game& g);
		bool roundOver(const Game& g);
		const Player& getNextPlayer(const Game& g);
};

#endif // RULES_H
