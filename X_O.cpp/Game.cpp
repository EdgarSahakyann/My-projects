#include <ctime>
#include "Game.h"


Game::Game(string player1, string player2) : cursor(2, 2) {
	name1 = player1;
	name2 = player2;
	currentPlayer = 'X';
}

void Game::move(Position to, int& cnt) {
	if (validMove(to)) {
		cnt++;
		if (currentPlayer == 'X') {
			dasht[to.row][to.col] = 'X';
		}
		else {
			dasht[to.row][to.col] = 'O';
		}
	}
}

void Game::switchPlayers() {
	if (!gameOver()) {
		if (currentPlayer == 'X') {
			currentPlayer = 'O';
			cout << "It's " << name2 << "'s turn." << endl;
		}
		else {
			currentPlayer = 'X';
			cout << "It's " << name1 << "'s turn." << endl;;
		}
	}
}

bool Game::XWon() {
	if ((dasht[0][0] == 'X' && dasht[0][2] == 'X' && dasht[0][4] == 'X') ||
		(dasht[2][0] == 'X' && dasht[2][2] == 'X' && dasht[2][4] == 'X') ||
		(dasht[4][0] == 'X' && dasht[4][2] == 'X' && dasht[4][4] == 'X') ||
		(dasht[0][0] == 'X' && dasht[2][0] == 'X' && dasht[4][0] == 'X') ||
		(dasht[0][2] == 'X' && dasht[2][2] == 'X' && dasht[4][2] == 'X') ||
		(dasht[0][4] == 'X' && dasht[2][4] == 'X' && dasht[4][4] == 'X') ||
		(dasht[0][0] == 'X' && dasht[2][2] == 'X' && dasht[4][4] == 'X') ||
		(dasht[0][4] == 'X' && dasht[2][2] == 'X' && dasht[4][0] == 'X')) {
		return true;
	}
	return false;
}

bool Game::OWon() {
	if ((dasht[0][0] == 'O' && dasht[0][2] == 'O' && dasht[0][4] == 'O') ||
		(dasht[2][0] == 'O' && dasht[2][2] == 'O' && dasht[2][4] == 'O') ||
		(dasht[4][0] == 'O' && dasht[4][2] == 'O' && dasht[4][4] == 'O') ||
		(dasht[0][0] == 'O' && dasht[2][0] == 'O' && dasht[4][0] == 'O') ||
		(dasht[0][2] == 'O' && dasht[2][2] == 'O' && dasht[4][2] == 'O') ||
		(dasht[0][4] == 'O' && dasht[2][4] == 'O' && dasht[4][4] == 'O') ||
		(dasht[0][0] == 'O' && dasht[2][2] == 'O' && dasht[4][4] == 'O') ||
		(dasht[0][4] == 'O' && dasht[2][2] == 'O' && dasht[4][0] == 'O')) {
		return true;
	}
	return false;
}

bool Game::gameOver() {
	if (XWon() || OWon()) {
		return true;
	}
	return false;
}

bool Game::validMove(Position to) {
	if (dasht[to.row][to.col] != ' ') {
		return false;
	}
	return true;
}

char Game::getCurrentPlayer() {
	return currentPlayer;
}

Position Game::getCursor() {
	return cursor;
}

void Game::updateCursor(int ch) {
	switch (ch) {
	case 72:
		if (cursor.row > 0) cursor.row -= 2;
		break;
	case 80:
		if (cursor.row < 4) cursor.row += 2;
		break;
	case 75:
		if (cursor.col > 0) cursor.col -= 2;
		break;
	case 77:
		if (cursor.col < 4) cursor.col += 2;
		break;
	}
}

void Game::block() {
	for (int i = 0; i < size; i += 2) {
		for (int j = 0; j < size; j += 2) {

			if (dasht[i][0] == 'X' && dasht[i][4] == 'X' && validMove(Position(i, 2))) {
				dasht[i][2] = 'O';
				alreadyMoved = true;
				return;
			}
			else if (dasht[i][0] == 'X' && dasht[i][2] == 'X' && validMove(Position(i, 4))) {
				dasht[i][4] = 'O';
				alreadyMoved = true;
				return;
			}
			else if (dasht[i][2] == 'X' && dasht[i][4] == 'X' && validMove(Position(i, 0))) {
				dasht[i][0] = 'O';
				alreadyMoved = true;
				return;
			}

			else if (dasht[0][j] == 'X' && dasht[4][j] == 'X' && validMove(Position(2, j))) {
				dasht[2][j] = 'O';
				alreadyMoved = true;
				return;
			}
			else if (dasht[0][j] == 'X' && dasht[2][j] == 'X' && validMove(Position(4, j))) {
				dasht[4][j] = 'O';
				alreadyMoved = true;
				return;
			}
			else if (dasht[2][j] == 'X' && dasht[4][j] == 'X' && validMove(Position(0, j))) {
				dasht[0][j] = 'O';
				alreadyMoved = true;
				return;
			}

		}
	}

	if (dasht[0][0] == 'X' && dasht[4][4] == 'X' && validMove(Position(2, 2))) {
		dasht[2][2] = 'O';
		alreadyMoved = true;
		return;
	}
	else if (dasht[0][4] == 'X' && dasht[4][0] == 'X' && validMove(Position(2, 2))) {
		dasht[2][2] = 'O';
		alreadyMoved = true;
		return;
	}
	else if (dasht[0][0] == 'X' && dasht[2][2] == 'X' && validMove(Position(4, 4))) {
		dasht[4][4] = 'O';
		alreadyMoved = true;
		return;
	}
	else if (dasht[2][2] == 'X' && dasht[4][4] == 'X' && validMove(Position(0, 0))) {
		dasht[0][0] = 'O';
		alreadyMoved = true;
		return;
	}
	else if (dasht[0][4] == 'X' && dasht[2][2] == 'X' && validMove(Position(4, 0))) {
		dasht[4][0] = 'O';
		alreadyMoved = true;
		return;
	}
	else if (dasht[4][0] == 'X' && dasht[2][2] == 'X' && validMove(Position(0, 4))) {
		dasht[0][4] = 'O';
		alreadyMoved = true;
		return;
	}
	else {
		alreadyMoved = false;
	}

}

