#include <vector>
#include <cstdlib>
#include <iostream>

#include "boardClass.h"

Board::Board(){

}
void Board::initBoard() {
	int row, col;
	for (int i = 0;i < 4;i++)
	{
		row = rand() % 4;
		col = rand() % 4;
		if (boardNum[row][col]) i--;
		else boardNum[row][col] = numSerial[rand() % 3];
	}
}
void Board::printBoard(){
	for (int row = 0;row < boardNum.size();row++)
	{
		for (int col = 0;col < boardNum.size();col++)
		{
			std::cout << boardNum[row][col] << ' ';
		}
		std::cout << std::endl;
	}
}
void Board::upSlide() {
    for (int row = 1;row <= 3;row++) {//上滑
        for (int col = 0;col <= 3;col++)//合并
        {
            if (boardNum[row][col] == boardNum[row - 1][col])
            {
                boardNum[row - 1][col] *= 2;
                boardNum[row][col] = 0;
                boardNum[row - 1][col] = boardNum[row - 1][col];
            }
            else boardNum[row][col] = boardNum[row][col];
        }
    }
    int k = 0;
    for (int row = 1;row < boardNum.size();row++) {//移动
        for (int col = 0;col < boardNum.size();col++) {
            if (boardNum[row][col]) {
                k = row;
                while (k >= 1 && boardNum[k - 1][col] == 0) {
                    std::swap(boardNum[k][col], boardNum[k - 1][col]);
                    k--;
                }
                k = 0;
            }
            else continue;
        }
    }
    return;
}
void Board::downSlide() {
    for (int row = 2;row >= 0;row--) {//合并
        for (int col = 0;col <= 3;col++)
        {
            if (boardNum[row][col] == boardNum[row + 1][col])
            {
                boardNum[row + 1][col] *= 2;
                boardNum[row][col] = 0;
            }
            else boardNum[row][col] = boardNum[row][col];
        }
    }
    int k = 0;
    for (int row = 2;row >= 0;row--) {//移动
        for (int col = 0;col < boardNum.size();col++) {
            if (boardNum[row][col]) {
                k = row;
                while (k <= 2 && boardNum[k + 1][col] == 0) {
                    std::swap(boardNum[k][col], boardNum[k + 1][col]);
                    k++;
                }
                k = 0;
            }
            else continue;
        }
    }
    return;
}
void Board::leftSlide() {
    for (int col = 1;col <= 3;col++) {//合并
        for (int row = 0;row <= 3;row++)
        {
            if (boardNum[row][col] == boardNum[row][col - 1])
            {
                boardNum[row][col - 1] *= 2;
                boardNum[row][col] = 0;
            }
            else boardNum[row][col] = boardNum[row][col];
        }
    }
    int k = 0;
    for (int col = 1;col < boardNum.size();col++) {//移动
        for (int row = 0;row < boardNum.size();row++) {
            if (boardNum[row][col]) {
                k = col;
                while (k >= 1 && boardNum[row][k - 1] == 0) {
                    std::swap(boardNum[row][k], boardNum[row][k - 1]);
                    k--;
                }
                k = 0;
            }
            else continue;
        }
    }
    return;
}
void Board::rightSlide() {
    for (int col = 2;col >= 0;col--) {//合并
        for (int row = 0;row <= 3;row++)
        {
            if (boardNum[row][col] == boardNum[row][col + 1])
            {
                boardNum[row][col + 1] *= 2;
                boardNum[row][col] = 0;
            }
            else boardNum[row][col] = boardNum[row][col];
        }
    }
    int k = 0;
    for (int col = 2;col >= 0;col--) {//移动
        for (int row = 0;row < boardNum.size();row++) {
            if (boardNum[row][col]) {
                k = col;
                while (k <= 2 && boardNum[row][k + 1] == 0) {
                    std::swap(boardNum[row][k], boardNum[row][k + 1]);
                    k++;
                }
                k = 0;
            }
            else continue;
        }
    }
    return;
}
bool Board::checkBoard(std::vector<std::vector<int>> check) {
    for (int row = 0;row <= 3;row++) {
        for (int col = 0;col <= 3;col++) {
            if (boardNum[row][col] == check[row][col]) continue;
            else return false;
        }
    }
    return true;
};
void Board::copyBoard(std::vector<std::vector<int>> &copy) {
    for (int row = 0;row <= 3;row++) {
        for (int col = 0;col <= 3;col++) copy[row][col] = boardNum[row][col];
    }
};
void Board::randBoard() {
    int row, col;
    while (1) {
        row = rand() % 4;
        col = rand() % 4;
        if (boardNum[row][col]) continue;
        else {
            boardNum[row][col] = numSerial[rand() % 3];
            return;
        }
    }
}