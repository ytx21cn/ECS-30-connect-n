#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include "input_validation.h"

bool isValidMove(int numArgsRead, int numArgsNeeded, int** board, int* piecesInCol, int numRows, int numCols, int col) {
	// This function checks if the user's input format is valid and if the number represents a playable column
	return (isValidFormat(numArgsRead, numArgsNeeded) && colPlayable(board, piecesInCol, numRows, numCols, col));
}

bool isValidFormat(int numArgsRead, int numArgsNeeded) {
	// This function checks if the format is valid
	char newLine = '\n';
	bool isValid = true;
	if(numArgsRead != numArgsNeeded){ // didn't fill in all the format specifiers
		isValid = false; // format is not correct
	}
	do {
		scanf("%c", &newLine);
		if (!isspace(newLine)) {
			isValid = false;
			// will return false if found one non-whitespace character after the integer
		}
	} while (newLine != '\n');
	return isValid;
}

bool colPlayable (int** board, int* piecesInCol, int numRows, int numCols, int col) {
	// This function checks if the column specified by the user can still accept a piece
	if (!((col >= 0) && (col <= numCols-1))) {
		return false;
	}
	else if (!(piecesInCol[col] < numRows)) {
		return false;
	}
	return true;
}
