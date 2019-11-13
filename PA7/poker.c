/*
	Author: Nathan Brown
	Created: 11/13/2019
	Description: A severely limited version of five-card draw poker. Includes no betting and a somewhat short list of winning hand combinations. Also, only allows for one player versus the dealer (computer). Despite these restrictions, has essentially the same gameplay as a typical round of five-card draw.
*/

#include "poker.h"

/*
	Function: display_menu()
	Date Created: 10/26/2019
	Description: Allows user to choose between displaying rules, playing the game, and exiting. New and improved version with a do-while loop.
	Preconditions: None
	Postconditions: Loops back into menu if rules chosen. Breaks loop if --> game. Ends program if exit.
*/
void display_menu(void)
{
	int option = 0;

	//Display menu until receiving valid input

	do {
		printf("\n~~~~~~ MAIN MENU ~~~~~~\n\n");
		printf("1. Rules\n");
		printf("2. Play Game\n");
		printf("3. Exit\n");
		printf("Select an option by typing in a number.\n");
		scanf("%d", &option);

		//Run process based on input
		switch (option) {
		case 1: //RULES
			system("cls");
			rules();
			display_menu();
			break;
			//Leave switch and while loop to begin playing game
		case 2: //PLAY
			system("cls");
			printf("Good luck!\n\n");
			break;
			//Exit program
		case 3: //EXIT
			printf("See you next time!\n");
			exit(0);
			break;
		default:
			break;
		}
		if (option < 1 || option > 3)
			printf("Invalid entry.\n");
	} while (option < 1 || option > 3);
}
/*
	Function: rules()
	Date Created: 10/26/2019
	Description: Displays rules of five-card draw poker
	Preconditions: Menu displayed
	Postconditions: Rules displayed
*/
void rules(void)
{
	printf("Typical rules of five-card draw.\n");
}
/* shuffle cards in deck (starting code)*/
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
/* deal cards in deck (starting code)*/
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
/*
	Function: init_hand()
	Date Created: 11/13/2019
	Description: Sets suit and denomination for all cards in hand equal to 0
	Preconditions: Hand struct exists
	Postconditions: Card array in hand initialized.
*/
void init_hand(Hand* hand)
{
	for (int i = 0; i < 5; i++) {
		hand->cards[i].denomination = 0;
	}
	for (int i = 0; i < 5; i++) {
		hand->cards[i].suit = 0;
	}

}
void display_hand(Hand hand, const char* wSuit[], const char* wDenomination[])
{
	printf("Your current hand: \n");
	for (int i = 0; i < 5; i++) {
		printf("%d.) %s of %s\n", i + 1, wDenomination[hand.cards[i].denomination], wSuit[hand.cards[i].suit]);
	}
}
void redraw(int discard_list[])
{
	int card_numbers[5] = { 0 };
	int discard = 0;
	do{
		printf("How many cards would you like to discard? Next you will choose *which* cards to discard..\n");
		scanf("%d", &discard);
		if (discard < 0 || discard > 5)
			printf("Invalid input. Try again.\n");
	} while (discard < 0 || discard > 5);

	switch (discard) {
	case 0:
		break;
	case 1:
		printf("Indicate the cards you would like to discard by their order in your hand (i.e. 1, 3, 5)\n");
		for (int i = 0; i < discard; i++)
			scanf("%d", &card_numbers[i]);
		break;
	case 2:
		printf("Indicate the cards you would like to discard by their order in your hand (i.e. 1, 3, 5)\n");
		for (int i = 0; i < discard; i++)
			scanf("%d", &card_numbers[i]);
		break;
	case 3:
		printf("Indicate the cards you would like to discard by their order in your hand (i.e. 1, 3, 5)\n");
		for (int i = 0; i < discard; i++)
			scanf("%d", &card_numbers[i]);
		break;
	case 4:
		printf("Indicate the cards you would like to discard by their order in your hand (i.e. 1, 3, 5)\n");
		for (int i = 0; i < discard; i++)
			scanf("%d", &card_numbers[i]);
		break;
	case 5:
		printf("Indicate the cards you would like to discard by their order in your hand (i.e. 1, 3, 5)\n");
		for (int i = 0; i < discard; i++)
			scanf("%d", &card_numbers[i]);
		break;
	default:
		break;
	}
	for (int check = 1; check <= 5; check++) {
		for (int i = 0; i < 5; i++) {
			if (card_numbers[i] == check)
				discard_list[i] = 1;
		}
	}
}