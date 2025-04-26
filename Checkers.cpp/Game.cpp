#include "Game.h"
#include <iostream>

void Game::set_coord(const Position& to) {
    coord_r = to.row;
    coord_c = to.col;
}

int Game::get_coord_r() const {
    return coord_r;
}

int Game::get_coord_c() const {
    return coord_c;
}

bool Game::WillEat(const Position& from, const Position& to) {
    if (to.row - from.row > 1 || to.row - from.row < -1) {
        return true;
    }
    return false;
}

bool Game::WhiteCanEat() {
    for (int i = size - 1; i >= 0; --i) {
        for (int j = size - 1; j >= 0; --j) {
            if (_board[i][j].getType() == WHITE) {
                if ((IsInBounds(Position(i + 2, j + 2)) && _board[i + 1][j + 1].getType() == BLUE && _board[i + 2][j + 2].getType() == EMPTY) ||
                    (IsInBounds(Position(i + 2, j - 2)) && _board[i + 1][j - 1].getType() == BLUE && _board[i + 2][j - 2].getType() == EMPTY) ||
                    (IsInBounds(Position(i - 2, j + 2)) && _board[i - 1][j + 1].getType() == BLUE && _board[i - 2][j + 2].getType() == EMPTY) ||
                    (IsInBounds(Position(i - 2, j - 2)) && _board[i - 1][j - 1].getType() == BLUE && _board[i - 2][j - 2].getType() == EMPTY)) {
                    return true;
                }
            }
        }
    }
    return false;
}

bool Game::BlueCanEat() {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (_board[i][j].getType() == BLUE) {
                if ((IsInBounds(Position(i + 2, j + 2)) && _board[i + 1][j + 1].getType() == WHITE && _board[i + 2][j + 2].getType() == EMPTY) ||
                    (IsInBounds(Position(i + 2, j - 2)) && _board[i + 1][j - 1].getType() == WHITE && _board[i + 2][j - 2].getType() == EMPTY) ||
                    (IsInBounds(Position(i - 2, j + 2)) && _board[i - 1][j + 1].getType() == WHITE && _board[i - 2][j + 2].getType() == EMPTY) ||
                    (IsInBounds(Position(i - 2, j - 2)) && _board[i - 1][j - 1].getType() == WHITE && _board[i - 2][j - 2].getType() == EMPTY)) {
                    return true;
                }
            }
        }
    }
    return false;
}

bool Game::WhiteQueenCanEat() {
    int k;
    for (int i = size - 1; i >= 0; --i) {
        for (int j = size - 1; j >= 0; --j) {

            if (_board[i][j].getType() == WHITE_QUEEN) {
                k = 1;

                while (IsInBounds(Position(i + k + 1, j + k + 1))) {
                    if (k == 1) {
                        if (_board[i + k][j + k].getType() == BLUE && _board[i + k + 1][j + k + 1].getType() == EMPTY) {
                            return true;
                        }
                    }
                    else {
                        if (_board[i + k][j + k].getType() == BLUE && _board[i + k + 1][j + k + 1].getType() == EMPTY &&
                            _board[i + k - 1][j + k - 1].getType() == EMPTY) {
                            return true;
                        }
                    }
                    k++;
                }
                k = 1;

                while (IsInBounds(Position(i + k + 1, j - k - 1))) {
                    if (k == 1) {
                        if (_board[i + k][j - k].getType() == BLUE && _board[i + k + 1][j - k - 1].getType() == EMPTY) {
                            return true;
                        }
                    }
                    else {
                        if (_board[i + k][j - k].getType() == BLUE && _board[i + k + 1][j - k - 1].getType() == EMPTY &&
                            _board[i + k - 1][j - k + 1].getType() == EMPTY) {
                            return true;
                        }
                    }
                    k++;
                }
                k = 1;

                while (IsInBounds(Position(i - k - 1, j + k + 1))) {
                    if (k == 1) {
                        if (_board[i - k][j + k].getType() == BLUE && _board[i - k - 1][j + k + 1].getType() == EMPTY) {
                            return true;
                        }
                    }
                    else {
                        if (_board[i - k][j + k].getType() == BLUE && _board[i - k - 1][j + k + 1].getType() == EMPTY &&
                            _board[i - k + 1][j + k - 1].getType() == EMPTY) {
                            return true;
                        }
                    }
                    k++;
                }
                k = 1;

                while (IsInBounds(Position(i - k - 1, j - k - 1))) {
                    if (k == 1) {
                        if (_board[i - k][j - k].getType() == BLUE && _board[i - k - 1][j - k - 1].getType() == EMPTY) {
                            return true;
                        }
                    }
                    else {
                        if (_board[i - k][j - k].getType() == BLUE && _board[i - k - 1][j - k - 1].getType() == EMPTY &&
                            _board[i - k + 1][j - k + 1].getType() == EMPTY) {
                            return true;
                        }
                    }
                    k++;
                }

            }

        }
    }
    return false;
}

