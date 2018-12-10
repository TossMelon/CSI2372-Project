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
#include <windows.h>

#include "player.cpp"
#include "card.h"
#include "reward.h"
#include "deck.h"
#include "carddeck.h"
#include "rewarddeck.h"
#include "board.h"
#include "game.h"
#include "rules.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;

using std::srand;
using std::rand;

int main() {
	int mode, players;
	string name;
	Game g;
	Board b;

	RewardDeck& d = RewardDeck::make_RewardDeck();


	cout<<"Memoarrr!"<<endl;
	cout<<"Choose a game version (1-3):"<<endl;
	cout<<"(1) Base Mode"<<endl;
	cout<<"(2) Expert Display Mode"<<endl;
	cout<<"(3) Experrt Rules Mode"<<endl;
	cout<<"Game version: ";
	cin>>mode;

	cout<<"Enter the number of players (1-4): ";
	cin>>players;
    Rules rules(players);

	for(int i=1; i<=players; i++) {
		cout<<"Enter Name of Player " <<i<<": "<<std::flush;
		cin>>name;
		cin.ignore(256, '\n' );
		Player* p = new Player(name);
		g.addPlayer(*p); //add players
	}
    for(int i = 0; i < 5; i ++){ //turn all cards face down
        for(int j = 0; j < 5; j++){
                b.turnFaceDown(static_cast<Letter>(i), static_cast<Number>(j));
        }
    }
	cout << g; //print out board, cards face down
	while(!rules.gameOver(g)){
        for(int i = 0; i < players; i ++){ //make all players active
                g.getPlayer(static_cast<Side>(i)).setActive(true);
        }
        b.turnFaceUp(Letter::A, Number::Two); //TOP up
        b.turnFaceUp(Letter::A, Number::Three);
        b.turnFaceUp(Letter::A, Number::Four);

        cout << g;
        Sleep(3);

        b.turnFaceDown(Letter::A, Number::Two); //TOP down
        b.turnFaceDown(Letter::A, Number::Three);
        b.turnFaceDown(Letter::A, Number::Four);

        cout << g;
        Sleep(3);

        b.turnFaceUp(Letter::B, Number::Five); //RIGHT up
        b.turnFaceUp(Letter::C, Number::Five);
        b.turnFaceUp(Letter::D, Number::Five);

        cout << g;
        Sleep(3);

        b.turnFaceDown(Letter::B, Number::Five); //RIGHT down
        b.turnFaceDown(Letter::C, Number::Five);
        b.turnFaceDown(Letter::D, Number::Five);

        cout << g;
        Sleep(3);

        b.turnFaceUp(Letter::E, Number::Two); //BOTTOM up
        b.turnFaceUp(Letter::E, Number::Three);
        b.turnFaceUp(Letter::E, Number::Four);

        cout << g;
        Sleep(3);

        b.turnFaceDown(Letter::E, Number::Two); //BOTTOM down
        b.turnFaceDown(Letter::E, Number::Three);
        b.turnFaceDown(Letter::E, Number::Four);

        cout << g;
        Sleep(3);

        b.turnFaceUp(Letter::B, Number::One); //LEFT up
        b.turnFaceUp(Letter::C, Number::One);
        b.turnFaceUp(Letter::D, Number::One);

        cout << g;
        Sleep(3);

        b.turnFaceDown(Letter::B, Number::One); //LEFT down
        b.turnFaceDown(Letter::C, Number::One);
        b.turnFaceDown(Letter::D, Number::One);

        cout << g;

        while(!rules.roundOver(g)){
            string cardSelection;
            Player p = rules.getNextPlayer(g);
            string currentPlayer = p.getName();
            cout << "It is now " << currentPlayer << "'s turn." << endl;
            cout << "Please select a card.";
            cin >> cardSelection;
            Letter lSelected = static_cast<Letter>(static_cast<int>(cardSelection[0]));
            Number nSelected = static_cast<Number>(static_cast<int>(cardSelection[1]));
            b.turnFaceUp(lSelected, nSelected);
            cout << g;
            if(!rules.isValid(g)){
                cout << currentPlayer << " is now eliminated from this round." << endl;
                p.setActive(false);
            }
            cout << g;
        }
        Player p = rules.getNextPlayer(g);
        p.addReward(*(d.getNext()));
	}
	Player p = rules.getNextPlayer(g);
	p.setDisplayMode(true);
	for(int i = 0; i < 4; i ++){
        cout << g.getPlayer(static_cast<Side>(i));
	}
	return 0;
}
