#ifndef BOARD_H
#define BOARD_H
#include <vector>
class Board {
private:
	std::vector<std::vector<int>> boardNum = { {0,0,0,0}, {0,0,0,0}, {0,0,0,0}, {0,0,0,0} };
	const std::vector<int> numSerial = { 2,4,8,16,32,64,128,256,512,1024,2048 };
public:
	Board();
	void initBoard();
	void printBoard();
	void upSlide();
	void downSlide();
	void leftSlide();
	void rightSlide();
	bool checkBoard(std::vector<std::vector<int>> check);
	void copyBoard(std::vector<std::vector<int>>& copy);
	void randBoard();
};
#endif
