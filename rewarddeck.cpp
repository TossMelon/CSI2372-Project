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

Deck<Reward> rDeck; //Create variable to hold reward deck
bool rExist = false; //false --> reward deck has not yet been made

//Makes reward deck with appropriate cards
template <class Reward>
static RewardDeck& make_RewardDeck() {
	if(rExist == false) {
		//Create and add all reward cards to reward deck
		rDeck.myvector.push_back(new Reward(1));
		rDeck.myvector.push_back(new Reward(1));
		rDeck.myvector.push_back(new Reward(1));
		rDeck.myvector.push_back(new Reward(2));
		rDeck.myvector.push_back(new Reward(2));
		rDeck.myvector.push_back(new Reward(3));
		rDeck.myvector.push_back(new Reward(4));
		
		//Shuffle reward deck
		rDeck.shuffle();
		
		//Reward deck now exists, disallows anymore reward decks from being formed this game
		rExist = true;
	}
}
