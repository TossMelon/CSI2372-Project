/*
	reward.cpp

	CSI 2372 Project
	Memory Card Game - Memoarrr!

	Group 36
	Member 1: Huong Pham
	Student Number: 7831858

	Member 2: Matthew Choi
	Student Number: 8250803
*/

//#define TEST_REWARD //Reward Test Compile Switch

#include <iostream>
#include "reward.h"

using std::cout;
using std::endl;

//Reward constructor
Reward::Reward(Rubies r) {
	rubies = r;
}

//int conversion operator
Reward::operator int() const {
	switch(rubies) {
		case Rubies::One:
			return 1;
			break;
		case Rubies::Two:
			return 2;
			break;
		case Rubies::Three:
			return 3;
			break;
		case Rubies::Four:
			return 4;
			break;
	}
	return 0;
}

//Overload stream insertion operator
//Displays Reward
ostream &operator << (ostream &out, const Reward &r) {
	return out<<static_cast<int>(r);
}

//Reward Unit Test
#ifdef TEST_REWARD
#include "rewarddeck.h"

int main() {
	cout<<"Testing Reward Class"<<endl;

	RewardDeck& deck = deck.make_RewardDeck();
	Reward* r = deck.getNext();
	int value = 0;
	
	while(r != nullptr) {
		//The following two lines should match for each reward card
		cout<<"\nostream output: "<<*r<<endl; //use overloaded ostream operator to display all reward cards of the deck
		cout<<"int conversion output: "<<(int)*r<<endl; //use int conversion operator to display all reward cards of the deck
		r = deck.getNext();
	}
}

#endif
