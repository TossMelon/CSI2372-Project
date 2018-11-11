/* 
	CSI 2372 Project
	Memory Card Game - Memoarrr!
	
	Group 36
	Member 1: Huong Pham
	Student Number: 7831858
	
	Member 2: Matthew Choi
	Student Number: 8250803
*/

#include "card.h"

#include <string>

using std::string;
using std::cout;
using std::endl;

//Card Constructor
Card::Card( char faceIn, char colourIn) {
	face = faceIn;
	colour = colourIn;
}

//Returns a string for correspond rowNum of card
string Card::row(int rowNum) {
	if(rowNum == 0 || rowNum == 2) {
		return colour<<colour<<colour;
	} else {
		return colour<<face<<colour;
	}
}

//Print Card
void Card::print() {
	for(int row = 0; row<3; ++row) {
		string rowString = c(row);
		cout << rowString << endl;
	}
}
