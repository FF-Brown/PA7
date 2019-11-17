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
			//system("cls");
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
/*
shuffle cards in deck (starting code)
*/
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
/*
deal cards in deck (starting code)
*/
void deal(const int wDeck[][13], const char* wDenomination[], const char* wSuit[], Hand* player_hand, Hand* dealer_hand, Hand* buffer1, Hand* buffer2)
{
	int row = 0;    /* row number */
	int column = 0; /*column number */
	int card = 0;   /* card counter */

	/* deal 5 cards to player */
	for (card = 1; card <= 5; card++) {
		/* loop through rows of wDeck */
		for (row = 0; row <= 3; row++)	{
			/* loop through columns of wDeck for current row */
			for (column = 0; column <= 12; column++) {
				/* if slot contains current card, display card */
				if (wDeck[row][column] == card)	{
					//printf("%5s of %-8s%c", wDenomination[column], wSuit[row], card % 2 == 0 ? '\n' : '\t');
					player_hand->cards[card - 1].denomination = column;
					player_hand->cards[card - 1].suit = row;
					//printf("%5s of %-8s%c", wDenomination[hand->cards[card - 1].denomination], wSuit[hand->cards[card - 1].suit], card % 2 == 0 ? '\n' : '\t');
				}
			}
		}
	}
	//Deal next 5 cards to dealer
	for (; card <= 10; card++) {
		for (row = 0; row <= 3; row++) {
			for (column = 0; column <= 12; column++) {
				if (wDeck[row][column] == card)	{
					//printf("%5s of %-8s%c", wDenomination[column], wSuit[row], card % 2 == 0 ? '\n' : '\t');
					dealer_hand->cards[card - 6].denomination = column;
					dealer_hand->cards[card - 6].suit = row;
					//printf("%5s of %-8s%c", wDenomination[hand->cards[card - 1].denomination], wSuit[hand->cards[card - 1].suit], card % 2 == 0 ? '\n' : '\t');
				}
			}
		}
	}
	//Deal next 5 cards to first buffer
	for (; card <= 15; card++) {
		for (row = 0; row <= 3; row++) {
			for (column = 0; column <= 12; column++) {
				if (wDeck[row][column] == card) {
					//printf("%5s of %-8s%c", wDenomination[column], wSuit[row], card % 2 == 0 ? '\n' : '\t');
					buffer1->cards[card - 11].denomination = column;
					buffer1->cards[card - 11].suit = row;
					//printf("%5s of %-8s%c", wDenomination[hand->cards[card - 1].denomination], wSuit[hand->cards[card - 1].suit], card % 2 == 0 ? '\n' : '\t');
				}
			}
		}
	}
	//Deal next 5 cards to second buffer
	for (; card <= 20; card++) {
		for (row = 0; row <= 3; row++) {
			for (column = 0; column <= 12; column++) {
				if (wDeck[row][column] == card) {
					//printf("%5s of %-8s%c", wDenomination[column], wSuit[row], card % 2 == 0 ? '\n' : '\t');
					buffer2->cards[card - 16].denomination = column;
					buffer2->cards[card - 16].suit = row;
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
void get_redraw(int discard_list[])
{
	int card_numbers[5] = { 0 };
	int discard = 0;
	do{
		printf("How many cards would you like to discard? Next you will choose *which* cards to discard.\n");
		scanf("%d", &discard);
		if (discard < 0 || discard > 5)
			printf("Invalid input. Try again.\n");
	} while (discard < 0 || discard > 5);

	switch (discard) {
	case 0:
		break;
	case 1:
		printf("Indicate the cards you would like to discard by their order in your hand (i.e. 1, 3, 5, enter)\n");
		//for (int i = 0; i < discard; i++)
		//	scanf("%d", &card_numbers[i]);
		scanf("%d", &card_numbers[0]);
		break;
	case 2:
		printf("Indicate the cards you would like to discard by their order in your hand (i.e. 1, 3, 5, enter)\n");
		//for (int i = 0; i < discard; i++)
		//	scanf("%d", &card_numbers[i]);
		scanf("%d%d", &card_numbers[0], &card_numbers[1]);
		break;
	case 3:
		printf("Indicate the cards you would like to discard by their order in your hand (i.e. 1, 3, 5, enter)\n");
		//for (int i = 0; i < discard; i++)
		//	scanf("%d", &card_numbers[i]);
		scanf("%d%d%d", &card_numbers[0], &card_numbers[1], &card_numbers[2]);
		break;
	case 4:
		printf("Indicate the cards you would like to discard by their order in your hand (i.e. 1, 3, 5, enter)\n");
		//for (int i = 0; i < discard; i++)
		//	scanf("%d", &card_numbers[i]);
		scanf("%d%d%d%d", &card_numbers[0], &card_numbers[1], &card_numbers[2], &card_numbers[3]);
		break;
	case 5:
		printf("Indicate the cards you would like to discard by their order in your hand (i.e. 1, 3, 5, enter)\n");
		//for (int i = 0; i < discard; i++)
		//	scanf("%d", &card_numbers[i]);
		scanf("%d%d%d%d%d", &card_numbers[0], &card_numbers[1], &card_numbers[2], &card_numbers[3], &card_numbers[4]);
		break;
	default:
		break;
	}
	for (int check = 1; check <= 5; check++) {
		for (int i = 0; i < 5; i++) {
			if (card_numbers[i] == check)
				discard_list[check - 1] = 1;
		}
	}
}
void redraw(int discard_list[], Hand* hand, Hand buffer)
{
	for (int i = 0; i < 5; i++) {
		if (discard_list[i] == 1) {
			hand->cards[i].denomination = buffer.cards[i].denomination;
			hand->cards[i].suit = buffer.cards[i].suit;
		}
	}
}
/*
	Function: cont_playing()
	Date Created:
	Description: Gives player the option to play again. New and improved version with a do-while loop (as it should be)
	Preconditions: Game over, all results displayed
	Postconditions: Returns player decision
*/
char cont_playing(void)
{
	char cont = '\0';
	do{
		printf("Would you like to play again? (y/n)\n");
		scanf(" %c", &cont);
		if (cont != 'y' && cont != 'n')
			printf("Invalid input.\n");
	} while (cont != 'y' && cont != 'n');
	return cont;
}
void init_deck(int deck[][13])
{
	for (int rows = 0; rows < 4; rows++) {
		for (int columns = 0; columns < 13; columns++) {
			deck[rows][columns] = 0;
		}
	}
}
void precheck_hand(Hand hand, int denominations[], int suits[])
{
	for (int i = 0; i < 5; i++)	{
		denominations[hand.cards[i].denomination]++;
		suits[hand.cards[i].suit];
	}
}
//denomination
int check_four(int denominations[])
{
	int result = 0;
	for (int i = 0; i < 14; i++) {
		if (denominations[i] == 4)
			result = 1;
	}
	return result;
}
//same suit
int check_flush(int suits[])
{
	int result = 0;
	for (int i = 0; i < 5; i++) {
		if (suits[i])
			result = 1;
	}
	return result;
}
//consecutive
int check_straight(int denominations[])
{
	short result = 0;
	for (int i = 0; i < 11; i++) {
		if (denominations[i] == 1) {
			for (int j = 0; j < 4; j++) {
				if (denominations[j] == 1)
					++result;
			}
		}
	}
	if (result == 4) result = 1;
	else result = 0;
	return result;
}
int check_three(int denominations[])
{
	int result = 0;
	for (int i = 0; i < 14; i++) {
		if (denominations[i] == 3)
			result = 1;
	}
	return result;
}
int check_twoPair(int denominations[])
{
	int result = 0;
	for (int i = 0; i < 14; i++) {
		if (denominations[i] >= 2)
			result++;
	}
	if (result == 2) result = 1;
	else result = 0;
	return result;
}
int check_pair(int denominations[])
{
	int result = 0;
	for (int i = 0; i < 14; i++) {
		if (denominations[i] >= 2)
			result = 1;
	}
	return result;
}
int check_master(int denominations[], int suits[])
{
	short score = 0;
	if (check_four(denominations))
		score = FOUR_OF_A_KIND;
	else if (check_flush(suits))
		score = FLUSH;
	else if (check_straight(denominations))
		score = STRAIGHT;
	else if (check_three(denominations))
		score = THREE_OF_A_KIND;
	else if (check_twoPair(denominations))
		score = TWO_PAIR;
	else if (check_pair(denominations))
		score = PAIR;
	return score;
}