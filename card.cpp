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
#include <sstream>
#include <iostream>

using namespace std;

//Card Constructor
Card::Card(FaceAnimal faceIn, FaceBackground backIn) {
	face = faceIn;
	colour = backIn;
}

Card::Card(){
    face = Crab;
    colour = Red;
}

//Returns a string for correspond rowNum of card
string Card::row(int rowNum) {
	stringstream ss;
	if(rowNum == 0 || rowNum == 2) {
		ss << BackEnum[colour]<<BackEnum[colour]<<BackEnum[colour];
		return ss.str();
	} else {
		ss << BackEnum[colour]<<AnimalEnum[colour]<<BackEnum[colour];
		return ss.str();
	}
}

//Print Card
void Card::print() {
	Card c(Penguin, Red);
	for(int row = 0; row<3; ++row) {
		string rowString = c.row(row);
		cout << rowString << endl;
	}
}