void Game::win() {
	for (int i = 0; i < size; i += 2) {
		for (int j = 0; j < size; j += 2) {

			if (dasht[i][0] == 'O' && dasht[i][4] == 'O' && validMove(Position(i, 2))) {
				dasht[i][2] = 'O';
				alreadyWon = true;
				return;
			}
			else if (dasht[i][0] == 'O' && dasht[i][2] == 'O' && validMove(Position(i, 4))) {
				dasht[i][4] = 'O';
				alreadyWon = true;
				return;
			}
			else if (dasht[i][2] == 'O' && dasht[i][4] == 'O' && validMove(Position(i, 0))) {
				dasht[i][0] = 'O';
				alreadyWon = true;
				return;
			}

			else if (dasht[0][j] == 'O' && dasht[4][j] == 'O' && validMove(Position(2, j))) {
				dasht[2][j] = 'O';
				alreadyWon = true;
				return;
			}
			else if (dasht[0][j] == 'O' && dasht[2][j] == 'O' && validMove(Position(4, j))) {
				dasht[4][j] = 'O';
				alreadyWon = true;
				return;
			}
			else if (dasht[2][j] == 'O' && dasht[4][j] == 'O' && validMove(Position(0, j))) {
				dasht[0][j] = 'O';
				alreadyWon = true;
				return;
			}

		}
	}

	if (dasht[0][0] == 'O' && dasht[4][4] == 'O' && validMove(Position(2, 2))) {
		dasht[2][2] = 'O';
		alreadyWon = true;
		return;
	}
	else if (dasht[0][4] == 'O' && dasht[4][0] == 'O' && validMove(Position(2, 2))) {
		dasht[2][2] = 'O';
		alreadyWon = true;
		return;
	}
	else if (dasht[0][0] == 'O' && dasht[2][2] == 'O' && validMove(Position(4, 4))) {
		dasht[4][4] = 'O';
		alreadyWon = true;
		return;
	}
	else if (dasht[2][2] == 'O' && dasht[4][4] == 'O' && validMove(Position(0, 0))) {
		dasht[0][0] = 'O';
		alreadyWon = true;
		return;
	}
	else if (dasht[0][4] == 'O' && dasht[2][2] == 'O' && validMove(Position(4, 0))) {
		dasht[4][0] = 'O';
		alreadyWon = true;
		return;
	}
	else if (dasht[4][0] == 'O' && dasht[2][2] == 'O' && validMove(Position(0, 4))) {
		dasht[0][4] = 'O';
		alreadyWon = true;
		return;
	}
	else {
		alreadyWon = false;
	}

}

void Game::compMove(string difficulty, int& cnt) {
	vector<Position> validMoves;
	Position finalMove(2, 2);
	cnt++;

	srand(time(0));

	for (int i = 0; i < size; i += 2) {
		for (int j = 0; j < size; j += 2) {
			if (validMove(Position(i, j))) {
				validMoves.push_back(Position(i, j));
			}
		}
	}

	if (difficulty == "easy") {
		if (!validMoves.empty()) {
			finalMove = validMoves[rand() % validMoves.size()];
			dasht[finalMove.row][finalMove.col] = 'O';
		}
	}
	else if (difficulty == "medium") {
		block();
		if (!validMoves.empty() && !alreadyMoved) {
			finalMove = validMoves[rand() % validMoves.size()];
			dasht[finalMove.row][finalMove.col] = 'O';
		}
	}
	else if (difficulty == "hard") {
		win();
		if (!alreadyWon) {
			block();
		}
		if (!validMoves.empty() && !alreadyMoved && !alreadyWon) {
			finalMove = validMoves[rand() % validMoves.size()]; 
			dasht[finalMove.row][finalMove.col] = 'O';
		}
	}

}
