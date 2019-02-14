#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include "board.h"
#include "game_play.h"
#include "input_validation.h"
#include "check.h"

// This is the main code file of the connectN program

// Game-play function
void connectN(int numRows, int numCols, int numToWin);

// Display result
void displayResult(int status);

int main(int argc, char* argv[]) {
	
	if (argc < 4) { // Too few arguments
		printf("Not enough arguments entered\n");
		printf("Usage connectn.out num_rows num_columns number_of_pieces_in_a_row_needed_to_win\n");
		return 0;
	}
	
	else if (argc > 4) { // Too many arguments
		printf("Too many arguments entered\n");
		printf("Usage connectn.out num_rows num_columns number_of_pieces_in_a_row_needed_to_win\n");
		return 0;
	}
	
	else { // Correct number of arguments, start the game
		int numRows = atoi(argv[1]);
		int numCols = atoi(argv[2]);
		int numToWin = atoi(argv[3]);
		connectN(numRows, numCols, numToWin);
		return 0;
	}
	
}

void connectN(int numRows, int numCols, int numToWin) { // The main function

	int **board = NULL;				// the space to contain pieces
	int *piecesInCol = NULL;	// the array to store number of pieces in each column
	int totalPieces = 0;			// number of total pieces
	int row, col = 0;					// records the row number and column number of each move
	
	int turn = 0; // turn indicator
	// Initial it to 0; at the first play it will be set to 1
	// 1: player 1
	// 2: player 2

	int status = 0;  // intitial status: nobody wins
	// 0: nobody won
	// 1: player 1 won
	// 2: player 2 won	
	
	// Game start
	setUp(&board, &piecesInCol, numRows, numCols);
	
	// Game play
	while ((status == 0) && (totalPieces != numRows*numCols)) {
		changeTurn(&turn);
		displayBoard(board, numRows, numCols);
		getMove(board, piecesInCol, numRows, numCols, &col);
		playMove(board, piecesInCol, &row, col, turn);
		totalPieces++;
		status = checkStatus(board, numRows, numCols, numToWin, row, col, turn);
	}

	// Game over
	displayBoard(board, numRows, numCols);
	displayResult(status);
	cleanUp(&board, &piecesInCol, numRows);
	
	return;
}

void displayResult(int status) { // Game over, display result
	switch (status) {
		case 1: // Player 1 won
		case 2: // Player 2 won
			printf("Player %d Won!", status); break;
		default: // Tie game
			printf("Tie game!"); break;
		}
	printf("\n");
	return;
}
