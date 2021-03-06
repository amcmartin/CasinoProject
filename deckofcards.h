// OOP Final project AJ McMartin Nick Ferrara
#pragma once
#include <iostream>
#include <string>
using namespace std;

class Card{
private:
	//AJ
	int value; //value of the card face cards worth 10 aces 1 or 11
	char suit;	//suits represented by a single character
	int cardtype; //defined so that when itterating through base pointers program can tell what class its from 

public:
	// constructor to initalize non picture cards 
	Card(int value, char suit){
		//AJ
		this->value = value;
		this->suit = suit;
		this->cardtype = 0; // notmal cards are card type 0
	}
	// Get functions
	int Getvalue(){
		//AJ
		return(value);
	}
	char Getsuit(){
		//AJ
		return(suit);
	}
	int Getcardtype(){
		//AJ
		return(cardtype);
	}
	virtual char Getsymbol(){return 'n';} //AJ // does nothing for card but lets program know it exists
	// set functions
	void Setvalue(int value){
		//AJ
		this->value = value;
	}
	void Setsuit(char suit){
		//AJ
		this->suit = suit; 
	}
	void Setcardtype(int num){
		//AJ
		this->cardtype = num; // used to change the type of card (Face or normal)
	}
	//Print functions
	virtual void printValue(){
		
		std::cout << value; //prints the value of the card 
	}
	virtual void Print(){//Print function not used in final implementation but is useful for prototypes
		//AJ
		cout << value << suit; // print card details both the value and the suit like 4D
	}
	~Card(){};
	
};

class FaceCard : public Card{
private:
	//AJ
	char symbol; //symbol of face card like A K Q J

public:
	// constuctor to intialize face cards
	FaceCard(char symbol, char suit):Card(10,suit){ // initilizes value to 10 but will be changed if Ace
		//AJ
		if (symbol == 'A'){ 						// if card is Ace then initializes value as 11
			Setvalue(11);
		}
		this->symbol = symbol;
		Setcardtype(1); 							// face cards are card type 1

	}
	//nick
	void printValue(){									//prints the symbol on the card
			if(symbol == 'A'){
				std::cout << symbol;
			}else{
				std::cout << symbol << " ";
			}
		}
	char Getsymbol(){
		//AJ
		return(symbol);
	}
	void Print(){//Print function not used in final implementation but is useful for prototypes
		// AJ
		cout << symbol << Getsuit(); //prints face card like QH (Queen of hearts)
	}
	~FaceCard(){};
};


