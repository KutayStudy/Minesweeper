#include "mineSweeper.h"
#include <iostream>
#include <vector>
#include <random>
#include <iomanip>

using namespace std;

mineSweeper::mineSweeper() {

}
vector<vector<char>> mineSweeper::createUserBoard(int n, int n1) {
	vector<vector<char>> vV;
	for (int i = 0; i < n; i++) {
		vector<char> v;
		for (int j = 0; j < n1; j++) {
			v.push_back('X');
		}
		vV.push_back(v);
	}
	return vV;
}

vector<vector<char>> mineSweeper::createRealBoard(vector<vector<char>> vV){
	int n = vV.size();
	int n2 = vV[0].size();
	int bombNumber = (n * n2) / 5;
	int counter = bombNumber;

	random_device rd;
	mt19937 engine(rd());

	uniform_int_distribution<int> distribution(0, n - 1);
	uniform_int_distribution<int> distribution2(0, n2 - 1);
	
	while (counter > 0) {
		int randomNumber = distribution(engine);
		int randomNumber2 = distribution2(engine);
		if (vV[randomNumber][randomNumber2] != 'B') {
			vV[randomNumber][randomNumber2] = 'B';
			counter--;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n2; j++) {
			if (vV[i][j] == 'X') {
				vV[i][j] = 'O';
			}
		}
	}
	return vV;
}

void mineSweeper::showUserBoard(vector<vector<char>> vV) {
	cout << "   ";
	for (int i = 0; i < vV[0].size(); i++) {
		cout << setw(3) << i;
	}
	cout << endl << endl;
	for (int i = 0; i < vV.size(); i++) {
		cout << setw(2) << i << " ";
		for (int j = 0; j < vV[0].size(); j++) {
			cout << setw(3) << vV[i][j];
		}
		cout << endl;
		cout << endl;
	}
}

int mineSweeper::chooseThat(const vector<vector<char>>& vV,int row, int column) {
	int total = 0;
	if (vV[row][column] == 'B') {
		return -1;
	}
	else {
		int nR = vV.size();
		int nC = vV[0].size();
		for (int dr = -1; dr <= 1; dr++) {
			for (int dc = -1; dc <= 1; dc++) {
				if (dr == 0 && dc == 0) {
					continue;
				}
				int nr = row + dr;
				int nc = column + dc;
				if (nr >= 0 && nr < nR && nc >= 0 && nc < nC) {
					if (vV[nr][nc] == 'B') {
						total++;
					}
				}
			}
		}
		return total;
	}
}


