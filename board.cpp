/* 
	CSI 2372 Project
	Memory Card Game - Memoarrr!
	
	Group 36
	Member 1: Huong Pham
	Student Number: 7831858
	
	Member 2: Matthew Choi
	Student Number: 8250803
*/

#include "board.h"

#include <iostream>

using std::endl;
using std::ostream;

//Board constructor
Board::Board() {
	
}

//Returns true if the card at a given position is face up
//Throws an exception of type OutOfRange if an invalid Letter and Number combination was given
bool isFaceUp(const Letter&, const Number&) {
	
}
	
//Changes state of the specified card to face up, return true
//If card was already face up, return false
//Throw OutOfRange exception if invalid Letter and Number combination was given
bool turnFaceUp(const Letter&, const Number&) {
	/*if(!isFaceUp(a, b)) {
		
		return true;
	}*/
	return false;
}

//Changes state of the specified card to face down, return true
//If card was already face down, return false
//Throw OutOfRange exception if invalid Letter and Number combination was given
bool turnFaceDown(const Letter&, const Number&) {
	/*if(isFaceUp(a, b)) {
		
		return true;
	}*/
	return false;
}

//Changes the state of all cards to be face down
void reset() {
	/*if( isFaceUp(a, b)) {
		turnFaceDown(a, b);
	}*/
}

//Overload stream insertion operator
//Displays board
ostream &operator<<(ostream &out, const Board &b) {
	out <<b<<endl;
	return out;
}
