#ifndef BOARD_H
#define BOARD_H

	char getPiece(int pieceID);
	
	void setUp(int*** board, int** piecesInCol, int numRows, int numCols);
	int** makeBoard(int numRows, int numCols);
	int* setPiecesInCol(int numCols);

	void displayBoard(int **board, int numRows, int numCols);

	void cleanUp(int*** board, int** piecesInCol, int numRows);

#endif
