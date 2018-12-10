/* 
	reward.h
	
	CSI 2372 Project
	Memory Card Game - Memoarrr!
	
	Group 36
	Member 1: Huong Pham
	Student Number: 7831858
	
	Member 2: Matthew Choi
	Student Number: 8250803
*/

#ifndef REWARD_H
#define REWARD_H

#include <iostream>

using std::ostream;

enum class Rubies { One, Two, Three, Four };

class Reward
{
	friend class RewardDeck;
	private:
		Rubies rubies;
		Reward(Rubies rubies); //Reward constructor
	public:
		operator int() const; //Conversion operator
		friend ostream &operator << (ostream &out, const Reward &r); //Ostream operator
};

#endif // REWARD_H
