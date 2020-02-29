#include <iostream>
#include <conio.h>

#include "boardClass.h"
#include "handler.h";
/*
int main()
{
    std::vector<std::vector<int>> *board = new std::vector<std::vector<int>>(4, std::vector<int>(4, 0));
    init(*board);
    printBoard(*board);
    while (1)
    {
        system("pause");
        switch (getchar()) {
        case('w'): {
            //printBoard(*board);
            std::vector<std::vector<int>>* check = new std::vector<std::vector<int>>(4, std::vector<int>(4, 0));
            copyBoard(*board,*check);
            upSlide(*board);
            if (!cmpBoard(*check,*board))
            {
                createRand(*board);
                delete check;
            }
            else {
                std::cout << "can't slide" << std::endl;
            }
            printBoard(*board);
            break;
        }
        case('a'): {
            //printBoard(*board);
            std::vector<std::vector<int>>* check = new std::vector<std::vector<int>>(4, std::vector<int>(4, 0));
            copyBoard(*board, *check);
            leftSlide(*board);
            if (!cmpBoard(*check, *board))
            {
                createRand(*board);
                delete check;
            }
            else {
                std::cout << "can't slide" << std::endl;
            }
            printBoard(*board);
            break;
        }
        case('s'): {
            //printBoard(*board);
            std::vector<std::vector<int>>* check = new std::vector<std::vector<int>>(4, std::vector<int>(4, 0));
            copyBoard(*board, *check);
            downSlide(*board);
            if (!cmpBoard(*check, *board))
            {
                createRand(*board);
                delete check;
            }
            else {
                std::cout << "can't slide" << std::endl;
            }
            printBoard(*board);
            break;
        }
        case('d'): {
            //printBoard(*board);
            std::vector<std::vector<int>>* check = new std::vector<std::vector<int>>(4, std::vector<int>(4, 0));
            copyBoard(*board, *check);
            rightSlide(*board);
            if (!cmpBoard(*check, *board))
            {
                createRand(*board);
                delete check;
            }
            else {
                std::cout << "can't slide" << std::endl;
            }
            printBoard(*board);
            break;
        }
        }
    }
    system("pause");
}
*/
int main() {
    Board *board = new Board();
    std::vector<std::vector<int>> check(4, std::vector<int>(4, 0));
    board->printBoard();
    board->initBoard();
    board->printBoard();
    while (1) {
        system("pause");
        switch (getchar()) {
        case('w'): {
            board->copyBoard(check);
            board->upSlide();
            if (!board->checkBoard(check)) board->randBoard();
            else std::cout << "can't slide" << std::endl;
            board->printBoard();
            break;
        }
        case('a'): {
            board->copyBoard(check);
            board->leftSlide();
            if (!board->checkBoard(check)) board->randBoard();
            else std::cout << "can't slide" << std::endl;
            board->printBoard();
            break;
        }
        case('s'): {
            board->copyBoard(check);
            board->downSlide();
            if (!board->checkBoard(check)) board->randBoard();
            else std::cout << "can't slide" << std::endl;
            board->printBoard();
            break;
        }
        case('d'): {
            board->copyBoard(check);
            board->rightSlide();
            if (!board->checkBoard(check)) board->randBoard();
            else std::cout << "can't slide" << std::endl;
            board->printBoard();
            break;
        }
    }
    }
}