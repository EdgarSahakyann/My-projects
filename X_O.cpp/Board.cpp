#include "Board.h"
#include <iostream>

Board::Board(int s) {
	size = s;
	_board = vector<vector<char>>(size, vector<char>(size, ' '));
}

void Board::initBoard() {
	for (int i = 0; i < _board.size(); ++i) {
		for (int j = 0; j < _board.size(); ++j) {

			if (i == 1 || i == 3) {
				_board[i][j] = '-';
			}
			else {
				if (j == 1 || j == 3) {
					_board[i][j] = '|';
				}
				else {
					_board[i][j] = ' ';
				}
			}

		}
	}
}

void Board::showBoard(Position cursor) {
	cout << "\033[32m" << "|-----|" << "\033[0m" << endl;

	for (int i = 0; i < _board.size(); ++i) {
		for (int j = 0; j < _board.size(); ++j) {

			if (i == 0 && j == 0) {
				cout << "\033[32m" << "|" << "\033[0m";
			}

			if (_board[i][j] == 'X') {
				cout << "\033[31m" << _board[i][j] << "\033[0m";
			}
			else if (_board[i][j] == 'O') {
				cout << "\033[34m" << _board[i][j] << "\033[0m";
			}
			else if (i == cursor.row && j == cursor.col) {
				cout << "\033[32m" << "*" << "\033[0m";
			}
			else {
				cout << _board[i][j];
			}

		}

		cout << "\033[32m" << "|" << "\033[0m" << endl;

		if (i != 5) {
			cout << "\033[32m" << "|" << "\033[0m";
		}

	}
	cout << "\033[32m" << "-----|" << "\033[0m" << endl;

}
