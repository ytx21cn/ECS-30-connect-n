#ifndef GAME_PLAY_H
#define GAME_PLAY_H

	void getMove(int** board, int* piecesInCol, int numRows, int numCols, int* col);
	void playMove(int** board, int* piecesInCol, int* row, int col, int turn);
	void changeTurn(int* turn);
	
#endif
