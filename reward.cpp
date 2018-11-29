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

#include "rewarddeck.h"
#include "deck.cpp"
#include "reward.cpp"

#include <iostream>

RewardDeck rDeck; //Create variable to hold reward deck

//Makes reward deck with appropriate cards
RewardDeck& RewardDeck::make_RewardDeck() {
	if(rDeck.isEmpty()) {
		//Create and add all reward cards to reward deck
		rDeck.addCard(Reward(1));
		rDeck.addCard(Reward(1));
		rDeck.addCard(Reward(1));
		rDeck.addCard(Reward(2));
		rDeck.myvector.push_back(Reward(2));
		rDeck.addCard(Reward(3));
		rDeck.addCard(Reward(4));
		
		//Shuffle reward deck
		rDeck.shuffle();
	}
	
	return rDeck;
}
