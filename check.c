#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "check.h"

// This file contains functions that check if any user wins

int checkStatus(int** board, int numRows, int numCols, int numToWin, int row, int col, int turn) {
	if (win(board, numRows, numCols, numToWin, row, col)) {
		return turn;	// If player 1 or player 2 wins, return 1 or 2
	}
	else {
		return 0; // If no one wins, return 0
	}
}

bool win(int** board, int numRows, int numCols, int numToWin, int row, int col) {
	// 4 cases of winning: row, column, two diagonals
	return ( rowWin(board, numCols, numToWin, row, col) || colWin(board, numRows, numToWin, row, col) || diagULLRWin(board, numRows, numCols, numToWin, row, col) || diagURLLWin(board, numRows, numCols, numToWin, row, col) );
}

bool rowWin(int** board, int numCols, int numToWin, int row, int col) {
	// Check if one player wins in a row
	return (checkLeft(board, numCols, row, col) + checkRight(board, numCols, row, col) + 1 >= numToWin);
}

bool colWin(int** board, int numRows, int numToWin, int row, int col) {
	// Check if one player wins in a column
	return (checkUpper(board, numRows, row, col) + checkLower(board, numRows, row, col) + 1 >= numToWin);
}

bool diagULLRWin(int** board, int numRows, int numCols, int numToWin, int row, int col) {
	// Check if one player wins in a UpperLeft-LowerRight diagonal
	return (checkUpperLeft(board, numRows, numCols, row, col) + checkLowerRight(board, numRows, numCols, row, col) + 1 >= numToWin);
}

bool diagURLLWin(int** board, int numRows, int numCols, int numToWin, int row, int col) {
	// Check if one player wins in a UpperRight-LowerLeft diagonal
	return (checkUpperRight(board, numRows, numCols, row, col) + checkLowerLeft(board, numRows, numCols, row, col) + 1 >= numToWin);
}

int checkLeft(int** board, int numCols, int row, int col) {
	// Check the number of same pieces on the left
	int i = row;
	int j = col;
	int count = 0;
	int pieceToCheck = board[row][col];
	while (j > 0) { // not reaching the left bound
		j--; // proceed to the column on the left
		if (board[i][j] == pieceToCheck) {count++;}
		else {break;}
	}
	return count;
}

int checkRight(int** board, int numCols, int row, int col) {
	// Check the number of same pieces on the right
	int i = row;
	int j = col;
	int count = 0;
	int pieceToCheck = board[row][col];
	while (j < numCols-1) { // not reaching the right bound
		j++; // proceed to the column on the right
		if (board[i][j] == pieceToCheck) {count++;}
		else {break;}
	}
	return count;
}

int checkUpper(int** board, int numRows, int row, int col) {
	// Check the number of the same pieces above
	int i = row;
	int j = col;
	int count = 0;
	int pieceToCheck = board[row][col];
	while (i < numRows-1) { // not reaching the top row
		i++; // proceed to the upper row
		if (board[i][j] == pieceToCheck) {count++;}
		else {break;}
	}
	return count;
}

int checkLower(int** board, int numRows, int row, int col) {
	int i = row;
	int j = col;
	int count = 0;
	int pieceToCheck = board[row][col];
	while (i > 0) { // not reaching the bottom row
		i--; // proceed to the lower row
		if (board[i][j] == pieceToCheck) {count++;}
		else {break;}
	}
	return count;
}

int checkUpperLeft(int** board, int numRows, int numCols, int row, int col) {
	int i = row;
	int j = col;
	int count = 0;
	int pieceToCheck = board[row][col];
	while ((i < numRows-1) && (j > 0)) { // not reaching the top row and left bound
		i++; j--; // proceed to the upper left piece
		if (board[i][j] == pieceToCheck) {count++;}
		else {break;}
	}
	return count;
}

int checkUpperRight(int** board, int numRows, int numCols, int row, int col) {
	int i = row;
	int j = col;
	int count = 0;
	int pieceToCheck = board[row][col];
	while ((i < numRows-1) && (j < numCols-1)) { // not reaching the top row and right bound
		i++; j++; // proceed the the upper right piece
		if (board[i][j] == pieceToCheck) {count++;}
		else {break;}
	}
	return count;
}

int checkLowerLeft(int** board, int numRows, int numCols, int row, int col) {
	int i = row;
	int j = col;
	int count = 0;
	int pieceToCheck = board[row][col];
	while ((i > 0) && (j > 0)) { // not reaching the bottom row and left bound
		i--; j--; // proceed to the lower left piece
		if (board[i][j] == pieceToCheck) {count++;}
		else {break;}
	}
	return count;
}

int checkLowerRight(int** board, int numRows, int numCols, int row, int col) {
	int i = row;
	int j = col;
	int count = 0;
	int pieceToCheck = board[row][col];
	while ((i > 0) && (j < numCols-1)) { // not reaching the bottom row and right bound
		i--; j++; // proceed to the lower right piece
		if (board[i][j] == pieceToCheck) {count++;}
		else {break;}
	}
	return count;
}
