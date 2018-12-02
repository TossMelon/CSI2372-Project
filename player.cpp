/* 
	player.cpp
	
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

bool Player::ENDGAME = false;

//Player Constructor
Player::Player(string nameIn, int playerNumber) {
	name = nameIn;
	
	if(playerNumber == 1) {
		this->setSide(Bottom);
	} else if(playerNumber == 2) {
		this->setSide(Top);
	} else if(playerNumber == 3) {
		this->setSide(Left);
	} else {
		this->setSide(Right);
	}
	
	rubies = 0;
	status = true;
}

//Return Player name
string Player::getName() const {
	return name;
}

//Set Player status as active or inactive
//If status == true player is active, if status == false player is inactive
void Player::setActive(bool s) {
	status = s;
}

//Returns true if Player status is active, false otherwise
bool Player::isActive() const{
	return status;
}

//Return number of rubies won by this Player
int Player::getNRubies() const {
	return rubies;
}

//Add a reward with a given number of rubies
void Player::addReward(const Reward& r) {
	rubies = rubies + r;
}

//Set display mode for player output
void Player::setDisplayMode(bool endOfGame) {
	ENDGAME = endOfGame;
}

//Returns side of board which player is on
Side Player::getSide() {
	return boardSide;
}

//Assign player to side of gameboard
void Player::setSide(Side side) {
	boardSide = side;
}

//Overload stream insertion operator
//Displays Player stats based on ENDGAME condition
ostream& operator<<(ostream& out, const Player& p) {
	if(Player::ENDGAME == false) {
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
