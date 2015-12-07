#include <stdio.h>
#include <stdlib.h>

int makeMove(char b[3][3], int row, int col, char player);
void drawTicTacToe(char grid[][3]);
int isFilled(char b[3][3]);
int checkWin(char b[3][3]);

int main()
{
	char board[3][3] = { { ' ', ' ', ' ' }, { ' ', ' ', ' ' }, { ' ', ' ', ' ' } }; // Initialized the board to spaces
	int player1Moves[2] = { 0 };											// Player1's moves saved in a 2-element array
	int player2Moves[2] = { 0 };											// Player2's moves saved in a 2-element array
	char player1 = 'O';														// Player1's representative symbol
	char player2 = 'X';														// Player2's representative symbol
	int rvMakeMove;															// Temp variable to store the return value of the makeMove() function

	printf("\n Welcome to TIC TAC TOE!!!!\n\n\n");

	// Display the blank board
	drawTicTacToe(board);
	puts("");

	while (1)
	{

		// PLAYER 1
		while (1)
		{
			printf("(Player 1) Enter in the board coordinates ( Row,Col; i.e. 0,2 ): ");
			scanf("%d,%d", &player1Moves[0], &player1Moves[1]);

			rvMakeMove = makeMove(board, player1Moves[0], player1Moves[1], player1); // Make the move
			if (rvMakeMove == 1)
			{
				puts("");
				drawTicTacToe(board);
				puts("");
				break;
			}

			else if (rvMakeMove == 0)
				printf("\nCoordinates not valid.\n\n");

			else
			{ // Coordinate had a symbol
				printf("\nCoordinates you entered have already been played.\n\n");
			}

		}

		//Check to see if player 1 won
		if (checkWin(board))
		{
			printf("Player 1 wins!\n\n");
			break;
		}

		// Check for full board -- The tie occurs only after the fifth move of the first player
		if (isFilled(board))
		{
			printf("Game is a draw.\n\n");
			break;
		}

		// END PLAYER1!


		// PLAYER 2
		while (1)
		{
			printf("(Player 2) Enter in the board coordinates ( Row,Col; i.e. 0,2 ): ");
			scanf("%d,%d", &player2Moves[0], &player2Moves[1]);

			rvMakeMove = makeMove(board, player2Moves[0], player2Moves[1], player2); // make the move
			if (rvMakeMove == 1)
			{
				puts("");
				drawTicTacToe(board);
				puts("");
				break;
			}

			else if (rvMakeMove == 0)
				printf("\nCoordinates not valid.\n\n");

			else
			{ // coordinate had a symbol
				printf("\nCoordinates you entered have already been played.\n\n");
			}
		}

		//Check to see if player 2 won
		if (checkWin(board))
		{
			printf("Player 2 wins!\n\n");
			break;
		}

		// END PLAYER 2
	}
	return 0;
}


// **********FUNCTIONS**********

int makeMove(char b[3][3], int row, int col, char player)
{
	if (row > 2 || col >2 || row < 0 || col < 0)  // we're out of bounds
	{
		return 0;
	}

	// We have to check to see if that spot is open
	if (b[row][col] == ' ')
		b[row][col] = player;

	else
		return -1;

	return 1;
}

void drawTicTacToe(char grid[][3])
{
	int i, j;

	//Display the Column Number header.
	printf("      0     1     2\n");

	printf("   \xda");
	for (i = 0; i < 17; i++)
	{
		printf("\xc4");
	}

	printf("\xbf");
	printf("\n");
	printf(" 0 \xb3%17c\xb3", ' ');

	for (i = 0; i < 3; i++)
	{
		printf("\n");
		if (i == 1)
			printf(" 1 \xb3");
		else
			printf("   \xb3");

		for (j = 0; j < 3; j++)
		{
			printf("%3c", grid[i][j]);
			if (j < 2)
				printf("  \xb3");
		}

		printf("%2c\xb3", ' ');
		printf("\n");
		if (i < 2)
			printf("   \xb3 \xc4\xc4\xc4\xc4\xc5\xc4\xc4\xc4\xc4\xc4\xc5\xc4\xc4\xc4\xc4 \xb3");
	}

	printf(" 2 \xb3%17c\xb3", ' ');
	printf("\n");
	printf("   \xc0");

	for (i = 0; i < 17; i++)
	{
		printf("\xc4");
	}

	printf("\xd9");
	printf("\n");
}

int isFilled(char b[3][3])
{
	int i, j;
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (b[i][j] == ' ')
				return 0;
		}
	}
	return 1;
}

int checkWin(char b[3][3])
{
	int i, j;

	// Check rows for a winner.
	for (i = 0; i < 3; i++)
	{
		if (b[i][0] != ' ' && b[i][0] == b[i][1] && b[i][1] == b[i][2])
			return 1;
	}

	// Check columns for a winner.
	for (j = 0; j < 3; j++)
	{
		if (b[0][j] != ' ' && b[0][j] == b[1][j] && b[1][j] == b[2][j])
			return 1;
	}

	// Check diagonals for a winner.
	if (b[0][0] != ' ' && b[0][0] == b[1][1] && b[1][1] == b[2][2])
		return 1;
	else if (b[0][2] != ' ' && b[0][2] == b[1][1] && b[1][1] == b[2][0])
		return 1;

	//  Return 0 to main() to continue game if no winner.
	else
		return 0;
}

// **********FUNCTIONS**********