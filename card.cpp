/* 
	card.cpp
	
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
#include <iostream>

using std::string;
using std::cout;
using std::endl;

//Card Constructor
Card::Card(FaceAnimal faceIn, FaceBackground backIn) {
	face = faceIn;
	colour = backIn;
	nRows = 3;
	
	switch(face) {
		case Crab:
			charFace = 'C';
			break;
		case Penguin:
			charFace = 'P';
			break;
		case Octopus:
			charFace = 'O';
			break;
		case Turtle:
			charFace = 'T';
			break;
		case Walrus:
			charFace = 'W';
			break;
	}
	
	switch(colour) {
		case Red:
			charColour = 'r';
			break;
		case Green:
			charColour = 'g';
			break;
		case Purple:
			charColour = 'p';
			break;
		case Blue:
			charColour = 'b';
			break;
		case Yellow:
			charColour = 'y';
			break;
	}
	
}

Card::operator FaceBackground() const {
	return colour;
}

Card::operator FaceAnimal() const {
	return face;
} 

int Card::getNRows() const {
	return nRows;
}

//Returns a string for correspond rowNum of card
string Card::operator()(int row) const {
	string s;
	s.push_back(charColour);
	
	if(row == 0 || row == 2) {
		s.push_back(charColour);
	} else {
		s.push_back(charFace);
	}
	
	s.push_back(charColour);
	return s;
}

//Print Card
ostream& operator<<(ostream& out, const Card& c) {
	for(int row = 0; row<c.getNRows(); ++row) {
		string rowString = c(row);
		cout << rowString << endl;
	}
	return out;
}
