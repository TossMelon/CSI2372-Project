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
	playerCounter = 1;
}

char Rules::convert(FaceAnimal a) const {
	switch(a) {
		case Crab:
			return 'C';
			break;
		case Penguin:
			return 'P';
			break;
		case Octopus:
			return 'O';
			break;
		case Turtle:
			return 'T';
			break;
		case Walrus:
			return 'W';
			break;
	}
}

char Rules::convert(FaceBackground b) const {
	switch(b) {
		case Red:
			return 'r';
			break;
		case Green:
			return 'g';
			break;
		case Purple:
			return 'p';
			break;
		case Blue:
			return 'b';
			break;
		case Yellow:
			return 'y';
			break;
	}
}

//Returns true if previous and current cards match, false otherwise
bool Rules::isValid(const Game& g) {
	const Card* prev = g.getPreviousCard();
	const Card* curr = g.getCurrentCard();
	char prevAnimal, prevColour, currAnimal, currColour;
	
	prevAnimal = convert((FaceAnimal)*prev);
	prevColour = convert((FaceBackground)*prev);
	
	currAnimal = convert((FaceAnimal)*curr);
	currColour = convert((FaceBackground)*curr);
	
	if(prevAnimal == currAnimal) {
		return true;
	} else if (prevColour == currColour) {
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
	
	for(int i=0; i<3; i++) {
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
		Player& p = g.getPlayer(Bottom);
		playerCounter++;
		return p;
	} else if(playerCounter == 2) {
		Player& p = g.getPlayer(Top);
		playerCounter++;
		return p;
	} else if(playerCounter == 3) {
		Player& p = g.getPlayer(Left);
		playerCounter++;
		return p;
	} else {
		Player& p = g.getPlayer(Right);
		return p;
	}
}
