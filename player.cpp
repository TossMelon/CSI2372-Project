/* 
	CSI 2372 Project
	Memory Card Game - Memoarrr!
	
	Group 36
	Member 1: Huong Pham
	Student Number: 7831858
	
	Member 2: Matthew Choi
	Student Number: 8250803
*/

#include "player.h"
#include "reward.h"

#include <iostream>
#include <string>

using std::endl;
using std::ostream;
using std::string;

bool endOfGame = true;

//Player Constructor
Player::Player(string nameIn) {
	name = nameIn;
	boardSide = 'B';
	rubies = 0;
	status = true;
}

Player::Player(string nameIn, int playerNumber) {
	name = nameIn;
	
	if(playerNumber == 1) {
		boardSide = 'B';
	} else if(playerNumber == 2) {
		boardSide = 'T';
	} else if(playerNumber == 3) {
		boardSide = 'L';
	} else {
		boardSide = 'R';
	}
	
	rubies = 0;
	status = true;
}

//Return Player name
string Player::getName() const {
	return name;
}

//Set Player status as active or inactive
//if status == true player is active, if status == false player is inactive
void Player::setActive(bool s) {
	status = s;
}

//Returns true if Player status is active, false otherwise
bool Player::isActive() {
	return status;
}

//Return number of rubies won by this Player
int Player::getNRubies() const {
	return rubies;
}

//Add a reward with a given number of rubies
void Player::addReward(const Reward&) {
	rubies = rubies + 10; //sub 10 with ruby value from Reward
}

//
void Player::setDisplayMode(bool endOfGame) {
	
}

//Overload stream insertion operator
//Displays Player stats based on endOfGame condition
ostream& operator<<(ostream& out, const Player& p) {
	if(endOfGame == false) {
		if(p.isActive()){
			out << p.getName()<<": "<<p.boardSide<<" (active)"<<endl;
		} else {
			out << p.getName()<<": "<<p.boardSide<<" (inactive)"<<endl;
		}
	} else {
		out<<p.getName()<<": "<<p.getNRubies()<<" rubies"<<endl;
	}
	
	return out;
}
