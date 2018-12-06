/* 
	player.h
	
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

enum class Side { Top, Bottom, Left, Right };

class Player
{
	private:
		string name;
		Side boardSide;
		int rubies;
		bool status;
		static bool ENDGAME;
	public:
		Player(string nameIn, int playerNumber); //Player constructor
		string getName() const;
		void setActive(bool s);
		bool isActive() const;
		int getNRubies() const;
		void addReward(const Reward& r);
		void setDisplayMode(bool endOfGame);
		Side getSide() const;
		void setSide(Side side);
		friend ostream& operator<<(ostream& out, const Player& p);
};

#endif
