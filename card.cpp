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

//#define TEST_CARD //Card Test Compile Switch

#include "card.h"

using std::cout;
using std::endl;

//Card Constructor
Card::Card(FaceAnimal faceIn, FaceBackground backIn) {
	face = faceIn;
	colour = backIn;
	nRows = 3;

	switch(face) {
		case FaceAnimal::Crab:
			charFace = 'C';
			break;
		case FaceAnimal::Penguin:
			charFace = 'P';
			break;
		case FaceAnimal::Octopus:
			charFace = 'O';
			break;
		case FaceAnimal::Turtle:
			charFace = 'T';
			break;
		case FaceAnimal::Walrus:
			charFace = 'W';
			break;
	}

	switch(colour) {
		case FaceBackground::Red:
			charColour = 'r';
			break;
		case FaceBackground::Green:
			charColour = 'g';
			break;
		case FaceBackground::Purple:
			charColour = 'p';
			break;
		case FaceBackground::Blue:
			charColour = 'b';
			break;
		case FaceBackground::Yellow:
			charColour = 'y';
			break;
	}
}

//Type FaceBackground conversion operator
Card::operator FaceBackground() const {
	return colour;
}

//Type FaceAnimal conversion operator
Card::operator FaceAnimal() const {
	return face;
}

//Return number of rows in card
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

//Card Unit Test
#ifdef TEST_CARD
#include "carddeck.h"
#include "deck.h"

int main() {
	cout<<"Testing Card Class\n"<<endl;
	
	CardDeck& deck = deck.make_CardDeck();
	Card* c = cDeck.getNext();
	Card& card = *c;
	
	cout<<"Using ostream operator - The card is:\n"<<*c<<endl; //test ostream operator overload
    cout<<"This card has "<<c->getNRows()<<" rows"<<endl; //test getNrows()
    cout<<"The 1st row is: "<<card(0)<<endl;	//test int
    cout<<"The 2nd row is: "<<card(1)<<endl;	//conversion
    cout<<"The 3rd row is: "<<card(2)<<endl;	//operator

	string colour = "";
	string animal = "";
	
	//Convert FaceBackground type to string
	switch((FaceBackground)*c) {
		case FaceBackground::Red:
			colour = "Red";
			break;
		case FaceBackground::Green:
			colour = "Green";
			break;
		case FaceBackground::Purple:
			colour = "Purple";
			break;
		case FaceBackground::Blue:
			colour = "Blue";
			break;
		case FaceBackground::Yellow:
			colour = "Yellow";
	}
	
	//Convert FaceAnimal type to string
	switch((FaceAnimal)*c) {
		case FaceAnimal::Crab:
			animal = "Crab";
			break;
		case FaceAnimal::Penguin:
			animal = "Penguin";
			break;
		case FaceAnimal::Octopus:
			animal = "Octopus";
			break;
		case FaceAnimal::Turtle:
			animal = "Turtle";
			break;
		case FaceAnimal::Walrus:
			animal = "Walrus";
	}
	
	cout<<"\nCard's animal and colour obtained from FaceBackground() and FaceAnimal() conversion operators:"<<endl;
    cout<<"Background Colour: "<<colour<<endl; //Display corresponding string after calling conversion operator to type FaceBackground
    cout<<"Animal Type: "<<animal<<endl; //Display corresponding string after calling conversion operator to type FaceAnimal

	return 0;
}

#endif
