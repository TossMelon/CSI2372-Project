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

//#define TEST_PLAYER //Player Test Compile Switch

#include "player.h"

#include <iostream>
#include <string>

using std::endl;
using std::ostream;
using std::string;

bool Player::ENDGAME = false;
int Player::counter = 1;

//Player Constructor
Player::Player(string nameIn) {
	name = nameIn;

	if(counter == 1) {
		this->setSide(Side::Bottom);
		counter++;
	} else if(counter == 2) {
		this->setSide(Side::Top);
		counter++;
	} else if(counter == 3) {
		this->setSide(Side::Left);
		counter++;
	} else if (counter == 4) {
		this->setSide(Side::Right);
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
Side Player::getSide() const {
	return boardSide;
}

//Assign player to side of gameboard
void Player::setSide(Side side) {
	boardSide = side;
}

string convertSide(Side side) {
	if(side == Side::Top) {
		return "Top";
	} else if(side == Side::Bottom) {
		return "Bottom";
	} else if(side == Side::Left) {
		return "Left";
	} else {
		return "Right";
	}
}

//Overload stream insertion operator
//Displays Player stats based on endOfGame condition
ostream& operator<<(ostream& out, const Player& p) {
	if(Player::ENDGAME == false) {
		if(p.isActive()){
			out << p.getName()<<": "<<convertSide(p.getSide())<<" (active)"<<endl;
		} else {
			out << p.getName()<<": "<<convertSide(p.getSide())<<" (inactive)"<<endl;
		}
	} else {
		out<<p.getName()<<": "<<p.getNRubies()<<" rubies"<<endl;
	}

	return out;
}

//Player Unit Test
#ifdef TEST_PLAYER
#include "rewarddeck.cpp"

int main() {
	cout<<"Testing Player Class\n"<<endl;
	RewardDeck& deck = deck.make_RewardDeck();
	Reward* r = deck.getNext();
	
	cout<<"Create player with constructor using the name \"John Doe\""<<endl;
	Player p = Player("John Doe"); //Player constructor
	cout<<"Calling the getName() function gives: "<<p.getName()<<endl;
	cout<<"Calling the getSide() function gives: "<<convertSide(p.getSide())<<endl;
	cout<<"\nSetting the player's side to Right with setSide(Side side) function."<<endl;
	p.setSide(Side::Right);
	cout<<"The player's side is now: "<<convertSide(p.getSide())<<endl;
	cout<<"\nCalling the getNRubies() function gives the number of rubies: "<<p.getNRubies()<<endl;
	cout<<"Calling the addReward(const Reward& r) function and adding "<<*r<<" rubies,"<<endl;
	p.addReward(*r);
	cout<<"\nThe player now has a ruby count of: "<<p.getNRubies()<<endl;
	cout<<"Player's default status: ";
	
	if(p.isActive()) {
		cout<<"active"<<endl;
	} else {
		cout<<"inactive"<<endl;
	}
	
	cout<<"\nAdding a second player named Jane."<<endl;
	Player p2 = Player("Jane");
	
	cout<<"\nWhen Game is Not Over"<<endl;
	cout<<"Printing player 1 with overloaded ostream operator:\n"<<p;
	cout<<"\nPrinting player 2 with overloaded ostream operator:\n"<<p2;
	
	cout<<"\nSimulating end of round:";
	cout<<"\nCalling setActive(bool s) with s == false on player 1."<<endl;
	p.setActive(false);
	cout<<"\nWhen Game is Not Over But Round is Over With Player 1's Loss"<<endl;
	cout<<"Printing player 1 with overloaded ostream operator:\n"<<p;
	cout<<"\nPrinting player 2 with overloaded ostream operator:\n"<<p2<<endl;
	
	cout<<"Simulating end of game:";
	cout<<"\nCalling setDisplayMode(bool endOfGame) with endOfGame == true to simulate"<<endl;
	p.setDisplayMode(true);
	cout<<"\nWhen Game is Over"<<endl;
	cout<<"Printing player 1 with overloaded ostream operator:\n"<<p;
	cout<<"\nPrinting player 2 with overloaded ostream operator:\n"<<p2;
}

#endif
