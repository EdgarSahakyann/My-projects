#pragma once
#include "position.h"
#include <vector>
using namespace std;


class Board {

protected:
	int size;
	vector<vector<char>> _board;

public:
	Board(int s = 5);
	void initBoard();
	void showBoard(Position cursor);
};
