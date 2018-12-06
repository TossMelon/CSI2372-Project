/* 
	card.h
	
	CSI 2372 Project
	Memory Card Game - Memoarrr!
	
	Group 36
	Member 1: Huong Pham
	Student Number: 7831858
	
	Member 2: Matthew Choi
	Student Number: 8250803
*/

#ifndef CARD_H
#define CARD_H

#include <string>
#include <iostream>

using std::ostream;
using std::string;

enum class FaceAnimal{ Crab, Penguin, Octopus, Turtle, Walrus };

enum class FaceBackground { Red, Green, Purple, Blue, Yellow };

class Card
{
	friend class CardDeck;
	
	FaceAnimal face;
	FaceBackground colour;
	char charFace;
	char charColour;
	int nRows;
	
	Card(FaceAnimal, FaceBackground); //Card constructor
	
	public:
		string operator()(int) const;
		operator FaceBackground() const; //Conversion operator to FaceBackground
		operator FaceAnimal() const; //Conversion operator to FaceAnimal
		int getNRows() const;
		friend ostream& operator<<(ostream&, const Card&);
};

#endif
