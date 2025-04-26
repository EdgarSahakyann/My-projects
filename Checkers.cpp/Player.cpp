#include <iostream>
#include "Player.h"
using namespace std;

Player::Player() {
    currentPlayer = WHITE, currentQueen = WHITE_QUEEN;
}

void Player::switchPlayers() {
    if (currentPlayer == WHITE) {
        currentPlayer = BLUE;
        currentQueen = BLUE_QUEEN;
        cout << endl << "It's Blue's turn." << endl;
    }
    else if (currentPlayer == BLUE) {
        currentPlayer = WHITE;
        currentQueen = WHITE_QUEEN;
        cout << endl << "It's White's turn." << endl;
    }
}

PieceType Player::getCurrentPlayer() {
    return currentPlayer;
}

PieceType Player::getCurrentQueen() {
    return currentQueen;
}
