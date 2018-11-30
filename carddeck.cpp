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
#include "deck.cpp"
#include "card.cpp"

CardDeck cDeck; //Create variable to hold card deck

//Makes card deck with appropriate cards
CardDeck& CardDeck::make_CardDeck() {
	if(cDeck.isEmpty()) {
		//Create and add all 5 Crab cards to card deck
		cDeck.addCard(Card(FaceAnimal::Crab,FaceBackground::Red));
		cDeck.addCard(Card(FaceAnimal::Crab,FaceBackground::Green));
		cDeck.addCard(Card(FaceAnimal::Crab,FaceBackground::Purple));
		cDeck.addCard(Card(FaceAnimal::Crab,FaceBackground::Blue));
		cDeck.addCard(Card(FaceAnimal::Crab,FaceBackground::Yellow));
		
		//Create and add all 5 Penguin cards to card deck
		cDeck.addCard(Card(FaceAnimal::Penguin,FaceBackground::Red));
		cDeck.addCard(Card(FaceAnimal::Penguin,FaceBackground::Green));
		cDeck.addCard(Card(FaceAnimal::Penguin,FaceBackground::Purple));
		cDeck.addCard(Card(FaceAnimal::Penguin,FaceBackground::Blue));
		cDeck.addCard(Card(FaceAnimal::Penguin,FaceBackground::Yellow));
		
		//Create and add all 5 Octopus cards to card deck
		cDeck.addCard(Card(FaceAnimal::Octopus,FaceBackground::Red));
		cDeck.addCard(Card(FaceAnimal::Octopus,FaceBackground::Green));
		cDeck.addCard(Card(FaceAnimal::Octopus,FaceBackground::Purple));
		cDeck.addCard(Card(FaceAnimal::Octopus,FaceBackground::Blue));
		cDeck.addCard(Card(FaceAnimal::Octopus,FaceBackground::Yellow));
		
		//Create and add all 5 Turtle cards to card deck
		cDeck.addCard(Card(FaceAnimal::Turtle,FaceBackground::Red));
		cDeck.addCard(Card(FaceAnimal::Turtle,FaceBackground::Green));
		cDeck.addCard(Card(FaceAnimal::Turtle,FaceBackground::Purple));
		cDeck.addCard(Card(FaceAnimal::Turtle,FaceBackground::Blue));
		cDeck.addCard(Card(FaceAnimal::Turtle,FaceBackground::Yellow));
		
		//Create and add all 5 Walrus cards to card deck
		cDeck.addCard(Card(FaceAnimal::Walrus,FaceBackground::Red));
		cDeck.addCard(Card(FaceAnimal::Walrus,FaceBackground::Green));
		cDeck.addCard(Card(FaceAnimal::Walrus,FaceBackground::Purple));
		cDeck.addCard(Card(FaceAnimal::Walrus,FaceBackground::Blue));
		cDeck.addCard(Card(FaceAnimal::Walrus,FaceBackground::Yellow));
		
		//Shuffle card deck
		cDeck.shuffle();
	}
	return cDeck;
}
