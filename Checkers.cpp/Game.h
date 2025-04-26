#pragma once
#include "Board.h"
using namespace std;

class Game : public Board {
    
    int coord_r, coord_c;

public:
    void set_coord(const Position& to);
    int get_coord_r() const;
    int get_coord_c() const;

    bool WillEat(const Position& from, const Position& to);
    bool WhiteCanEat();
    bool BlueCanEat();
    bool WhiteQueenCanEat();
    bool BlueQueenCanEat();
    bool HasEaten(const Position& from, const Position& to);

    void WhiteIsFuk(const Position& to);
    void BlueIsFuk(const Position& to);
    void WhiteQueenIsFuk(const Position& to);
    void BlueQueenIsFuk(const Position& to);
    void move(const Position& from, const Position& to);
};
