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

//#define TEST_RULES //Rules Test Compile Switch

#include "rules.h"
#include "card.h"

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

	Player& p = g.getPlayer(Side::Bottom);
	
	if(p.isActive()) {
		activeCounter++;
	}
	
	p = g.getPlayer(Side::Top);
	
	if(p.isActive()) {
		activeCounter++;
	}
	
	p = g.getPlayer(Side::Left);
	
	if(p.isActive()) {
		activeCounter++;
	}
	
	p = g.getPlayer(Side::Right);
	
	if(p.isActive()) {
		activeCounter++;
	}

	if(activeCounter == 1) {
		return true;
	} else {
		return false;
	}
}

//Return next active player in the array of players
const Player& Rules::getNextPlayer(const Game& g) {
	if(playerCounter == 1) {
		Player& p = g.getPlayer(Side::Bottom);
        playerCounter++;

		if(p.isActive()){
            return p;
        } else {
            p = getNextPlayer(g);
            return p;
        }
	} else if(playerCounter == 2) {
		Player& p = g.getPlayer(Side::Top);
		playerCounter++;

		if(p.isActive()){
            return p;
        } else {
            p = getNextPlayer(g);
            return p;
        }
	} else if(playerCounter == 3) {
		Player& p = g.getPlayer(Side::Left);
		playerCounter++;

		if(p.isActive()){
            return p;
        } else {
            p = getNextPlayer(g);
            return p;
        }
	} else {
		Player& p = g.getPlayer(Side::Right);
		playerCounter = 1;

		if(p.isActive()){
            return p;
        } else {
            p = getNextPlayer(g);
            return p;
        }
	}
}

//Rules Unit Test
#ifdef TEST_RULES

int main() {
	cout<<"Testing Rules Class\n"<<endl;
	/*Rules(int numPlayers); //Rules constructor
	bool isValid(const Game& g);
	bool gameOver(const Game& g);
	bool roundOver(const Game& g);
	const Player& getNextPlayer(const Game& g);*/
}

#endif