bool Game::BlueQueenCanEat() {
    int k;
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {

            if (_board[i][j].getType() == BLUE_QUEEN) {
                k = 1;

                while (IsInBounds(Position(i + k + 1, j + k + 1))) {
                    if (k == 1) {
                        if (_board[i + k][j + k].getType() == WHITE && _board[i + k + 1][j + k + 1].getType() == EMPTY) {
                            return true;
                        }
                    }
                    else {
                        if (_board[i + k][j + k].getType() == WHITE && _board[i + k + 1][j + k + 1].getType() == EMPTY &&
                            _board[i + k - 1][j + k - 1].getType() == EMPTY) {
                            return true;
                        }
                    }
                    k++;
                }
                k = 1;

                while (IsInBounds(Position(i + k + 1, j - k - 1))) {
                    if (k == 1) {
                        if (_board[i + k][j - k].getType() == WHITE && _board[i + k + 1][j - k - 1].getType() == EMPTY) {
                            return true;
                        }
                    }
                    else {
                        if (_board[i + k][j - k].getType() == WHITE && _board[i + k + 1][j - k - 1].getType() == EMPTY &&
                            _board[i + k - 1][j - k + 1].getType() == EMPTY) {
                            return true;
                        }
                    }
                    k++;
                }
                k = 1;

                while (IsInBounds(Position(i - k - 1, j + k + 1))) {
                    if (k == 1) {
                        if (_board[i - k][j + k].getType() == WHITE && _board[i - k - 1][j + k + 1].getType() == EMPTY) {
                            return true;
                        }
                    }
                    else {
                        if (_board[i - k][j + k].getType() == WHITE && _board[i - k - 1][j + k + 1].getType() == EMPTY &&
                            _board[i - k + 1][j + k - 1].getType() == EMPTY) {
                            return true;
                        }
                    }
                    k++;
                }
                k = 1;

                while (IsInBounds(Position(i - k - 1, j - k - 1))) {
                    if (k == 1) {
                        if (_board[i - k][j - k].getType() == WHITE && _board[i - k - 1][j - k - 1].getType() == EMPTY) {
                            return true;
                        }
                    }
                    else {
                        if (_board[i - k][j - k].getType() == WHITE && _board[i - k - 1][j - k - 1].getType() == EMPTY &&
                            _board[i - k + 1][j - k + 1].getType() == EMPTY) {
                            return true;
                        }
                    }
                    k++;
                }

            }

        }
    }
    return false;
}

bool Game::HasEaten(const Position& from, const Position& to) {
    if (to.row - from.row > 1 || to.row - from.row < -1) {
        return true;
    }
    return false;
}



void Game::WhiteIsFuk(const Position& to) {
    for (int i = size - 1; i >= 0; --i) {
        for (int j = size - 1; j >= 0; --j) {

            if (_board[i][j].getType() == WHITE) {
                if ((IsInBounds(Position(i + 2, j + 2)) && _board[i + 1][j + 1].getType() == BLUE && _board[i + 2][j + 2].getType() == EMPTY) ||
                    (IsInBounds(Position(i + 2, j - 2)) && _board[i + 1][j - 1].getType() == BLUE && _board[i + 2][j - 2].getType() == EMPTY) ||
                    (IsInBounds(Position(i - 2, j + 2)) && _board[i - 1][j + 1].getType() == BLUE && _board[i - 2][j + 2].getType() == EMPTY) ||
                    (IsInBounds(Position(i - 2, j - 2)) && _board[i - 1][j - 1].getType() == BLUE && _board[i - 2][j - 2].getType() == EMPTY) ||
                    (IsInBounds(Position(i + 2, j + 2)) && _board[i + 1][j + 1].getType() == BLUE_QUEEN && _board[i + 2][j + 2].getType() == EMPTY) || 
                    (IsInBounds(Position(i + 2, j - 2)) && _board[i + 1][j - 1].getType() == BLUE_QUEEN && _board[i + 2][j - 2].getType() == EMPTY) || 
                    (IsInBounds(Position(i - 2, j + 2)) && _board[i - 1][j + 1].getType() == BLUE_QUEEN && _board[i - 2][j + 2].getType() == EMPTY) || 
                    (IsInBounds(Position(i - 2, j - 2)) && _board[i - 1][j - 1].getType() == BLUE_QUEEN && _board[i - 2][j - 2].getType() == EMPTY) ) {
                    if (i != to.row || j != to.col) {
                        _board[i][j].setType(EMPTY);
                        w_count++;
                    }

                    return;
                }
            }

        }
    }
}

