/*
	CSI 2372 Project
	Memory Card Game - Memoarrr!

	Group 36
	Member 1: Huong Pham
	Student Number: 7831858

	Member 2: Matthew Choi
	Student Number: 8250803
*/
//#define TEST_GAME


#include <iostream>
#include <sstream>
#include "game.h"

using std::endl;
using std::ostream;


//Game constructor
Game::Game():cPrev(nullptr), cCurrent(nullptr), round(0), expertDisplay(false){
	playerArray = new Player[4]{Player(""), Player(""), Player(""), Player("")};
}

//Return number [0 - 6] corresponding to current round of game
int Game::getRound() const{
	return round;
}

//adds or updates a player. If Player is already in Game, the player is updated, and if not it is added.
void Game::nextRound(){
    round++;
    for(int i = 0; i < 5; i ++){
        for(int j = 0; j < 5; j++){
            b.turnFaceDown(static_cast<Letter>(i), static_cast<Number>(j));
        }
    }
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
Player& Game::getPlayer(Side side) const{ //side input is for NEXT player
	for(int i = 0; i < 4; i++){
		if(playerArray[i].getSide() == side){
			return playerArray[i];
		}
	}
}

//Return previous card selected
Card* Game::getPreviousCard() const{
    return cPrev;

}

//Return current card selected
Card* Game::getCurrentCard() const{
    return cCurrent;
}

//Sets current card to passed argument (Card*)
void Game::setCurrentCard(Card* c){
    cCurrent = c;
}
Card* Game::getCard(const Letter& letter, const Number& number){
    b.getCard(letter, number);
}
void Game::setCard(const Letter& letter, const Number& number, Card* c){
    b.setCard(letter, number, c);
}

//Overload stream insertion operator
//Displays Game (board and all players)
ostream &operator << (ostream &out, const Game &g) {
    if(!g.expertDisplay){ //regular display
        out << g.b << endl;
    }
    else{ //expert display
        for(int i = 0; i < 5; i++){
            std::stringstream ss2, ss1, ss0;
            for(int j = 0; j < 5; j++){
                //if(g.b.isFaceUp(static_cast<Letter>(i), static_cast<Number>(j))){

                //}
            }
        }
    }
	for(int i = 0; i < g.numPlayers; i ++){
        out << (g.getPlayer(static_cast<Side>(i))).getName() << endl;
	}
	return out;
}

#ifdef TEST_GAME
int main(){
    Game g;
    cout << "Testing game class." << endl;
    cout << "Testing getRound. # of rounds: " << g.getRound() << endl;
    g.nextRound();
    cout << "Testing nextRound. # of rounds: " << g.getRound() << endl;
    Player p("Jo");
    g.addPlayer(p);
    cout << "Testing addPlayer and getPlayer: " << g.getPlayer(Side::Bottom) << endl;
    cout << "Testing getPreviousCard : " << g.getPreviousCard() << endl;
    cout << "Testing getCurrentCard: " << g.getCurrentCard() << endl;
    g.setCurrentCard(g.getCard(Letter::B, Number::Three));
    cout << "Testing setCurrentCard and getCard: " << g.getCurrentCard() << endl;
    g.setCard(Letter::A, Number::Three, g.getCard(Letter::B, Number::Three));
    cout << "Testing setCard: " << g.getCard(Letter::A, Number::Three) << endl;

}
#endif // TEST_GAME
