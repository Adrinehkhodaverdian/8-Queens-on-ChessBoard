/*
 lab4
 CS/IS211
 CodeCrash: Adrineh khodaverdian, Ervin Simonian
 */

//Board.h
#ifndef _BOARD
#define _BOARD
#include "Queen.h"
#include <vector>
#include <cassert>
#include <iostream>
using namespace std;

static const int BOARD_SIZE = 8;

class Board {

private:
    vector<Queen*> queens;
    bool isQueen(int inRow, int inCol) const ;
    bool placeQueens(Queen* queenPtr);


public:
    Board();
    ~Board();
    void clear();
    void display() const;
    void doEightQueens(Queen q);
    int getNumQueens() const;
    void removeQueen();
    void setQueen(Queen* queenPtr);
    const Queen* getQueen(int index) const;
};
#endif
