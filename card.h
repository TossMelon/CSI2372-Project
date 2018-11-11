/* 
	CSI 2372 Project
	Memory Card Game - Memoarrr!
	
	Group 36
	Member 1: Huong Pham
	Student Number: 7831858
	
	Member 2: Matthew Choi
	Student Number: 8250803
*/

#ifndef CARD_H
#define CARD_H

class Card
{
	char face, colour;
	
	private:
		Card(char faceIn, char colourIn); //Card constructor
	public:
		print(); //Print Card
};

#endif
