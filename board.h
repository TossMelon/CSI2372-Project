/* 
	CSI 2372 Project
	Memory Card Game - Memoarrr!
	
	Group 36
	Member 1: Huong Pham
	Student Number: 7831858
	
	Member 2: Matthew Choi
	Student Number: 8250803
*/

#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <string>
#include <array>

//Aggregates
class Letter;
class Number;

using std::ostream;
using std::string;

class Board
{
	string d[];
	public:
		Board(); //Board constructor
		bool isFaceUp(const Letter&, const Number&);
		bool turnFaceUp(const Letter&, const Number&);
		bool turnFaceDown(const Letter&, const Number&);
		void reset();
		friend ostream &operator<<(ostream &out, const Board &b);
};

#endif
