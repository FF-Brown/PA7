/*
	Author: Nathan Brown
	Created: 11/13/2019
	Description: A severely limited version of five-card draw poker. Includes no betting and a somewhat short list of winning hand combinations. Also, only allows for one player versus the dealer (computer). Despite these restrictions, has essentially the same gameplay as a typical round of five-card draw.
*/

// Authors: Deitel & Deitel - C How to Program

#include "poker.h"


int main(void)
{
	Hand player_hand, dealer_hand, buffer1, buffer2;
	init_hand(&player_hand);
	init_hand(&dealer_hand);
	init_hand(&buffer1);
	init_hand(&buffer2);
	int discard_list[5] = { 0 };

	/* initialize suit array */
	const char* suit[4] = { "Hearts", "Diamonds", "Clubs", "Spades" };

	/* initialize denomination array */
	const char* denomination[13] = { "Ace", "Deuce", "Three", "Four", "Five", "Six", "Seven", "Eight",
		"Nine", "Ten", "Jack", "Queen", "King" };

	/* initalize deck array */
	int deck[4][13] = { 0 };

	srand((unsigned)time(NULL)); /* seed random-number generator */

	shuffle(deck);
	deal(deck, denomination, suit, &player_hand);
	deal(deck, denomination, suit, &dealer_hand);

	printf("~~WELCOME TO POKER~~\n");
	display_menu();
	display_hand(player_hand, suit, denomination);
	redraw(discard_list);

	return 0;
}

