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

void shuffle(int wDeck[][13]);
void deal(const int wDeck[][13], const char* wdenomination[], const char* wSuit[], Hand* hand);
void init_hand(Hand* hand);