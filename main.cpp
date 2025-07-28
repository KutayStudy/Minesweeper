#include <iostream>
#include "mineSweeper.h"

using namespace std;

int main() {
	mineSweeper m;
	int row, column;
	cout << "Enter the desired row number: ";
	cin >> row;
	cout << "Enter the desired column number: ";
	cin >> column;
	vector<vector<char>> userBoard = m.createUserBoard(row,column);
	vector<vector<char>> realBoard = m.createRealBoard(userBoard);
	bool game_over = false;
	int opened_cells = 0, total_cells = (row * column) - (row * column / 4);
	int row1 = 0, column1 = 0, value = 0, point = 0;
	do {
		system("CLS");
		m.showUserBoard(userBoard);
		cout << "Enter the row you guess: ";
		cin >> row1;
		cout << "Enter the column you guess: ";
		cin >> column1;
		if (row1 < 0 || row1 >= row || column1 < 0 || column1 >= column) {
			cout << "Invalid coordinates!!! Please enter values between 0 and " << row - 1
				<< " for rows and between 0 and " << column - 1 << " for columns." << endl;
			system("pause");
			continue; 
		}
		if (userBoard[row1][column1] != 'X') {
			cout << "This cell is already opened!" << endl;
			system("pause");
			continue;
		}
		value = m.chooseThat(realBoard, row1, column1);
		if (value == -1) {
			system("CLS");
			game_over = true;
			point = 0;
		}
		else {
			userBoard[row1][column1] = '0' + value;
			point++;
			opened_cells++;
		}

		if (opened_cells == total_cells) {
			game_over = true;
		}

	} while (game_over == false);

	if ((game_over == true) && (point == 0)) {
		m.showUserBoard(realBoard);
		cout << "GAME OVER!!!" << endl;
	}
	else {
		m.showUserBoard(realBoard);
		cout << "You won with " << point << " point";
	}
	return 0;
}