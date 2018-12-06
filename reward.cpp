/* 
	reward.cpp
	
	CSI 2372 Project
	Memory Card Game - Memoarrr!
	
	Group 36
	Member 1: Huong Pham
	Student Number: 7831858
	
	Member 2: Matthew Choi
	Student Number: 8250803
*/

#include "reward.h"

//Reward constructor
Reward::Reward(Rubies r) {
	rubies = r;
}

Reward::operator int() const {
	switch(rubies) {
		case Rubies::One:
			return 1;
			break;
		case Rubies::Two:
			return 2;
			break;
		case Rubies::Three:
			return 3;
			break;
		case Rubies::Four:
			return 4;
			break;
	}
}

//Overload stream insertion operator
//Displays Reward
ostream &operator << (ostream &out, const Reward &r) {
	return out<<static_cast<int>(r);
}
