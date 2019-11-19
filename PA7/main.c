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
	const char* winning_hands[7] = {"Garbage hand", "Pair", "Two pair", "Three of a kind", "Straight", "Flush", "Four of a kind" };

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

	//Shuffle and deal cards
	shuffle(deck);
	deal(deck, denomination, suit, &player_hand, &dealer_hand, &buffer1, &buffer2);

	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	if (round == 1) printf("~~WELCOME TO POKER~~\n");
	else printf("~~ROUND %d OF POKER~~\n", round);
	display_menu();
	printf("Cards have been dealt. Dealer's hand is facedown.\n");
	display_hand(player_hand, suit, denomination);

	//Allow player to choose which cards to discard
	get_redraw(discard_list);

	//Replace specified cards in player hand
	redraw(discard_list, &player_hand, buffer1);
	display_hand(player_hand, suit, denomination);

	//Sort hand into parallel arrays by denomination and suit
	precheck_hand(player_hand, denominations_player, suits_player);

	//Score hand
	score_player = check_master(denominations_player, suits_player);
	//Report score
	printf("You scored %d\n", score_player);

	//Fill parallel arrays
	precheck_hand(dealer_hand, denominations_dealer, suits_dealer);
	//Have dealer assign discard_list
	close_enough(dealer_hand, denominations_dealer, suits_dealer, discard_list); 
	redraw(discard_list, &dealer_hand, buffer2);
	//Reset parallel arrays
	for (i = 0; i < 12; i++) denominations_dealer[i] = 0;
	for (i = 0; i < 4; i++) suits_dealer[i] = 0;
	//Refill parallel arrays
	precheck_hand(dealer_hand, denominations_dealer, suits_dealer);
	//Calculate dealer score
	score_dealer = check_master(denominations_dealer, suits_dealer);

	score_compare(score_player, score_dealer, winning_hands);


	//GAME OVER~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	//Play again if desired
	cont = cont_playing();
	++round;
	if (cont == 'y') goto begin;
	else printf("See you next time!\n");

	return 0;
}

