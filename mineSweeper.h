#pragma once
#include <vector>

using namespace std;

class mineSweeper
{
public:
	mineSweeper();
	vector<vector<char>> createUserBoard(int n, int n1);
	vector<vector<char>> createRealBoard(vector<vector<char>> vV);
	void showUserBoard(vector<vector<char>> vV);
	int chooseThat(const vector<vector<char>>& vV ,int row, int column);
};

