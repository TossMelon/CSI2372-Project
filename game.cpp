/* 
	CSI 2372 Project
	Memory Card Game - Memoarrr!
	
	Group 36
	Member 1: Huong Pham
	Student Number: 7831858
	
	Member 2: Matthew Choi
	Student Number: 8250803
*/

#include "game.h"

#include <iostream>

using std::endl;
using std::ostream;

//Game constructor
Game::Game() {
	round = 0;
}

//Return number [0 - 6] corresponding to current round of game
int Game::getRound() {
	return round;
}

//Add Player to current game
void Game::addPlayer(const Player&) {
	
}

//Return player
Player& Game::getNextPlayer() {
	
}

//Return previous card selected
const Card* Game::getPreviousCard() {
	
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
