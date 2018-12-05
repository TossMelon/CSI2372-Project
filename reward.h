/* 
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

class Reward
{
	private:
		Reward(); //Reward constructor
	public:
		friend ostream &operator << (ostream &out, const Reward &r);
	
};

#endif
