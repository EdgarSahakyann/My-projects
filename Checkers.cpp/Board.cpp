#include <iostream>
#include "board.h"
using namespace std;

Board::Board(int s) {
    size = s;
    _board = vector<vector<Piece>>(s, vector<Piece>(s));
}

int Board::getW_Count() {
    return w_count;
}

int Board::getB_Count() {
    return b_count;
}

void Board::initialize() {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if ((i + j) % 2 == 1 && i < 3) {
                _board[i][j] = WHITE;
            }
            else if ((i + j) % 2 == 1 && i > 4) {
                _board[i][j] = BLUE;
            }
        }
    }
}

void Board::show() {
    cout << "\033[34m" << "&" << "\033[0m" << " ";
    for (int i = 0; i < 8; ++i) {
        cout << "\033[31m" << i << "\033[0m" << " ";
    }
    cout << endl;
    for (int i = 0; i < 8; ++i) {
        cout << "\033[31m" << i << "\033[0m" << " ";
        for (int j = 0; j < 8; ++j) {
            if (_board[i][j].getSymbol() == '.') {
                cout << "\033[33m" << _board[i][j].getSymbol() << "\033[0m" << " ";
            }
            else if (_board[i][j].getSymbol() == 'b' || _board[i][j].getSymbol() == 'B') {
                cout << "\033[34m" << _board[i][j].getSymbol() << "\033[0m" << " ";
            }
            else {
                cout << _board[i][j].getSymbol() << " ";
            }
        }
        cout << endl;
    }
}

bool Board::IsInBounds(const Position& pos) const {
    return (pos.row >= 0 && pos.row < size && pos.col >= 0 && pos.col < size);
}

