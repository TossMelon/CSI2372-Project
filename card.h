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
enum FaceAnimal{
	Crab, Penguin, Octopus, Turtle, Walrus
};
enum FaceBackground{
	Red, Green, Purple, Blue, Yellow
};
class Card
{
	FaceAnimal face;
	FaceBackground colour;
	
	private:
		Card(FaceAnimal, FaceBackground); //Card constructor
	public:
		string row(int);
		void print();
		
		
};

#endif
