/*
	Author: Nathan Brown
	Created: 11/13/2019
	Description: A severely limited version of five-card draw poker. Includes no betting and a somewhat short list of winning hand combinations. Also, only allows for one player versus the dealer (computer). Despite these restrictions, has essentially the same gameplay as a typical round of five-card draw.
*/

#include "poker.h"

/* shuffle cards in deck */

void shuffle(int wDeck[][13])
{
	int row = 0;    /* row number */
	int column = 0; /*column number */
	int card = 0;   /* card counter */

	/* for each of the 52 cards, choose slot of deck randomly */
	for (card = 1; card <= 52; card++)
	{
		/* choose new random location until unoccupied slot found */
		do
		{
			row = rand() % 4;
			column = rand() % 13;
		} while (wDeck[row][column] != 0);

		/* place card number in chosen slot of deck */
		wDeck[row][column] = card;
	}
}

/* deal cards in deck */
void deal(const int wDeck[][13], const char* wDenomination[], const char* wSuit[], Hand* hand)
{
	int row = 0;    /* row number */
	int column = 0; /*column number */
	int card = 0;   /* card counter */

	/* deal each of the 52 cards */
	for (card = 1; card <= 5; card++)
	{
		/* loop through rows of wDeck */
		for (row = 0; row <= 3; row++)
		{
			/* loop through columns of wDeck for current row */
			for (column = 0; column <= 12; column++)
			{
				/* if slot contains current card, display card */
				if (wDeck[row][column] == card)
				{
					//printf("%5s of %-8s%c", wDenomination[column], wSuit[row], card % 2 == 0 ? '\n' : '\t');
					hand->cards[card - 1].denomination = column;
					hand->cards[card - 1].suit = row;
					//printf("%5s of %-8s%c", wDenomination[hand->cards[card - 1].denomination], wSuit[hand->cards[card - 1].suit], card % 2 == 0 ? '\n' : '\t');
				}
			}
		}
	}
}
void init_hand(Hand* hand)
{
	for (int i = 0; i < 5; i++) {
		hand->cards[i].denomination = 0;
	}
	for (int i = 0; i < 5; i++) {
		hand->cards[i].suit = 0;
	}

}