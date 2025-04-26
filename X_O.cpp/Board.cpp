#include "Board.h"
#include <iostream>

Board::Board(int s) {
	size = s;
	dasht = vector<vector<char>>(size, vector<char>(size, ' '));
}

void Board::initBoard() {
	for (int i = 0; i < dasht.size(); ++i) {
		for (int j = 0; j < dasht.size(); ++j) {

			if (i == 1 || i == 3) {
				dasht[i][j] = '-';
			}
			else {
				if (j == 1 || j == 3) {
					dasht[i][j] = '|';
				}
				else {
					dasht[i][j] = ' ';
				}
			}

		}
	}
}

void Board::showBoard(Position cursor) {
	cout << "\033[32m" << "|-----|" << "\033[0m" << endl;

	for (int i = 0; i < dasht.size(); ++i) {
		for (int j = 0; j < dasht.size(); ++j) {

			if (i == 0 && j == 0) {
				cout << "\033[32m" << "|" << "\033[0m";
			}

			if (dasht[i][j] == 'X') {
				cout << "\033[31m" << dasht[i][j] << "\033[0m";
			}
			else if (dasht[i][j] == 'O') {
				cout << "\033[34m" << dasht[i][j] << "\033[0m";
			}
			else if (i == cursor.row && j == cursor.col) {
				cout << "\033[32m" << "*" << "\033[0m";
			}
			else {
				cout << dasht[i][j];
			}

		}

		cout << "\033[32m" << "|" << "\033[0m" << endl;

		if (i != 5) {
			cout << "\033[32m" << "|" << "\033[0m";
		}

	}
	cout << "\033[32m" << "-----|" << "\033[0m" << endl;

}
