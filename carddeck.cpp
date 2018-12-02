/* 
	carddeck.cpp
	
	CSI 2372 Project
	Memory Card Game - Memoarrr!
	
	Group 36
	Member 1: Huong Pham
	Student Number: 7831858
	
	Member 2: Matthew Choi
	Student Number: 8250803
*/

#include "carddeck.h"
#include "deck.h"
#include "card.h"

CardDeck cDeck; //Create variable to hold card deck

//If no card deck exists, make deck with appropriate cards
//Else return existing deck
CardDeck& CardDeck::make_CardDeck() {
	if(cDeck.isEmpty()) {
		//Create and add all 5 Crab cards to card deck
		cDeck.myvector.push_back(Card(FaceAnimal::Crab,FaceBackground::Red));
		cDeck.myvector.push_back(Card(FaceAnimal::Crab,FaceBackground::Green));
		cDeck.myvector.push_back(Card(FaceAnimal::Crab,FaceBackground::Purple));
		cDeck.myvector.push_back(Card(FaceAnimal::Crab,FaceBackground::Blue));
		cDeck.myvector.push_back(Card(FaceAnimal::Crab,FaceBackground::Yellow));
		
		//Create and add all 5 Penguin cards to card deck
		cDeck.myvector.push_back(Card(FaceAnimal::Penguin,FaceBackground::Red));
		cDeck.myvector.push_back(Card(FaceAnimal::Penguin,FaceBackground::Green));
		cDeck.myvector.push_back(Card(FaceAnimal::Penguin,FaceBackground::Purple));
		cDeck.myvector.push_back(Card(FaceAnimal::Penguin,FaceBackground::Blue));
		cDeck.myvector.push_back(Card(FaceAnimal::Penguin,FaceBackground::Yellow));
		
		//Create and add all 5 Octopus cards to card deck
		cDeck.myvector.push_back(Card(FaceAnimal::Octopus,FaceBackground::Red));
		cDeck.myvector.push_back(Card(FaceAnimal::Octopus,FaceBackground::Green));
		cDeck.myvector.push_back(Card(FaceAnimal::Octopus,FaceBackground::Purple));
		cDeck.myvector.push_back(Card(FaceAnimal::Octopus,FaceBackground::Blue));
		cDeck.myvector.push_back(Card(FaceAnimal::Octopus,FaceBackground::Yellow));
		
		//Create and add all 5 Turtle cards to card deck
		cDeck.myvector.push_back(Card(FaceAnimal::Turtle,FaceBackground::Red));
		cDeck.myvector.push_back(Card(FaceAnimal::Turtle,FaceBackground::Green));
		cDeck.myvector.push_back(Card(FaceAnimal::Turtle,FaceBackground::Purple));
		cDeck.myvector.push_back(Card(FaceAnimal::Turtle,FaceBackground::Blue));
		cDeck.myvector.push_back(Card(FaceAnimal::Turtle,FaceBackground::Yellow));
		
		//Create and add all 5 Walrus cards to card deck
		cDeck.myvector.push_back(Card(FaceAnimal::Walrus,FaceBackground::Red));
		cDeck.myvector.push_back(Card(FaceAnimal::Walrus,FaceBackground::Green));
		cDeck.myvector.push_back(Card(FaceAnimal::Walrus,FaceBackground::Purple));
		cDeck.myvector.push_back(Card(FaceAnimal::Walrus,FaceBackground::Blue));
		cDeck.myvector.push_back(Card(FaceAnimal::Walrus,FaceBackground::Yellow));
		
		//Shuffle card deck
		cDeck.shuffle();
	}
	return cDeck;
}
