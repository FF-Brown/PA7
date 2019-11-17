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
	int denominations_player[13] = { 0 };
	int denominations_dealer[13] = { 0 };
	int suits_player[4] = { 0 };
	int suits_dealer[4] = { 0 };
	short score_player = 0, score_dealer = 0;
	short i = 0, round = 1;

	/* initialize suit array */
	const char* suit[4] = { "Hearts", "Diamonds", "Clubs", "Spades" };

	/* initialize denomination array */
	const char* denomination[13] = { "Ace", "Deuce", "Three", "Four", "Five", "Six", "Seven", "Eight",
		"Nine", "Ten", "Jack", "Queen", "King" };

	/* initalize deck array */
	int deck[4][13] = { 0 };

begin:
	//Reset for consecutive rounds
	for (i = 0; i < 5; i++) discard_list[i] = 0; 
	for (i = 0; i < 13; i++) denominations_player[i] = 0;
	for (i = 0; i < 13; i++) denominations_dealer[i] = 0;
	for (i = 0; i < 4; i++) suits_player[i] = 0;
	for (i = 0; i < 4; i++) suits_dealer[i] = 0;
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

	if (round == 1) printf("~~WELCOME TO POKER~~\n");
	else printf("~~ROUND %d OF POKER~~\n", round);
	display_menu();
	display_hand(player_hand, suit, denomination);
	//Allow player to choose which cards to discard
	get_redraw(discard_list);
	printf("Discard list: %d %d %d %d %d\n", discard_list[0], discard_list[1], discard_list[2], discard_list[3], discard_list[4]);
	//Replace specified cards in player hand
	redraw(discard_list, &player_hand, buffer1);
	display_hand(player_hand, suit, denomination);
	precheck_hand(player_hand, denominations_player, suits_player);
	printf("Denominations: ");
	for (i = 0; i < 13; i++) printf("%d ", denominations_player[i]);
	printf("Suits: ");
	for (i = 0; i < 4; i++) printf("%d ", suits_player[i]);
	score_player = check_master(denominations_player, suits_player);
	printf("You scored %d\n", score_player);


	//GAME OVER~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	//Play again if desired
	cont = cont_playing();
	++round;
	if (cont == 'y') goto begin;
	else printf("See you next time!\n");

	return 0;
}

