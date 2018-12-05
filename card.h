/*
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

using namespace std;

enum FaceAnimal{
	Crab, Penguin, Octopus, Turtle, Walrus
};
enum FaceBackground{
	Red, Green, Purple, Blue, Yellow
};

static const char* AnimalEnum[] = {"C", "P", "O", "T", "W"};
static const char* BackEnum[] = {"R", "G", "P", "B", "Y"};

class Card
{
	FaceAnimal face;
	FaceBackground colour;
	Card(FaceAnimal, FaceBackground); //Card constructor
	public:
	    Card();
		string row(int);
		void print();
    friend void CardDeck();


};

#endif
