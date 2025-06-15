#include "Game.h"
#include <conio.h>

int main() {
	int count = 0;
	string mode, name, diff, name1, name2;

	cout << "Single Player or Multiplayer (Type 's' or 'm')." << endl; cin >> mode;

	if (mode == "m") {

		cout << "Enter name of first player: "; cin >> name1;
		cout << "Enter name of second player: "; cin >> name2;

		Game game(name1, name2);

		game.initBoard();
		game.showBoard(game.getCursor());

		cout << "It's " << name1 << "'s turn!" << endl;

		while (true) {

			if (game.XWon()) {
				cout << endl << "\033[31m" << name1 << " Won!\033[0m" << endl;
				break;
			}
			else if (game.OWon()) {
				cout << endl << "\033[34m" << name2 << " Won!\033[0m" << endl;
				break;
			}
			else if (count == 9) {
				cout << endl << "\033[32m" << "It is a draw!" << "\033[0m" << endl;
				break;
			}

			int ch = _getch();
			system("cls");

			if (ch == 13) {
				Position cursor = game.getCursor();

				if (game.validMove(cursor)) {
					game.move(cursor, count);
					game.showBoard(cursor);
					game.switchPlayers();
				}
				else {
					game.showBoard(game.getCursor());

					cout << "Unvalid move, try again!" << endl;

					if (game.getCurrentPlayer() == 'X') {
						cout << "It's " << name1 << "'s turn. " << endl;
					}
					else if (game.getCurrentPlayer() == 'O') {
						cout << "It's " << name2 << "'s turn. " << endl;
					}

				}

			}
			else {
				game.updateCursor(ch);
				game.showBoard(game.getCursor());

				if (game.getCurrentPlayer() == 'X') {
					cout << "It's " << name1 << "'s turn.";
				}
				else if (game.getCurrentPlayer() == 'O') {
					cout << "It's " << name2 << "'s turn.";
				}

			}

		}

	}

	else if (mode == "s") {

		cout << "Choose difficulty (easy, medium or hard): " << endl; cin >> diff;

		while (diff != "easy" || diff != "medium" || diff != "hard") {
			if (diff == "easy" || diff == "medium" || diff == "hard") {
				break;
			}
			cout << "Type 'easy', 'medium' or 'hard'." << endl;
			cin >> diff;
		}


		Game game(name1, name2);

		game.initBoard();
		game.showBoard(game.getCursor());

		while (true) {

			if (game.XWon()) {
				cout << endl << "\033[31mYou Won!\033[0m" << endl;
				break;
			}
			else if (game.OWon()) {
				cout << endl << "\033[34mComputer Won!\033[0m" << endl;
				break;
			}
			else if (count == 10) {
				cout << endl << "\033[32m" << "It is a draw!" << "\033[0m" << endl;
				break;
			}

			int ch = _getch();
			system("cls");

			if (ch == 13) {
				Position cursor = game.getCursor();

				if (game.validMove(cursor)) {
					game.move(cursor, count);
					game.compMove(diff, count);
					game.showBoard(cursor);
					cout << "It's your turn." << endl;
				}
				else {
					game.showBoard(game.getCursor());
					cout << "Unvalid move, try again!" << endl << "It's your turn." << endl;
				}

			}
			else {
				game.updateCursor(ch);
				game.showBoard(game.getCursor());
				cout << "It's your turn." << endl;
			}

		}

	}

	else {
		cout << "Type 'Multiplayer' or 'Single Player'." << endl;
	}

	return 0;

}
