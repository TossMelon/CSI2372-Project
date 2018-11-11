/* 
	CSI 2372 Project
	Memory Card Game - Memoarrr!
	
	Group 36
	Member 1: Huong Pham
	Student Number: 7831858
	
	Member 2: Matthew Choi
	Student Number: 8250803
*/

#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>

//Aggregate
class Reward;

using std::ostream;
using std::string;

class Player
{
	private:
		string name;
		char boardSide;
		int rubies;
		bool status;
	public:
		Player(string nameIn);
		Player(string nameIn, int playerNumber); //Player constructor
		string getName() const;
		void setActive(bool s);
		bool isActive();
		int getNRubies() const;
		void addReward(const Reward&);
		void setDisplayMode(bool endOfGame);
		friend ostream& operator<<(ostream& out, const Player& p);
};

#endif