void Game::BlueIsFuk(const Position& to) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {

            if (_board[i][j].getType() == BLUE) {
                if ((IsInBounds(Position(i + 2, j + 2)) && _board[i + 1][j + 1].getType() == WHITE && _board[i + 2][j + 2].getType() == EMPTY) ||
                    (IsInBounds(Position(i + 2, j - 2)) && _board[i + 1][j - 1].getType() == WHITE && _board[i + 2][j - 2].getType() == EMPTY) ||
                    (IsInBounds(Position(i - 2, j + 2)) && _board[i - 1][j + 1].getType() == WHITE && _board[i - 2][j + 2].getType() == EMPTY) ||
                    (IsInBounds(Position(i - 2, j - 2)) && _board[i - 1][j - 1].getType() == WHITE && _board[i - 2][j - 2].getType() == EMPTY) ||
                    (IsInBounds(Position(i + 2, j + 2)) && _board[i + 1][j + 1].getType() == WHITE_QUEEN && _board[i + 2][j + 2].getType() == EMPTY) || 
                    (IsInBounds(Position(i + 2, j - 2)) && _board[i + 1][j - 1].getType() == WHITE_QUEEN && _board[i + 2][j - 2].getType() == EMPTY) || 
                    (IsInBounds(Position(i - 2, j + 2)) && _board[i - 1][j + 1].getType() == WHITE_QUEEN && _board[i - 2][j + 2].getType() == EMPTY) || 
                    (IsInBounds(Position(i - 2, j - 2)) && _board[i - 1][j - 1].getType() == WHITE_QUEEN && _board[i - 2][j - 2].getType() == EMPTY) ) {
                    if (i != to.row || j != to.col) {
                        _board[i][j].setType(EMPTY);
                        b_count++;
                    }

                    return;
                }
            }

        }
    }
}

void Game::WhiteQueenIsFuk(const Position& to) {
    int k;
    for (int i = size - 1; i >= 0; --i) {
        for (int j = size - 1; j >= 0; --j) {

            if (_board[i][j].getType() == WHITE_QUEEN) {
                k = 1;
                while (IsInBounds(Position(i + k + 1, j + k + 1))) {
                    if (_board[i + k][j + k].getType() == BLUE && _board[i + k - 1][j + k - 1].getType() == EMPTY &&
                        _board[i + k + 1][j + k + 1].getType() == EMPTY ||
                        _board[i + k][j + k].getType() == BLUE_QUEEN && _board[i + k + 1][j + k + 1].getType() == EMPTY && 
                        _board[i + k - 1][j + k - 1].getType() == EMPTY) {
                        if (i != to.row || j != to.col) {
                            _board[i][j].setType(EMPTY);
                            w_count++;
                            return;
                        }
                    }
                    k++;
                }
                k = 1;
                while (IsInBounds(Position(i + k + 1, j - k - 1))) {
                    if (_board[i + k][j - k].getType() == BLUE && _board[i + k - 1][j - k + 1].getType() == EMPTY &&
                        _board[i + k + 1][j - k - 1].getType() == EMPTY ||
                        _board[i + k][j - k].getType() == BLUE_QUEEN && _board[i + k - 1][j - k + 1].getType() == EMPTY &&
                        _board[i + k + 1][j - k - 1].getType() == EMPTY) {
                        if (i != to.row || j != to.col) {
                            _board[i][j].setType(EMPTY);
                            w_count++;
                            return;
                        }
                    }
                    k++;
                }
                k = 1;
                while (IsInBounds(Position(i - k - 1, j + k + 1))) {
                    if (_board[i - k][j + k].getType() == BLUE && _board[i - k + 1][j + k - 1].getType() == EMPTY &&
                        _board[i - k - 1][j + k + 1].getType() == EMPTY ||
                        _board[i - k][j + k].getType() == BLUE_QUEEN && _board[i - k + 1][j + k - 1].getType() == EMPTY &&
                        _board[i - k - 1][j + k + 1].getType() == EMPTY) {
                        if (i != to.row || j != to.col) {
                            _board[i][j].setType(EMPTY);
                            w_count++;
                            return;
                        }
                    }
                    k++;
                }
                k = 1;
                while (IsInBounds(Position(i - k - 1, j - k - 1))) {
                    if (_board[i - k][j - k].getType() == BLUE && _board[i - k + 1][j - k + 1].getType() == EMPTY && 
                        _board[i - k - 1][j - k - 1].getType() == EMPTY ||
                        _board[i - k][j - k].getType() == BLUE_QUEEN && _board[i - k + 1][j - k + 1].getType() == EMPTY &&
                        _board[i - k - 1][j - k - 1].getType() == EMPTY) {
                        if (i != to.row || j != to.col) {
                            _board[i][j].setType(EMPTY);
                            w_count++;
                            return;
                        }
                    }
                    k++;
                }
            }
        }
    }
}

