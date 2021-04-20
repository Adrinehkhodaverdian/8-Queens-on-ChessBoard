/*
 lab4
 CS/IS211
 CodeCrash: Adrineh khodaverdian, Ervin Simonian
 
 */


#ifndef Queen_h
#define Queen_h
#include <string>
#include <algorithm>
#include <vector>

class Board;
class Queen
{
    private:
    int row; // Row (or prospective row) of queen if it is on the board
    int column; // Column (or prospective column) of queen if it is on
    // the board
    // All queens share the same board
    static const Board* boardPtr;
    public:
    /** Places a queen in upper-left corner of board. */
    Queen();/** Places a queen in supplied location. */
    ~Queen();
    Queen( int inRow, int inCol);
    void setRow(int r);
    void setCol(int c);
    /** @return Column number. */
    int getCol() const;
    /** @return Row number. */
    int getRow() const;
    /** Moves queen to next row. */
    void nextRow();
    /** Sees whether the queen is under attack by another queen.
    @return True if another queen is in the same row or the same
    diagonal; otherwise, returns false. */
    bool isUnderAttack() const;
    /** Saves a pointer to the board for all queens. */
    static void setBoard( const Board* bPtr);
    

}; // end Queen
#endif /* Queen_h */