bool Board::IsValidMove(const Position& from, const Position& to, PieceType currentPlayer, PieceType currentQueen) {

    rowDiff = abs(from.row - to.row);
    colDiff = abs(from.col - to.col);

    if ((_board[from.row][from.col].getType() != WHITE_QUEEN) && (_board[from.row][from.col].getType() != BLUE_QUEEN)) {

        if (rowDiff == 2) {

            midRow = (from.row + to.row) / 2;
            midCol = (from.col + to.col) / 2;

            if (_board[midRow][midCol].getType() == EMPTY ||
                _board[midRow][midCol].getType() == currentPlayer) {
                return false;
            }
        }

        else {

            if (rowDiff != colDiff || rowDiff > 2) {
                return false;
            }

            if (_board[to.row][to.col].getType() != EMPTY) {
                return false;
            }

            if (_board[from.row][from.col].getType() != currentPlayer) {
                return false;
            }

            if (_board[from.row][from.col].getType() == WHITE) {
                if ((to.row - from.row < 0 && to.col - from.col > 0) || (to.row - from.row < 0 && to.col - from.col < 0)) {
                    return false;
                }
            }

            else if (_board[from.row][from.col].getType() == BLUE) {
                if ((to.row - from.row > 0 && to.col - from.col < 0) || (to.row - from.row > 0 && to.col - from.col > 0)) {
                    return false;
                }
            }
        }

    }

    else if ((_board[from.row][from.col].getType() == WHITE_QUEEN)) {

        if (rowDiff != colDiff) {
            return false;
        }

        if (_board[to.row][to.col].getType() != EMPTY) {
            return false;
        }

        if (_board[from.row][from.col].getType() != currentQueen) {
            return false;
        }


        if (to.row - from.row < 0 && to.col - from.col > 0) {

            for (int i = 1; i < rowDiff; ++i) {

                if (_board[from.row - i][from.col + i].getType() == WHITE) {
                    return false;
                    break;
                }

                else if (_board[from.row - i][from.col + i].getType() == BLUE && _board[from.row - i - 1][from.col + i + 1].getType() == EMPTY) {
                    b_count++;
                    _board[from.row - i][from.col + i].setType(EMPTY);
                }

                else if (_board[from.row - i][from.col + i].getType() == BLUE && _board[from.row - i - 1][from.col + i + 1].getType() == BLUE) {
                    return false;
                }

            }

        }

        else if (to.row - from.row > 0 && to.col - from.col > 0) {

            for (int i = 1; i < rowDiff; ++i) {

                if (_board[from.row + i][from.col + i].getType() == WHITE) {
                    return false;
                    break;
                }

                else if (_board[from.row + i][from.col + i].getType() == BLUE && _board[from.row + i + 1][from.col + i + 1].getType() == EMPTY) {
                    b_count++;
                    _board[from.row + i][from.col + i].setType(EMPTY);
                }

                else if (_board[from.row + i][from.col + i].getType() == BLUE && _board[from.row + i + 1][from.col + i + 1].getType() == BLUE) {
                    return false;
                }

            }

        }

        else if (to.row - from.row > 0 && to.col - from.col < 0) {

            for (int i = 1; i < rowDiff; ++i) {

                if (_board[from.row + i][from.col - i].getType() == WHITE) {
                    return false;
                    break;
                }

                else if (_board[from.row + i][from.col - i].getType() == BLUE && _board[from.row + i + 1][from.col - i - 1].getType() == EMPTY) {
                    b_count++;
                    _board[from.row + i][from.col - i].setType(EMPTY);
                }

                else if (_board[from.row + i][from.col - i].getType() == BLUE && _board[from.row + i + 1][from.col - i - 1].getType() == BLUE) {
                    return false;
                }

            }

        }

        else if (to.row - from.row < 0 && to.col - from.col < 0) {

            for (int i = 1; i < rowDiff; ++i) {

                if (_board[from.row - i][from.col - i].getType() == WHITE) {
                    return false;
                    break;
                }

                else if (_board[from.row - i][from.col - i].getType() == BLUE && _board[from.row - i - 1][from.col - i - 1].getType() == EMPTY) {
                    b_count++;
                    _board[from.row - i][from.col - i].setType(EMPTY);
                }

                else if (_board[from.row - i][from.col - i].getType() == BLUE && _board[from.row - i - 1][from.col - i - 1].getType() == BLUE) {
                    return false;
                }

            }

        }

    }

    else if (_board[from.row][from.col].getType() == BLUE_QUEEN) {

        if (rowDiff != colDiff) {
            return false;
        }

        if (_board[to.row][to.col].getType() != EMPTY) {
            return false;
        }

        if (_board[from.row][from.col].getType() != currentQueen) {
            return false;
        }


        if (to.row - from.row < 0 && to.col - from.col > 0) {

            for (int i = 1; i < rowDiff; ++i) {

                if (_board[from.row - i][from.col + i].getType() == BLUE) {
                    return false;
                    break;
                }

                else if (_board[from.row - i][from.col + i].getType() == WHITE && _board[from.row - i - 1][from.col + i + 1].getType() == EMPTY) {
                    w_count++;
                    _board[from.row - i][from.col + i].setType(EMPTY);
                }

                else if (_board[from.row - i][from.col + i].getType() == WHITE && _board[from.row - i - 1][from.col + i + 1].getType() == WHITE) {
                    return false;
                }

            }

        }

        else if (to.row - from.row > 0 && to.col - from.col > 0) {

            for (int i = 1; i < rowDiff; ++i) {

                if (_board[from.row + i][from.col + i].getType() == BLUE) {
                    return false;
                    break;
                }

                else if (_board[from.row + i][from.col + i].getType() == WHITE && _board[from.row + i + 1][from.col + i + 1].getType() == EMPTY) {
                    w_count++;
                    _board[from.row + i][from.col + i].setType(EMPTY);
                }

                else if (_board[from.row + i][from.col + i].getType() == WHITE && _board[from.row + i + 1][from.col + i + 1].getType() == WHITE) {
                    return false;
                }

            }

        }

        else if (to.row - from.row > 0 && to.col - from.col < 0) {

            for (int i = 1; i < rowDiff; ++i) {

                if (_board[from.row + i][from.col - i].getType() == BLUE) {
                    return false;
                    break;
                }

                else if (_board[from.row + i][from.col - i].getType() == WHITE && _board[from.row + i + 1][from.col - i - 1].getType() == EMPTY) {
                    w_count++;
                    _board[from.row + i][from.col - i].setType(EMPTY);
                }

                else if (_board[from.row + i][from.col - i].getType() == WHITE && _board[from.row + i + 1][from.col - i - 1].getType() == WHITE) {
                    return false;
                }

            }

        }

        else if (to.row - from.row < 0 && to.col - from.col < 0) {

            for (int i = 1; i < rowDiff; ++i) {

                if (_board[from.row - i][from.col - i].getType() == BLUE) {
                    return false;
                    break;
                }

                else if (_board[from.row - i][from.col - i].getType() == WHITE && _board[from.row - i - 1][from.col - i - 1].getType() == EMPTY) {
                    w_count++;
                    _board[from.row - i][from.col - i].setType(EMPTY);
                }

                else if (_board[from.row - i][from.col - i].getType() == WHITE && _board[from.row - i - 1][from.col - i - 1].getType() == WHITE) {
                    return false;
                }

            }

        }

    }

    return true;
}
