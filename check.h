#ifndef CHECK_H
#define CHECK_H

	int checkStatus(int** board, int numRows, int numCols, int numToWin, int row, int col, int turn);

	bool win(int** board, int numRows, int numCols, int numToWin, int row, int col);
	bool rowWin(int** board, int numCols, int numToWin, int row, int col);
	bool colWin(int** board, int numRows, int numToWin, int row, int col);
	bool diagULLRWin(int** board, int numRows, int numCols, int numToWin, int row, int col);
	bool diagURLLWin(int** board, int numRows, int numCols, int numToWin, int row, int col);

	int checkLeft(int** board, int numCols, int row, int col);
	int checkRight(int** board, int numCols, int row, int col);
	int checkUpper(int** board, int numRows, int row, int col);
	int checkLower(int** board, int numRows, int row, int col);
	int checkUpperLeft(int** board, int numRows, int numCols, int row, int col);
	int checkUpperRight(int** board, int numRows, int numCols, int row, int col);
	int checkLowerLeft(int** board, int numRows, int numCols, int row, int col);
	int checkLowerRight(int** board, int numRows, int numCols, int row, int col);

#endif
