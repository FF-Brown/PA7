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
	printf("Five-card draw\n");
	printf("This is one of the more simple versions of poker. As this text-based edition does not include\nbetting, we will exclude an explanation of that system from these rules.\n");
	printf("At the beginning of the match, players (including the dealer) are dealt five cards from the deck.\nThey then have the option to discard as many cards as they want and draw that many again.\n");
	printf("Once all players have been dealt new cards, their hands are scored. Possible hands include:\n");
	printf("Four-of-a-kind: Four cards of the same denomination (i.e. jacks, queens, threes, etc.\n");
	printf("Flush: All cards of the same suit (i.e. hearts)\n");
	printf("Straight: Five denominations in a row (i.e. 3, 4, 5, 6, 7)\n");
	printf("Three-of-a-kind: Three cards of the same denomination\n");
	printf("Two pair: Two pairs of denominations (i.e. 2 fours, 2 queens)\n");
	printf("Pair: Two of the same denomination\n");
	printf("The hands above are listed in order or desirability. Whoever has the better hand wins.\n");
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
/*
	Function: display_hand()
	Date Created: 
	Description: Prints the player's current hand to the screen
	Preconditions: Cards have been dealt
	Postconditions: Hand printed to screen
*/
void display_hand(Hand hand, const char* wSuit[], const char* wDenomination[])
{
	printf("Your current hand: \n");
	for (int i = 0; i < 5; i++) {
		printf("%d.) %s of %s\n", i + 1, wDenomination[hand.cards[i].denomination], wSuit[hand.cards[i].suit]);
	}
}
/*
	Function: get_redraw()
	Date Created: 
	Description: Asks user which cards they want to discard. Creates an array of input. Translates that array into discard_list[]
	Preconditions: Player hand has been displayed. 
	Postconditions: discard_list[] filled
*/
void get_redraw(int discard_list[])
{
	int card_numbers[5] = { 0 };
	int discard = 0;
	//init discard_list
	//for (short i = 0; i < 5; i++) discard_list[i] = 0;

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
		scanf("%d", &card_numbers[0]);
		system("cls");
		break;
	case 2:
		printf("Indicate the cards you would like to discard by their order in your hand (i.e. 1, 3, 5, enter)\n");
		scanf("%d%d", &card_numbers[0], &card_numbers[1]);
		system("cls");
		break;
	case 3:
		printf("Indicate the cards you would like to discard by their order in your hand (i.e. 1, 3, 5, enter)\n");
		scanf("%d%d%d", &card_numbers[0], &card_numbers[1], &card_numbers[2]);
		system("cls");
		break;
	case 4:
		printf("Indicate the cards you would like to discard by their order in your hand (i.e. 1, 3, 5, enter)\n");
		scanf("%d%d%d%d", &card_numbers[0], &card_numbers[1], &card_numbers[2], &card_numbers[3]);
		system("cls");
		break;
	case 5:
		printf("Indicate the cards you would like to discard by their order in your hand (i.e. 1, 3, 5, enter)\n");
		scanf("%d%d%d%d%d", &card_numbers[0], &card_numbers[1], &card_numbers[2], &card_numbers[3], &card_numbers[4]);
		system("cls");
		break;
	default:
		break;
	}
	//Assign discard_list according to input values
	for (int check = 1; check <= 5; check++) {
		for (int i = 0; i < 5; i++) {
			if (card_numbers[i] == check)
				discard_list[check - 1] = 1;
		}
	}
}
/*
	Function: redraw()
	Date Created:
	Description: Uses discard_list[] to take cards from the buffer hand and put them into the player's hand
	Preconditions: Player has chosen which cards to discard
	Postconditions: Player has new cards in their hand
*/
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
	Preconditions: Game over
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
/*
	Function: init_deck()
	Date Created:
	Description: Resets deck for a new round
	Preconditions: Beginning of round
	Postconditions: Deck reset to 0's
*/
void init_deck(int deck[][13])
{
	for (int rows = 0; rows < 4; rows++) {
		for (int columns = 0; columns < 13; columns++) {
			deck[rows][columns] = 0;
		}
	}
}
/*
	Function: precheck_hand()
	Date Created:
	Description: Sorts cards from hand into counting arrays by denomination and suit for scoring
	Preconditions: Ready to score
	Postconditions: denominations[] and suits[] arrays formed
*/
void precheck_hand(Hand hand, int denominations[], int suits[])
{
	for (int i = 0; i < 5; i++)	{
		denominations[hand.cards[i].denomination]++;
		suits[hand.cards[i].suit]++;
	}
}
/*
	Function: check_four()
	Date Created:
	Description: Checks to see if player has a four-of-a-kind, returns 1/0 (T/F)
	Preconditions: Player has drawn any new cards and precheck_hand() has run
	Postconditions: Outcome returned
*/
int check_four(int denominations[])
{
	int result = 0;
	for (int i = 0; i < 13; i++) {
		if (denominations[i] == 4)
			result = 1;
	}
	return result;
}
/*
	Function: check_flush()
	Date Created:
	Description: Checks if player has a flush
	Preconditions: precheck_hand() has run
	Postconditions: Result (1/0) returned
*/
int check_flush(int suits[])
{
	int result = 0;
	for (int i = 0; i < 5; i++) {
		if (suits[i] == 5)
			result = 1;
	}
	return result;
}
/*
	Function: check_straight()
	Date Created:
	Description: Checks if player has a straight
	Preconditions: precheck_hand() has run
	Postconditions: Returns 1/0
*/
int check_straight(int denominations[])
{
	short result = 0;
	for (int i = 0; i < 9; i++) {
		//Straight impossible if 2 cards of same value
		if (denominations[i] > 1)
			return 0;
		//Whenever a 1 found, check next 4 denominations
		else if (denominations[i] == 1) {
			for (int j = i; j < i + 5; j++) {
				if (denominations[j] == 1)
					++result;
			}
			if (result == 5) {
				result = 1;
				return result;
			}
			else result = 0;
		}
	}
	return result;
}
/*
	Function: check_three()
	Date Created:
	Description: Checks if player has a three-of-a-kind
	Preconditions: precheck_hand() has run
	Postconditions: Returns 1/0
*/
int check_three(int denominations[])
{
	int result = 0;
	for (int i = 0; i < 13; i++) {
		if (denominations[i] == 3)
			result = 1;
	}
	return result;
}
/*
	Function: check_twoPair()
	Date Created:
	Description: Checks if player has two pairs
	Preconditions: precheck_hand() has run
	Postconditions: Returns 1/0
*/
int check_twoPair(int denominations[])
{
	int result = 0;
	for (int i = 0; i < 13; i++) {
		if (denominations[i] >= 2)
			result++;
	}
	if (result == 2) result = 1;
	else result = 0;
	return result;
}
/*
	Function: check_pair()
	Date Created:
	Description: Checks if the player has a pair
	Preconditions: precheck_hand() has run 
	Postconditions: Returns 1/0
*/
int check_pair(int denominations[])
{
	int result = 0;
	for (int i = 0; i < 13; i++) {
		if (denominations[i] >= 2)
			result = 1;
	}
	return result;
}
/*
	Function: check_master()
	Date Created:
	Description: Runs all other score checking functions in order. Breaks when one is true.
	Preconditions: precheck_hand() has run
	Postconditions: Returns score
*/
short check_master(int denominations[], int suits[])
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
/*
	Function: close2four()
	Date Created: 11/17/2019
	Description: Checks to see if player has 3 of a kind. Assigns discard_list[] if so
	Preconditions: precheck_hand() run
	Postconditions: Returns 1/0
*/
short close2four(Hand hand, int denominations[], int discard_list[])
{
	short index = 0, i = 0, result = 0;
	
	for (i = 0; i < 13; i++) {
		if (denominations[i] == 3) {
			index = i; //Mark location of 3 cards
			result = 1; //Report as found

			//Assign discard list
			for (i = 0; i < 5; i++) {
				if (hand.cards[i].denomination == index)
					discard_list[i] = 0;
				else discard_list[i] = 1;
			}
		}
	}
	return result;
}
/*
	Function: close2flush()
	Date Created: 11/17/2019
	Description: Checks to see if player is close to having a flush. Assigns discard_list[] if so
	Preconditions: precheck_hand() run
	Postconditions: Returns 1/0
*/
short close2flush(Hand hand, int suits[], int discard_list[])
{
	short index = 0, i = 0, result = 0;
	//Find which suit has at least 3 cards
	for (i = 0; i < 5; i++) {
		if (suits[i] >= 3) {
			index = i;
			result = 1;

			//Assign discard_list
			for (i = 0; i < 5; i++) {
				if (hand.cards[i].suit == index)
					discard_list[i] = 0;
				else discard_list[i] = 1;
			}
		}
	}
	return result;
}
/*
	Function: close2straight()
	Date Created: 11/17/2019
	Description: Checks to see if player nearly has a straight. Assigns discard_list[] if so.
	Preconditions: precheck_hand() run
	Postconditions: Returns 1/0
*/
short close2straight(Hand hand, int denominations[], int discard_list[])
{	
	short i = 0, count = 0, j = 0, result = 0;
	for (i = 0; i < 9; i++) {
		//When 1 found...
		if (denominations[i] == 1) {
			//Check # of cards in the next 4 slots
			for (j = i; j < i + 5; j++) {
				if (denominations[j] == 1)
					++count;
			}
			//If at least 3 total...
			if (count >= 3) {
				//Keep those 3 or 4 cards
				for (short k = 0; k < 5; k++) {
					if (hand.cards[k].denomination >= i && hand.cards[k].denomination <= i + 4)
						discard_list[k] = 0;
					else discard_list[k] = 1;
				}
				result = 1;
			}
			else count = 0;
		}
	}
	return result;
}
/*
	Function: close2three()
	Date Created: 11/17/2019
	Description: Checks to see if player nearly has a three of a kind. Assigns discard_list[] if so.
	Preconditions: precheck_hand() run
	Postconditions: Returns 1/0
*/
short close2three(Hand hand, int denominations[], int discard_list[])
{
	short index = 0, i = 0, result = 0;
	//Find the pair
	for (i = 0; i < 13; i++) {
		if (denominations[i] == 2) {
			index = i;
			result = 1;

			//Assign discard_list
			for (i = 0; i < 5; i++) {
				if (hand.cards[i].denomination == index)
					discard_list[i] = 0;
				else discard_list[i] = 1;
			}
		}
	}
	return result;
}
/*
	Function: close_enough()
	Date Created: 11/17/2019
	Description: Runs all close2 functions. 
	Preconditions: precheck_hand() run
	Postconditions: Returns successful or not
*/
short close_enough(Hand hand, int denominations[], int suits[], int discard_list[])
{
	short result = 0, score = 0;
	//run check_master
	score = check_master(denominations, suits);
	//if score >= 4, fantastic. No discards
	if (score >= 4) {
		for (short i = 0; i < 5; i++) discard_list[i] = 0;
		result = 1;
	}
	//Otherwise run close2 functions
	else if (close2four(hand, denominations, discard_list))
		result = 1;
	else if (close2flush(hand, suits, discard_list))
		result = 1;
	else if (close2straight(hand, denominations, discard_list))
		result = 1;
	else if (close2three(hand, denominations, discard_list))
		result = 1;
	else {
		for (short i = 0; i < 5; i++) discard_list[i] = 1;
		result = 0;
	}
	return result;
}
/*
	Function: score_compare()
	Date Created: 11/17/2019
	Description: Compares the player and dealer's scores and prints result of round
	Preconditions: Game over, both scores calculated
	Postconditions: Result of round printed
*/
short score_compare(int player_score, int dealer_score, const char* winning_hands[])
{
	if (player_score > dealer_score) {
		printf("You won! You had a %s and the dealer only had a %s.\n", winning_hands[player_score], winning_hands[dealer_score]);
		return 1;
	}
	else if (player_score < dealer_score) {
		printf("You lose! The dealer had a %s and you only had a %s. Maybe work on your bluff next time, eh?\n", winning_hands[dealer_score], winning_hands[player_score]);
		return 0;
	}
	else {
		printf("Tie! Both you and the dealer had a %s!\n", winning_hands[player_score]);
		return -1;
	}
}