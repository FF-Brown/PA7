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
	int discard_list[5] = { 0, 0, 0, 0, 0 };
	char cont = '\0';
	int player_denominations[14] = { 0 };
	int player_suits[5] = { 0 };
	int dealer_denominations[14] = { 0 };
	int dealer_suits[5] = { 0 };

	/* initialize suit array */
	const char* suit[4] = { "Hearts", "Diamonds", "Clubs", "Spades" };

	/* initialize denomination array */
	const char* denomination[13] = { "Ace", "Deuce", "Three", "Four", "Five", "Six", "Seven", "Eight",
		"Nine", "Ten", "Jack", "Queen", "King" };

	/* initalize deck array */
	int deck[4][13] = { 0 };

begin:
	init_deck(deck);
	srand((unsigned)time(NULL)); /* seed random-number generator */

	shuffle(deck);
	deal(deck, denomination, suit, &player_hand, &dealer_hand, &buffer1, &buffer2);
	/*Testing Purposes
	for (int i = 0; i < 5; i++) {
		printf("%s of %s\n", denomination[player_hand.cards[i].denomination], suit[player_hand.cards[i].suit]);
	}
	for (int i = 0; i < 5; i++) {
		printf("%s of %s\n", denomination[dealer_hand.cards[i].denomination], suit[dealer_hand.cards[i].suit]);
	}
	for (int i = 0; i < 5; i++) {
		printf("%s of %s\n", denomination[buffer1.cards[i].denomination], suit[buffer1.cards[i].suit]);
	}
	for (int i = 0; i < 5; i++) {
		printf("%s of %s\n", denomination[buffer2.cards[i].denomination], suit[buffer2.cards[i].suit]);
	}
	*/

	printf("~~WELCOME TO POKER~~\n");
	display_menu();
	display_hand(player_hand, suit, denomination);
	//Allow player to choose which cards to discard
	get_redraw(discard_list);
	printf("Discard list: %d %d %d %d %d\n", discard_list[0], discard_list[1], discard_list[2], discard_list[3], discard_list[4]);
	//Replace specified cards in player hand
	redraw(discard_list, &player_hand, buffer1);
	display_hand(player_hand, suit, denomination);

	//Play again if desired
	cont = cont_playing();
	if (cont == 'y') goto begin;
	else printf("See you next time!\n");

	return 0;
}

