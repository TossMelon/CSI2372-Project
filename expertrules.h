/*
	expertrules.h

	CSI 2372 Project
	Memory Card Game - Memoarrr!

	Group 36
	Member 1: Huong Pham
	Student Number: 7831858

	Member 2: Matthew Choi
	Student Number: 8250803
*/

#ifndef EXPERT_RULES_H
#define EXPERT_RULES_H

//#include "game.h"
//#include "player.h"
#include "rules.h"
#include "board.h"

class ExpertRules: public Rules {

	private:
		FaceAnimal blockedAnimal;
		FaceBackground blockedColour;
		
		Letter getLetter(char letter);
		Number getNumber(char number);
		void animalAttribute(const Game& g, const Board b);
		void block(const Letter&, const Number&, const Board b);
		bool isBlocked(const Game& g);
		
		void crab();
		void penguin(const Board b);
		void octopus();
		void turtle(const Game& g);
		void walrus(const Board b);
	public:
		ExpertRules(int numPlayers); //ExpertRules constructor
		bool isValid(const Game& g, const Board b);
};

#endif // EXPERTRULES_H
