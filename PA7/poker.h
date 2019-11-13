/*
	Author: Nathan Brown
	Created: 11/13/2019
	Description: A severely limited version of five-card draw poker. Includes no betting and a somewhat short list of winning hand combinations. Also, only allows for one player versus the dealer (computer). Despite these restrictions, has essentially the same gameplay as a typical round of five-card draw.
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
	int suit;
	int denomination;
*/
typedef struct card {
	int suit;
	int denomination;
}Card;
/*
	Card cards[5];
*/
typedef struct hand {
	Card cards[5];
}Hand;

/*
	Function: display_menu()
	Date Created: 10/26/2019
	Description: Allows user to choose between displaying rules, playing the game, and exiting. New and improved version with a do-while loop.
	Preconditions: None
	Postconditions: Loops back into menu if rules chosen. Breaks loop if --> game. Ends program if exit.
*/
void display_menu(void);
/*
	Function: rules()
	Date Created: 10/26/2019
	Description: Displays rules of five-card draw poker
	Preconditions: Menu displayed
	Postconditions: Rules displayed
*/
void rules(void);
void shuffle(int wDeck[][13]);
void deal(const int wDeck[][13], const char* wdenomination[], const char* wSuit[], Hand* hand);
/*
	Function: init_hand()
	Date Created: 11/13/2019
	Description: Sets suit and denomination for all cards in hand equal to 0
	Preconditions: Hand struct exists
	Postconditions: Card array in hand initialized.
*/
void init_hand(Hand* hand);
void display_hand(Hand hand, const char* wSuit[], const char* wDenomination[]);
void redraw(int discard_list[]);