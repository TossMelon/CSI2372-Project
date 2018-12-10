/* 
	rewarddeck.h
	
	CSI 2372 Project
	Memory Card Game - Memoarrr!
	
	Group 36
	Member 1: Huong Pham
	Student Number: 7831858
	
	Member 2: Matthew Choi
	Student Number: 8250803
*/

#ifndef REWARDDECK_H
#define REWARDDECK_H

#include "deck.h"
#include "reward.h"

class RewardDeck: public Deck<Reward> {
	public:
		static RewardDeck& make_RewardDeck();
};

#endif // REWARDDECK_H
