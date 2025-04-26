#pragma once
#include "Board.h"
#include <iostream>
#include <string>


class Game : public Board {

private:
	bool alreadyMoved, alreadyWon;
	Position cursor;
	string name1, name2;
	char currentPlayer;

public:
	Game(string player1, string player2);
	void move(Position to, int& cnt);
	void switchPlayers();
	bool XWon();
	bool OWon();
	bool gameOver();
	bool validMove(Position to);
	char getCurrentPlayer();
	Position getCursor();
	void updateCursor(int ch);
	void block();
	void win();
	void compMove(string difficulty, int& cnt);

};
