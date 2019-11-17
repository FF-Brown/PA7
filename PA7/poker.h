/*
	Author: Nathan Brown
	Created: 11/13/2019
	Description: A severely limited version of five-card draw poker. Includes no betting and a somewhat short list of winning hand combinations. Also, only allows for one player versus the dealer (computer). Despite these restrictions, has essentially the same gameplay as a typical round of five-card draw.
*/

#ifndef POKER_H
#define POKER_H
#define _CRT_SECURE_NO_WARNINGS
#define FOUR_OF_A_KIND 6
#define FLUSH 5
#define STRAIGHT 4
#define THREE_OF_A_KIND 3
#define TWO_PAIR 2
#define PAIR 1

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
void deal(const int wDeck[][13], const char* wDenomination[], const char* wSuit[], Hand* player_hand, Hand* dealer_hand, Hand* buffer1, Hand* buffer2);
/*
	Function: init_hand()
	Date Created: 11/13/2019
	Description: Sets suit and denomination for all cards in hand equal to 0
	Preconditions: Hand struct exists
	Postconditions: Card array in hand initialized.
*/
void init_hand(Hand* hand);
void display_hand(Hand hand, const char* wSuit[], const char* wDenomination[]);
void get_redraw(int discard_list[]);
void redraw(int discard_list[], Hand* hand, Hand buffer);
char cont_playing(void);
void init_deck(int deck[][13]);
void precheck_hand(Hand hand, int denominations[], int suits[]);
int check_four(int denominations[]);
int check_flush(int suits[]);
int check_straight(int denominations[]);
int check_three(int denominations[]);
int check_twoPair(int denominations[]);
int check_pair(int denominations[]);
short check_master(int denominations[], int suits[]);
void close2four(Hand hand, int denominations[], int discard_list[]);
void close2flush(Hand hand, int suits[], int discard_list[]);
void close2straight(Hand hand, int denominations[], int discard_list[]);
void close2three(Hand hand, int denominations[], int discard_list[]);
void close_enough(Hand hand, int denominations[], int suits[], int discard_list[]);

#endif // !POKER_H
