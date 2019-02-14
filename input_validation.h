#ifndef INPUT_VALIDATION_H
#define INPUT_VALIDATION_H

	bool isValidMove(int numArgsRead, int numArgsNeeded, int** board, int* piecesInCol, int numRows, int numCols, int col);
	bool isValidFormat(int numArgsRead, int numArgsNeeded);
	bool colPlayable (int** board, int* piecesInCol, int numRows, int numCols, int col);
	
#endif
