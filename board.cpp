/*
	CSI 2372 Project
	Memory Card Game - Memoarrr!

	Group 36
	Member 1: Huong Pham
	Student Number: 7831858

	Member 2: Matthew Choi
	Student Number: 8250803
*/

//#define TEST_BOARD

#include <exception>
#include <iostream>
#include <sstream>
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
Board::Board() : strArray(new string*[5]) {
    cDeck->make_CardDeck();
	for(int i = 0; i < 5; i++){
		strArray[i] = new string[5];
		for(int j = 0; j < 5; j++){
            cArray[j][i] = *(cDeck->getNext());
		}
	}
	for(int i = 0; i < 5; i++){ //initializes every element to nothing
		for(int j = 0; j < 5; j++){
			strArray[i][j] = "zzz\nzzz\nzzz\n";//zzz zzz zzz
		}
	}
}

//Returns true if the card at a given position is face up
//Throws an exception of type OutOfRange if an invalid Letter and Number combination was given
bool Board::isFaceUp(const Letter& letter, const Number& number) {
	try{
		if(strArray[static_cast<int>(letter)][static_cast<int>(number)] == "zzz\nzzz\nzzz\n"){
			return true;
		}
		return false;
	}
	catch(OutOfRange e){
		std::cout << e.what() << static_cast<int>(letter) << " " << static_cast<int>(number) << endl;
	}
}

//Changes state of the specified card to face up, return true
//If card was already face up, return false
//Throw OutOfRange exception if invalid Letter and Number combination was given
bool Board::turnFaceUp(const Letter& letter, const Number& number) {
	try{
		if(!isFaceUp(letter, number)) {//if card is face down
            string s;
            FaceAnimal face;  //convert cards to faceanimal and facebackground
            face = *(cArray[(static_cast<int>(letter)), (static_cast<int>(number))]);
            FaceBackground background;
            background = *(cArray[(static_cast<int>(letter)), (static_cast<int>(number))]);
            for(int i = 0; i < 11; i++){ //construct card rows
                if(i == 3 || i == 7){
                    s.append("\n");
                }
                if(i == 5){//middle face
                   s.append(faceAnimal[static_cast<int>(face)]);
                }
                s.append(faceBackground[static_cast<int>(background)]);
            }
            s.append("\n");
            strArray[static_cast<int>(letter)][static_cast<int>(number)]= s;
			return true;
		}
		return false;
	}
	catch(OutOfRange e){
		std::cout << e.what() << static_cast<int>(letter) << " " << static_cast<int>(number) << endl;
	}

}

//Changes state of the specified card to face down, return true
//If card was already face down, return false
//Throw OutOfRange exception if invalid Letter and Number combination was given
bool Board::turnFaceDown(const Letter& letter, const Number& number) {
    try{
        if(isFaceUp(letter, number)) {
            strArray[static_cast<int>(letter)][static_cast<int>(number)] = "zzz\nzzz\nzzz\n";
            return true;
        }
        return false;
    }
	catch(OutOfRange e){
        std::cout << e.what() << static_cast<int>(letter) << " " << static_cast<int>(number) << endl;
	}
}
Card* Board::getCard(const Letter& letter, const Number& number){
	try{
		Card* cPtr;
		cPtr = cArray[(static_cast<int>(letter)), (static_cast<int>(number))];
		return cPtr;
	}
	catch(OutOfRange e){
        std::cout << e.what() << static_cast<int>(letter) << " " << static_cast<int>(number) << endl;
	}
}
void Board::setCard(const Letter& letter, const Number& number, Card* card){
	try{
		//set the card pointer in the card deck object to whatever he wants to ????
		cArray[(static_cast<int>(letter)), (static_cast<int>(number))] = card;

	}
	catch(OutOfRange e){
        std::cout << e.what() << static_cast<int>(letter) << " " << static_cast<int>(number) << endl;
	}
}

//Changes the state of all cards to be face down
void Board::reset() {
    for(int i = 0; i < 5; i ++){
        for(int j = 0; i < 5; j++){
            if(isFaceUp(static_cast<Letter>(i), static_cast<Number>(j))){
                turnFaceDown(static_cast<Letter>(i), static_cast<Number>(j));
            }
        }
    }
}

//Overload stream insertion operator
//Displays board
ostream &operator<<(ostream &out, const Board &b) {
	for(int i = 0; i < 5; i ++){
        stringstream ss0, ss1, ss2;
        string s;
        for(int j = 0; j < 5; j++){
                                                                //01234
            ss0 << (b.strArray[i,j]->substr(0,4)) << " ";       //zzz\n
            ss1 << (b.strArray[i,j]->substr(4, 4)) << " ";      //zzz\n
            ss2 << (b.strArray[i,j]->substr(8,4)) << " ";       //zzz\n
            if(j==4){
                ss0 << "\n";
                ss1 << "\n";
                ss2 << "\n";
            }
        }
        ss0 >> s; //construct row i
        ss1 >> s;
        ss2 >> s;
        s.append("\n");
        out << s;
	}
	return out;
}

#ifdef TEST_BOARD
int main(){
    cout << "Testing board class." << endl;
    Board b;
    cout << "isFaceUp testing: " << b.isFaceUp(Letter::A, Number::One) << endl;
    cout << "isFaceUp testing exception: " << b.isFaceUp(static_cast<Letter>(6), static_cast<Number>(6)) << endl;
    cout << b;

    cout << "turnFaceUp testing: " << b.turnFaceUp(Letter::A, Number::One) << endl;
    cout << "turnFaceUp testing exception: " << b.turnFaceUp(static_cast<Letter>(6), static_cast<Number>(6)) << endl;
    cout << b;

    cout << "turnFaceDown testing: " << b.turnFaceDown(Letter::A, Number::One) << endl;
    cout << "turnFaceDown testing exception: " << b.turnFaceDown(static_cast<Letter>(6), static_cast<Number>(6)) << endl;
    cout << b;

    Card* c = b.getCard(Letter::A, Number::One);
    cout << "getCard testing: " << c << endl;
    c = b.getCard(static_cast<Letter>(6), static_cast<Number>(6));
    cout << "getCard testing exception: " << c << endl;

    c = b.getCard(Letter::A, Number::One);
    b.setCard(Letter::A, Number::One, c);
    cout << "setCard testing: " << c << endl;
    b.setCard(static_cast<Letter>(6), static_cast<Number>(6), c);
    cout << "setCard testing exception: " << c << endl;

    b.reset();
    cout << b;


}
#endif // TEST_BOARD
