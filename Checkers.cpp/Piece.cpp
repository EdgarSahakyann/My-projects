#include "piece.h"


Piece::Piece(PieceType t) {
    type = t;
}

void Piece::makeQueen() {
    if (type == WHITE) {
        type = WHITE_QUEEN;
    }
    else if (type == BLUE) {
        type = BLUE_QUEEN;
    }
}

PieceType Piece::getType() const {
    return type;
}

void Piece::setType(PieceType newType) {
    type = newType;
}

char Piece::getSymbol() const {
    switch (type) {
    case WHITE: return 'w';
    case BLUE: return 'b';
    case WHITE_QUEEN: return 'W';
    case BLUE_QUEEN: return 'B';
    case EMPTY: return '.';
    }
}
