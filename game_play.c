#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "game_play.h"
#include "input_validation.h"

void getMove(int** board, int* piecesInCol, int numRows, int numCols, int* col) {
	// This function gets user move and check if it is valid; if not, it will continuously ask the user for a valid input
	int numArgsRead = 0;
	do {
		printf("Enter a column between 0 and %d to play in: ", numCols-1);
		numArgsRead = scanf("%d", col);
	} while (!isValidMove(numArgsRead, 1, board, piecesInCol, numRows, numCols, *col));
	return;
}

void playMove(int** board, int* piecesInCol, int* row, int col, int turn) {
	// This function plays the move specified by the user and updates the number of pieces in that column
	*row = piecesInCol[col]; // = (piecesInCol-1)+1
	board[(*row)][col] = turn;
	piecesInCol[col]++;
}

void changeTurn(int* turn) {
	// This function changes turn
	switch (*turn) {
		case 1: *turn = 2; break;
		case 2: *turn = 1; break;
		default: *turn = 1; break;
	}
	return;
}