void Game::BlueQueenIsFuk(const Position& to) {
    int k;
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {

            if (_board[i][j].getType() == BLUE_QUEEN) {
                k = 1;
                while (IsInBounds(Position(i + k + 1, j + k + 1))) {
                    if (_board[i + k][j + k].getType() == WHITE && _board[i + k - 1][j + k - 1].getType() == EMPTY && 
                        _board[i + k + 1][j + k + 1].getType() == EMPTY ||
                        _board[i + k][j + k].getType() == WHITE_QUEEN && _board[i + k - 1][j + k - 1].getType() == EMPTY &&
                        _board[i + k + 1][j + k + 1].getType() == EMPTY) {
                        if (i != to.row || j != to.col) {
                            _board[i][j].setType(EMPTY);
                            b_count++;
                            return;
                        }
                    }
                    k++;
                }
                k = 1;
                while (IsInBounds(Position(i + k + 1, j - k - 1))) {
                    if (_board[i + k][j - k].getType() == WHITE && _board[i + k - 1][j - k + 1].getType() == EMPTY && 
                        _board[i + k + 1][j - k - 1].getType() == EMPTY ||
                        _board[i + k][j - k].getType() == WHITE_QUEEN && _board[i + k - 1][j - k + 1].getType() == EMPTY && 
                        _board[i + k + 1][j - k - 1].getType() == EMPTY) {
                        if (i != to.row || j != to.col) {
                            _board[i][j].setType(EMPTY);
                            b_count++;
                            return;
                        }
                    }
                    k++;
                }
                k = 1;
                while (IsInBounds(Position(i - k - 1, j + k + 1))) {
                    if (_board[i - k][j + k].getType() == WHITE && _board[i - k + 1][j + k - 1].getType() == EMPTY &&
                        _board[i - k - 1][j + k + 1].getType() == EMPTY ||
                        _board[i - k][j + k].getType() == WHITE_QUEEN && _board[i - k + 1][j + k - 1].getType() == EMPTY &&
                        _board[i - k - 1][j + k + 1].getType() == EMPTY) {
                        if (i != to.row || j != to.col) {
                            _board[i][j].setType(EMPTY);
                            b_count++;
                            return;
                        }
                    }
                    k++;
                }
                k = 1;
                while (IsInBounds(Position(i - k - 1, j - k - 1))) {
                    if (_board[i - k][j - k].getType() == WHITE && _board[i - k + 1][j - k + 1].getType() == EMPTY &&
                        _board[i - k - 1][j - k - 1].getType() == EMPTY ||
                        _board[i - k][j - k].getType() == WHITE_QUEEN && _board[i - k + 1][j - k + 1].getType() == EMPTY &&
                        _board[i - k - 1][j - k - 1].getType() == EMPTY) {
                        if (i != to.row || j != to.col) {
                            _board[i][j].setType(EMPTY);
                            b_count++;
                            return;
                        }
                    }
                    k++;
                }
            }
        }
    }
}

void Game::move(const Position& from, const Position& to) {

    if (IsInBounds(from) && IsInBounds(to)) {

        if ((to.row == 0 && _board[from.row][from.col].getType() == BLUE) || (to.row == 7 && _board[from.row][from.col].getType() == WHITE)) {
            _board[from.row][from.col].makeQueen();
        }

        _board[to.row][to.col] = _board[from.row][from.col];
        _board[from.row][from.col] = EMPTY;

        if (rowDiff == 2) {

            if (_board[midRow][midCol].getType() == WHITE || _board[midRow][midCol].getType() == WHITE_QUEEN) {
                w_count++;
            }

            else if (_board[midRow][midCol].getType() == BLUE || _board[midRow][midCol].getType() == BLUE_QUEEN) {
                b_count++;
            }

            _board[midRow][midCol].setType(EMPTY);

        }

    }

}
