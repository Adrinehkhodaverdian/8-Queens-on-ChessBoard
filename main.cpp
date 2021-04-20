/*
 lab4
 CS/IS211
 CodeCrash: Adrineh khodaverdian, Ervin Simonian
 
 */
#include <iostream>
#include "Queen.h"
#include "Board.h"
using namespace std;

int main() {

    Board board;

    Queen queen(1, 3);
    queen.setBoard(&board);
    board.doEightQueens(queen);
    board.display();
    board.clear();
    cout << endl;
    Board board1;

    Queen queen2(5,6);
    queen2.setBoard(&board1);
    board1.doEightQueens(queen2);
    board1.display();
    board1.clear();
    
    
    cout << endl;
    Board board2;
    Queen queen3(6 , 1);
    queen3.setBoard(&board2);
    board2.doEightQueens(queen3);
    board2.display();
    board2.clear();
    cout << endl;
     
     
    
    return 0;
}
