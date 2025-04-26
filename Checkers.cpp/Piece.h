#pragma once
#include "piecetype.cpp"

class Piece {

private:
    PieceType type;

public:

    Piece(PieceType t = EMPTY);

    void makeQueen();
    PieceType getType() const;
    void setType(PieceType newType);
    char getSymbol() const;
};
