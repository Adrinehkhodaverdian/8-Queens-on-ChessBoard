/*
 lab4
 CS/IS211
 CodeCrash: Adrineh khodaverdian, Ervin Simonian
 */
//Queen.cpp
#include "Queen.h"
#include "Board.h"
#include <iostream>
using namespace std;

const Board* Queen::boardPtr;

Queen::Queen() : row(0), column(0){
}
Queen::Queen(int inRow, int inCol) : row(inRow), column(inCol){
//    setRow(inRow);
//    setCol(inCol);
}
Queen::~Queen() {
}
void Queen::setRow(int r){
    row = r >0 && r < 9? r: 0;
}
void Queen::setCol(int c){
    column = c >0 && c < 9? c : 0;
}
int Queen::getCol() const {
    return column;
}

int Queen::getRow() const {
    return row;
}
void Queen::nextRow() {
    ++row;
}
bool Queen::isUnderAttack() const {
    for (int i = 0; i < boardPtr->getNumQueens(); i++){
        const Queen* q = boardPtr->getQueen(i);
        
        if (q->getCol() == column || q->getRow() == row || q->getRow()-q->getCol() == row-column || q->getRow()+q->getCol() == row + column){
            return true;
        }
    }
    return false;
}
void Queen::setBoard(const Board* bPtr) {
    boardPtr = bPtr;
}
