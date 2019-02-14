#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "board.h"
#include "game_play.h"

// This file contains the functions that set up, display, and clean up the board

void setUp(int*** board, int** piecesInCol, int numRows, int numCols) {
	*board = makeBoard(numRows, numCols);		// make the board
	*piecesInCol = setPiecesInCol(numCols);	// initialize the number of pieces in each column (0)
	return;
}

int** makeBoard(int numRows, int numCols) {
	// make the board
	
	int **board = (int**)malloc(numRows * sizeof(int*));
	int i, j = 0;
	
	for (i = 0; i < numRows; i++) {
		board[i] = (int*)malloc(numCols * sizeof(int));
		for(j = 0; j < numCols; ++j) {
			board[i][j] = 0;
		}
	}

	return board;
}

int* setPiecesInCol(int numCols) {
	// Setup an array that contains the number of pieces in each column

	int *piecesInCol = (int*)malloc(numCols * sizeof(int));
	int j = 0;
	
	for (j = 0; j < numCols; j++) {
		piecesInCol[j] = 0;
	}
	
	return piecesInCol;
}

char getPiece(int pieceID) {
	// Get the pieces based on the IDs of users (1 or 2), or '*' for empty spots
	switch (pieceID) {
		case 1:	return 'X'; break;
		case 2:	return 'O'; break;
		default: return '*'; break;
	}
}

void displayBoard(int **board, int numRows, int numCols) {
	// Display the board at the beginning, end, and at each turn
	
	int row, col = 0;
	
	// Print all rows with pieces
	for (row = numRows-1; row >= 0; row--) {
		printf("%3d", row);
		for (col = 0; col < numCols; col++) {
			printf("%4c", getPiece(board[row][col]));
		}
		printf("\n");
	}
	
	// Print the last line
	printf("   ");
	for (col = 0; col < numCols; col++) {
		printf("%4d", col);
	}
	printf("\n");
	
	return;
}

void cleanUp(int*** board, int** piecesInCol, int numRows) {
	// Game over, free the memory

	int row;
	
	for (row = 0; row < numRows; row++){
		free((*board)[row]);
	}
	free(*board);
	*board = NULL;

	free(*piecesInCol);
	*piecesInCol = NULL;

	return;
}
