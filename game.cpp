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
#include "game.h"

using std::endl;
using std::ostream;


//Game constructor
Game::Game() {
	round = 0;
	playerArray = new Player[4]{Player(""), Player(""), Player(""), Player("")};
	cDeck->make_CardDeck();
}

//Return number [0 - 6] corresponding to current round of game
int Game::getRound() {
	return round;
}

//adds or updates a player. If Player is already in Game, the player is updated, and if not it is added. 
void nextRound(){
	
}

//Add Player to current game
void Game::addPlayer(const Player& p) {
	bool exists = true;
	
	for(int i = 0; i < numPlayers; i++){
		if(p.getName() == playerArray[i].getName()){ //updated player
			playerArray[i] = p;
		}
		if(i == 3 && p.getName() != playerArray[i].getName()){
			exists = false;
		}
	}
	if(numPlayers < 3 && !exists){
		playerArray[numPlayers] = p;
	}
}

//Return player
Player& Game::getPlayer(Side side) { //side input is for NEXT player
	for(int i = 0; i < 4; i++){
		if(playerArray[i].getSide() == side){
			return playerArray[i];
		}
	}
}

//Return previous card selected
const Card* Game::getPreviousCard() {//how the fuck do i do this??????
	
}

//Return current card selected
const Card* Game::getCurrentCard() {
}

//Sets current card to passed argument (Card*)
void Game::setCurrentCard(const Card*) {
	
}

//Overload stream insertion operator
//Displays Game (board and all players)
ostream &operator << (ostream &out, const Game &g) {
	out << "Players, etc."<<endl;
	return out;
}
