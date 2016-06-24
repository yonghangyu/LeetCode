#include<iostream>
#include<vector>
using namespace std;

enum VectorType {row,column,subBox};

char* convert(vector<vector<char>>& board,int ith);

bool isValid(vector<vector<char>>& board,VectorType type,int i);

bool isValidSudoku(vector<vector<char>>& board);

void main() {

	
	system("pause");
	return;

	// for the test of sudoku board

}

bool isValidSudoku(vector<vector<char>>& board) {

	VectorType type;
	
	// testing row of the board
	type = row;
	for (int i = 0; i < 9; i++) {
		
		if (!isValid(board,type, i))
			return false;
	}

	// testing column of the board
	type = column;
	for (int i = 0; i < 9;i++) {
		
		if (!isValid(board,type, i))
			return false;
	}
	//testing subBox of the board
	type = subBox;
	for (int i = 0; i < 9;i++) {
		
		if (!isValid(board,type, i))
			return false;
	}

	return true;

}

bool isValid(vector<vector<char>>& board,VectorType type, int i) {
	if (type==row) {
		int count[9] = {0};
		cout << count[1];
		for (int j = 0; j < 9;j++) {
			if (count[board[i][j] - '0' -1] != 0)
				return false;
			else {
				count[board[i][j] - '0' -1]++;
			}

		}
		return true;
	}

	else if (type == column) {
		int count[9];

		for (int j = 0; j < 9; j++) {
			if (count[board[j][i] - '0' -1] != 0)
				return false;
			else {
				count[board[j][i] - '0' -1]++;
			}

		}
		return true;
	}

	else {
		int count[9];
		char* arrayConvert;
		arrayConvert = convert(board,i);
		
		for (int k = 0; k < 9;k++) {
			if (count[arrayConvert[k] - '0' - 1] != 0)
				return false;
			else
				count[arrayConvert[k] - '0' - 1]++;

		}
		return true;

	}

}


char* convert(vector<vector<char>>& board,int ith) {

	char arrayConvert[9];
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3;j++) {
			arrayConvert[i * 3 + j] = board[(ith/3)*3+i][(ith%3)*3+j];
		}

	return arrayConvert;
}






