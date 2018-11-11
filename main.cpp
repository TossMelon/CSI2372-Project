/* 
	CSI 2372 Project
	Memory Card Game - Memoarrr!
	
	Group 36
	Member 1: Huong Pham
	Student Number: 7831858
	
	Member 2: Matthew Choi
	Student Number: 8250803
*/

#include <iostream>
#include <random>
#include <string>

#include "player.cpp"
/*#include "card.h"
#include "reward.h"
#include "deck<C>.h"
#include "carddeck.h"
#include "rewarddeck.h"
#include "board.h"
#include "game.h"
#include "rules.h"*/

using std::cout;
using std::cin;
using std::endl;
using std::string;

using std::srand;
using std::rand;

int main() {
	int mode, players;
	string name;
	
	cout<<"Memoarrr!"<<endl;
	cout<<"Choose a game version (1-3):"<<endl;
	cout<<"(1) Base Mode"<<endl;
	cout<<"(2) Expert Display Mode"<<endl;
	cout<<"(3) Experrt Rules Mode"<<endl;
	cout<<"Game version: ";
	cin>>mode;
	
	cout<<"Enter the number of players (1-4): ";
	cin>>players;
	
	Player *playerArray [players];
	
	
	for(int i=1; i<=players; i++) {
		cout<<"Enter Name of Player " <<i<<": "<<std::flush;
		cin>>name;
		cin.ignore(256, '\n' );
		playerArray[i - 1] = new Player;
	}
	
	/*while(!Rules.gameOver()) {
		
		
		while(!Rules.roundOver()) {
			
			
		}
		
	}*/

	return 0;	
}
