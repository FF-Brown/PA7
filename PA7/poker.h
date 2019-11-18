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
/*
shuffle cards in deck (starting code)
*/
void shuffle(int wDeck[][13]);
/*
deal cards in deck (starting code)
*/
void deal(const int wDeck[][13], const char* wDenomination[], const char* wSuit[], Hand* player_hand, Hand* dealer_hand, Hand* buffer1, Hand* buffer2);
/*
	Function: init_hand()
	Date Created: 11/13/2019
	Description: Sets suit and denomination for all cards in hand equal to 0
	Preconditions: Hand struct exists
	Postconditions: Card array in hand initialized.
*/
void init_hand(Hand* hand);
/*
	Function: display_hand()
	Date Created:
	Description: Prints the player's current hand to the screen
	Preconditions: Cards have been dealt
	Postconditions: Hand printed to screen
*/
void display_hand(Hand hand, const char* wSuit[], const char* wDenomination[]);
/*
	Function: get_redraw()
	Date Created:
	Description: Asks user which cards they want to discard. Creates an array of input. Translates that array into discard_list[]
	Preconditions: Player hand has been displayed.
	Postconditions: discard_list[] filled
*/
void get_redraw(int discard_list[]);
/*
	Function: redraw()
	Date Created:
	Description: Uses discard_list[] to take cards from the buffer hand and put them into the player's hand
	Preconditions: Player has chosen which cards to discard
	Postconditions: Player has new cards in their hand
*/
void redraw(int discard_list[], Hand* hand, Hand buffer);
/*
	Function: cont_playing()
	Date Created:
	Description: Gives player the option to play again. New and improved version with a do-while loop (as it should be)
	Preconditions: Game over
	Postconditions: Returns player decision
*/
char cont_playing(void);
/*
	Function: init_deck()
	Date Created:
	Description: Resets deck for a new round
	Preconditions: Beginning of round
	Postconditions: Deck reset to 0's
*/
void init_deck(int deck[][13]);
/*
	Function: precheck_hand()
	Date Created:
	Description: Sorts cards from hand into counting arrays by denomination and suit for scoring
	Preconditions: Ready to score
	Postconditions: denominations[] and suits[] arrays formed
*/
void precheck_hand(Hand hand, int denominations[], int suits[]);
/*
	Function: check_four()
	Date Created:
	Description: Checks to see if player has a four-of-a-kind, returns 1/0 (T/F)
	Preconditions: Player has drawn any new cards and precheck_hand() has run
	Postconditions: Outcome returned
*/
int check_four(int denominations[]);
/*
	Function: check_flush()
	Date Created:
	Description: Checks if player has a flush
	Preconditions: precheck_hand() has run
	Postconditions: Result (1/0) returned
*/
int check_flush(int suits[]);
/*
	Function: check_straight()
	Date Created:
	Description: Checks if player has a straight
	Preconditions: precheck_hand() has run
	Postconditions: Returns 1/0
*/
int check_straight(int denominations[]);
/*
	Function: check_three()
	Date Created:
	Description: Checks if player has a three-of-a-kind
	Preconditions: precheck_hand() has run
	Postconditions: Returns 1/0
*/
int check_three(int denominations[]);
/*
	Function: check_twoPair()
	Date Created:
	Description: Checks if player has two pairs
	Preconditions: precheck_hand() has run
	Postconditions: Returns 1/0
*/
int check_twoPair(int denominations[]);
/*
	Function: check_pair()
	Date Created:
	Description: Checks if the player has a pair
	Preconditions: precheck_hand() has run
	Postconditions: Returns 1/0
*/
int check_pair(int denominations[]);
/*
	Function: check_master()
	Date Created:
	Description: Runs all other score checking functions in order. Breaks when one is true.
	Preconditions: precheck_hand() has run
	Postconditions: Returns score
*/
short check_master(int denominations[], int suits[]);
/*
	Function: close2four()
	Date Created: 11/17/2019
	Description: Checks to see if player has 3 of a kind. Assigns discard_list[] if so
	Preconditions: precheck_hand() run
	Postconditions: Returns 1/0
*/
short close2four(Hand hand, int denominations[], int discard_list[]);
/*
	Function: close2flush()
	Date Created: 11/17/2019
	Description: Checks to see if player is close to having a flush. Assigns discard_list[] if so
	Preconditions: precheck_hand() run
	Postconditions: Returns 1/0
*/
short close2flush(Hand hand, int suits[], int discard_list[]);
/*
	Function: close2straight()
	Date Created: 11/17/2019
	Description: Checks to see if player nearly has a straight. Assigns discard_list[] if so.
	Preconditions: precheck_hand() run
	Postconditions: Returns 1/0
*/
short close2straight(Hand hand, int denominations[], int discard_list[]);
/*
	Function: close2three()
	Date Created: 11/17/2019
	Description: Checks to see if player nearly has a three of a kind. Assigns discard_list[] if so.
	Preconditions: precheck_hand() run
	Postconditions: Returns 1/0
*/
short close2three(Hand hand, int denominations[], int discard_list[]);
/*
	Function: close_enough()
	Date Created: 11/17/2019
	Description: Runs all close2 functions.
	Preconditions: precheck_hand() run
	Postconditions: Returns successful or not
*/
short close_enough(Hand hand, int denominations[], int suits[], int discard_list[]);

#endif // !POKER_H
