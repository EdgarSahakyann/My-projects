#pragma once
#include <vector>
#include "piece.h"
#include "position.h"
using namespace std;


class Board {

protected:
    int w_count = 0;
    int b_count = 0;
    int rowDiff, colDiff, midRow, midCol;
    int size;
    vector<vector<Piece>> _board;

public:
    Board(int s = 8);
    int getW_Count();
    int getB_Count();
    void initialize();
    void show();
    bool IsInBounds(const Position& pos) const;
    bool IsValidMove(const Position& from, const Position& to, PieceType currentPlayer, PieceType currentQueen);
};
