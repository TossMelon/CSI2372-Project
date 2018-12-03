/* 
	CSI 2372 Project
	Memory Card Game - Memoarrr!
	
	Group 36
	Member 1: Huong Pham
	Student Number: 7831858
	
	Member 2: Matthew Choi
	Student Number: 8250803
*/


#include <exception>
#include <iostream>
#include "board.h"

using namespace std;
using std::endl;
using std::ostream;

class Card;


struct OutOfRange : public exception {
	const char* what() const throw(){
		return "Out of range exception";
	}
};

//Board constructor
Board::Board() { 
	strArray = new string*[5];
	cDeck->make_CardDeck();
	for(int i = 0; i < 5; i++){
		strArray[i] = new string[5];
	}
	for(int i = 0; i < 5; i++){ //initializes every element to nothing
		for(int j = 0; j < 5; j++){
			strArray[i][j] = "zzz zzz zzz";
		}
	}
}

//Returns true if the card at a given position is face up
//Throws an exception of type OutOfRange if an invalid Letter and Number combination was given
bool Board::isFaceUp(const Letter& letter, const Number& number) {
	try{
		if(strArray[letter][number] == "z"){
			return true;
		}
		return false;
	}
	catch(OutOfRange e){
		std::cout << e.what() << letter << " " << number << endl;
	}
}
	
//Changes state of the specified card to face up, return true
//If card was already face up, return false
//Throw OutOfRange exception if invalid Letter and Number combination was given
bool Board::turnFaceUp(const Letter& letter, const Number& number) {
	try{
		if(!isFaceUp(letter, number)) {
			Card* f = getCard(letter, number);
			//strArray[letter, number] = //set the string in the array to the face up card ie. "bbb bpb bbb"
			return true;
		}
		return false;
	}
	catch(OutOfRange e){
		std::cout << e.what() << letter << " " << number << endl;
	}

}

//Changes state of the specified card to face down, return true
//If card was already face down, return false
//Throw OutOfRange exception if invalid Letter and Number combination was given
bool Board::turnFaceDown(const Letter& letter, const Number& number) {
	/*if(isFaceUp(a, b)) {
		//set the string in the array to "zzz zzz zzz"
		return true;
	}*/
	return false;
}
Card* Board::getCard(const Letter& letter, const Number& number){
	try{
		Card* cPtr = new Card(Crab, Red);
		cPtr = cDeck;
		for(int i = 0; i < letter*number; i++){//return the card pointer found by looking throught the card deck object
			cPtr = cPtr->getNext();
		}
		return cPtr;
	}
	catch(OutOfRange e){
		
	}
}
void Board::setCard(const Letter& letter, const Number& number, Card* card){
	try{
		//set the card pointer in the card deck object to whatever he wants to ????
		Card* cPtr = cDeck;
		for(int i = 0; i < letter*number; i++){
			cPtr = cPtr->getNext();
		}
		cPtr = card;
	}
	catch(OutOfRange e){
		
	}
}

//Changes the state of all cards to be face down
void Board::reset() {
	/*if( isFaceUp(a, b)) {
		turnFaceDown(a, b);
	}*/
}

//Overload stream insertion operator
//Displays board
ostream &operator<<(ostream &out, const Board &b) {
	out <<b<<endl;
	return out;
}
