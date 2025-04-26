#pragma once
#include "piecetype.cpp"

class Player {

private:
    PieceType currentPlayer, currentQueen;

public:
    Player();
    void switchPlayers();
    PieceType getCurrentPlayer();
    PieceType getCurrentQueen();
};
