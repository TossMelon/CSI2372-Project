/*
	rewarddeck.cpp

	CSI 2372 Project
	Memory Card Game - Memoarrr!

	Group 36
	Member 1: Huong Pham
	Student Number: 7831858

	Member 2: Matthew Choi
	Student Number: 8250803
*/

//#define TEST_REWARDDECK //RewardDeck Test Compile Switch

#include "rewarddeck.h"

RewardDeck rDeck; //Create variable to hold reward deck

//If no reward deck exists, make deck with appropriate cards
//Else return existing deck
RewardDeck& RewardDeck::make_RewardDeck() {
	if(rDeck.isEmpty()) {
		//Create and add all reward cards to reward deck
		rDeck.myvector.push_back(Reward(Rubies::One));
		rDeck.myvector.push_back(Reward(Rubies::One));
		rDeck.myvector.push_back(Reward(Rubies::One));
		rDeck.myvector.push_back(Reward(Rubies::Two));
		rDeck.myvector.push_back(Reward(Rubies::Two));
		rDeck.myvector.push_back(Reward(Rubies::Three));
		rDeck.myvector.push_back(Reward(Rubies::Four));

		//Shuffle reward deck
		rDeck.shuffle();
	}
	return rDeck;
}

//RewardDeck Unit Test
#ifdef TEST_REWARDDECK

int main() {
	cout<<"Testing RewardDeck Class"<<endl;
	
	int numCards = 0;
	int nOne = 0, nTwo = 0, nThree = 0, nFour = 0;
	
	cout<<"Make Reward Deck"<<endl;
	RewardDeck& d = RewardDeck::make_RewardDeck();
	cout<<"Print all Cards in Shuffled Reward Deck:\n"<<endl;
	
	Reward* r = d.getNext();
	while(r != nullptr) {
		cout<<*r<<endl;

		if((int)*r == 1) {
			nOne++;
		} else if((int)*r == 2) {
			nTwo++;
		} else if((int)*r == 3) {
			nThree++;
		} else if((int)*r == 4) {
			nFour++;
		}
		
		numCards++;
		r=d.getNext();
	}
	
	cout<<"\nThis reward deck has a total of "<<numCards<<" cards\n";
	cout<<"Number of Each Type of Reward Card:\n";
	cout<<nOne<<" Cards with One Ruby\n";
	cout<<nTwo<<" Cards with Two Rubies\n";
	cout<<nThree<<" Cards with Three Rubies\n";
	cout<<nFour<<" Cards with Four Rubies\n";
}

#endif
