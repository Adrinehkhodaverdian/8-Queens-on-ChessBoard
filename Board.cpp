/*
 lab4
 CS/IS211
 CodeCrash: Adrineh khodaverdian, Ervin Simonian
 */
#include <stdio.h>
#include "Board.h"
#include "Queen.h"
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

Board::Board()
{
    Queen::setBoard(this);
}
Board::~Board()
{
    clear();
}

bool Board::isQueen(int inRow, int inCol) const
{
    bool isItQueen=false;

    for(int i=0; i<getNumQueens(); i++)
    {
        if(queens[i]->getCol() == inCol && queens[i]->getRow() == inRow)
        {
            isItQueen = true;
        }
//        else
//        {
//            isItQueen=false;
//        }
    }
    return isItQueen;
}
bool Board::placeQueens(Queen* queenPtr)
{
    if (queenPtr->getCol()>= BOARD_SIZE){
        delete queenPtr;
        return true;
    } // end if
    bool isQueenSet = false;
    while (!isQueenSet && queenPtr->getRow() < BOARD_SIZE ){
        // If the queen can be attacked, try moving it
        // to the next row in the current column
        if (queenPtr->isUnderAttack())
            queenPtr->nextRow();
        else{
            // Put this queen on the board and try putting a
            // new queen in the first row of the next column
            setQueen(queenPtr);
            Queen* newQueenPtr = new Queen(0,queenPtr->getCol()+1);
            isQueenSet = placeQueens(newQueenPtr);
            if (!isQueenSet){
                delete newQueenPtr;
                removeQueen();
                queenPtr->nextRow();
            } // end if
            }

    } // end while
    return isQueenSet;
 }
void Board::doEightQueens(Queen q) {
    placeQueens(new Queen(q.getRow(),q.getCol()));
}

void Board::clear() {
    for (int i = 0; i < getNumQueens(); ++i) {
        delete (queens[i]);
        queens[i] = nullptr;
    }
}
void Board::removeQueen() {
    if (getNumQueens() != 0)
    {
        queens.pop_back();
    }
}
void Board::setQueen(Queen* queenPtr)
{
    queens.push_back(queenPtr);
}
void Board::display() const {

    cout << " ";
    for(int i = 0; i<BOARD_SIZE; i++)
    {
        cout << "  " << i   ;
    }
    cout << endl;
    for(int i = 0; i<BOARD_SIZE; i++)
    {
        cout << i  << " ";
        for(int j = 0; j<BOARD_SIZE; j++)
        {
            if(!isQueen(i,j))
            {
                cout << " * ";
            }
            else
            {
                cout << " Q ";
            }
        }
        cout<<endl;
    }
}
int Board::getNumQueens() const {
    return (int)queens.size();
}
const Queen* Board::getQueen(int index) const {
    return queens[index];
}

