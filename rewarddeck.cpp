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
#include "deck.h"
#include "reward.h"

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
