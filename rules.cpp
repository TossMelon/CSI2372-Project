/*
	rules.cpp

	CSI 2372 Project
	Memory Card Game - Memoarrr!

	Group 36
	Member 1: Huong Pham
	Student Number: 7831858

	Member 2: Matthew Choi
	Student Number: 8250803
*/

#include "rules.h"

Rules::Rules(int numPlayers) {
	nPlayers = numPlayers;
	playerCounter = 1;
}

//Returns true if previous and current cards match, false otherwise
bool Rules::isValid(const Game& g) {
	const Card* prev = g.getPreviousCard();
	const Card* curr = g.getCurrentCard();
	
	if( ((FaceAnimal)*prev) == ((FaceAnimal)*curr) ) {
		return true;
	} else if ( ((FaceBackground)*prev) == ((FaceBackground)*curr) ) {
		return true;
	} else {
		return false;
	}
}

//Returns true if the number of rounds has reached 7
bool Rules::gameOver(const Game& g) {
	if(g.getRound() == 7) {
		return true;
	}
	return false;
}

//Return true if there is only one active Player left
bool Rules::roundOver(const Game& g) {
	int activeCounter = 0;
	
	for(int i=0; i<nPlayers; i++) {
		const Player& p = getNextPlayer(g);
		if(p.isActive() == true) {
		activeCounter++;
		}
	}
	
	playerCounter = 1;
	
	if(activeCounter == 1) {
		return true;
	} else {
		return false;
	}
}

//Return next player in the array of players
const Player& Rules::getNextPlayer(const Game& g) {
	if(playerCounter == 1) {
		Player& p = g.getPlayer(Side::Bottom);
		playerCounter++;
		return p;
	} else if(playerCounter == 2) {
		Player& p = g.getPlayer(Side::Top);
		playerCounter++;
		return p;
	} else if(playerCounter == 3) {
		Player& p = g.getPlayer(Side::Left);
		playerCounter++;
		return p;
	} else {
		Player& p = g.getPlayer(Side::Right);
		return p;
	}
}
