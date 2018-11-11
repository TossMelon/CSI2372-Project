/* 
	CSI 2372 Project
	Memory Card Game - Memoarrr!
	
	Group 36
	Member 1: Huong Pham
	Student Number: 7831858
	
	Member 2: Matthew Choi
	Student Number: 8250803
*/

#include "rules.h"

Rules::Rules() {
	
}

//Returns true if previous and current cards match, false otherwise
bool isValid(const Game& g) {
	if(g.getPreviousCard() == g.getCurrentCard()) {
		return true;
	}	
	return false;
}

//Returns true if the number of rounds has reached 7
bool gameOver(const Game& g) {
	if(g.getRound() == 7) {
		return true;
	}
	return false;
}

//Return true if there is only one active Player left
bool roundOver(const Game& g) {
	if(g.getNextPlayer() == NULL) {
		return true;
	}
	return false;
}
