/*
	expertrules.cpp

	CSI 2372 Project
	Memory Card Game - Memoarrr!

	Group 36
	Member 1: Huong Pham
	Student Number: 7831858

	Member 2: Matthew Choi
	Student Number: 8250803
*/

//#define TEST_EXPERTRULES //ExpertRules Test Compile Switch

#include <iostream>
#include "expertrules.h"

using std::cout;
using std::cin;
using std::endl;

ExpertRules::ExpertRules(int numPlayers) : Rules(numPlayers) {}

Letter ExpertRules::getLetter(char letter) {
	switch(letter) {
	case 'A':
		return Letter::A;
	case 'B':
		return Letter::B;
	case 'C':
		return Letter::C;
	case 'D':
		return Letter::D;
	case 'E':
		return Letter::E;
	}
}

Number ExpertRules::getNumber(char number) {
	switch(number) {
	case '1':
		return Number::One;
	case '2':
		return Number::Two;
	case '3':
		return Number::Three;
	case '4':
		return Number::Four;
	case '5':
		return Number::Five;
	}
}

//True if previous and current cards match
//And current card cannot be one which is blocked by walrus attribute
//If true activate animal attribute
bool ExpertRules::isValid(const Game& g, const Board b) {
	if((Rules::isValid(g)) && (isBlocked(g) == false)) {
		animalAttribute(g, b); //Activate card ability
		return true; //Player choice is valid
	}

    return false; //Player choice is not valid
}

//Activate animal attribute of current card
void ExpertRules::animalAttribute(const Game& g, const Board b) {
	FaceAnimal animal = (FaceAnimal)*(g.getCurrentCard());
	switch(animal) {
    case FaceAnimal::Crab:
        crab();
        break;
    case FaceAnimal::Octopus:
        octopus();
        break;
	case FaceAnimal::Penguin:
        penguin(b);
        break;
    case FaceAnimal::Turtle:
        turtle(g);
        break;
    case FaceAnimal::Walrus:
        walrus(b);
        break;
    }
}

//Player gets another turn
void ExpertRules::crab() {
	cout<<"Crab card - activate attribute\n";
	cout<<"Player gets another turn"<<endl;
	playerCounter--;
}

//Player can turn a face-up card face-down
void ExpertRules::penguin(const Board b) {
	cout<<"Penguin card - activate attribute\n";
	char letter, number;
	cout<<"Choose a face-up card to turn face-down: "<<endl;
	cin>>letter>>number;

	Letter l = (Letter)letter;
	Number n = (Number)number;

	while(b.isFaceUp(l,n) == false) {
		cout<<"Error: Chosen card is already face-down.\n";
		cout<<"Choose a face-up card to turn face-down: "<<endl;
		cin>>letter>>number;
	}

	b.turnFaceDown(l, n);
}

//Card exchanges positions with an adjacent card at player's choice
void ExpertRules::octopus() {											////NOT FINISHED
	cout<<"Octopus card - activate attribute"<<endl;
	char letter, number;
	cout<<"Choose an adjacent card to exchange the current card with: "<<endl;
	cin>>letter>>number;
}

//Skips next player's turn
void ExpertRules::turtle(const Game& g) {
	cout<<"Turtle card - activate attribute"<<endl;
	Rules::getNextPlayer(g);
}

//Player chooses one face-down card to block - next player cannot reveal this location
void ExpertRules::walrus(const Board b) {
	cout<<"Walrus card - activate attribute"<<endl;
	char letter, number;
	cout<<"Choose a face-down card to blcok: "<<endl;
	cin>>letter>>number;

	Letter l = (Letter)letter;
	Number n = (Number)number;

	while(b.isFaceUp(l,n) == true) {
		cout<<"Error: Chosen card is not face-down.\n";
		cout<<"Choose a face-down card to blcok: "<<endl;
		cin>>letter>>number;
	}
	
	block(l,n,b);
}

//Identify animal and colour of chosen blocked card
void ExpertRules::block(const Letter& l, const Number& n, const Board b) {
	blockedAnimal = (FaceAnimal)*(b.getCard(l,n));
	blockedColour = (FaceBackground)*(b.getCard(l,n));
}

//True if player picks a card blocked by the walrus attribute
bool ExpertRules::isBlocked(const Game& g) {
	FaceAnimal animal = (FaceAnimal)*(g.getCurrentCard());
	FaceBackground colour = (FaceBackground)*(g.getCurrentCard());
	
	if(g.getPreviousCard() == nullptr) {
		return false;
	} else if((blockedAnimal == animal) && (blockedColour == colour)) {
		return true;
	} else {
		return false;
	}
}

//ExpertRules Unit Test
#ifdef TEST_EXPERTRULES

int main() {
	cout<<"Testing ExpertRules Class\n"<<endl;
	//check out of range input for getLetter() and getNumber()
}

#endif
