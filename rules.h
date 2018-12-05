/*
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

//Aggregate
class Game;

//Check if a selection of a player is valid
class Rules
{
	public:
		Rules(); //Rules constructor
		const bool isValid(const Game& g);
		const bool gameOver(const Game& g);
		const bool roundOver(const Game& g);
};

#endif
