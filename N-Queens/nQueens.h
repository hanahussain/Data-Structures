#include <stack>
#include <array>
#include <string>
#include <vector>

#ifndef NQUEENS_H_EXISTS
#define NQUEENS_H_EXISTS

class nQueens {
	private:
		//std::stack<int*> locations;
		std::stack<std::array<int,2>> locations;
		std::stack<std::array<int,2>> temp; //used to iterate through locations
		int n;
		int filled;
		int tFilled; //to keep track of size of temp stack

	public:
		nQueens();
		std::array<int,2> getTop();
		void setN(int n);
		int getN();
		int getFilled();
		void setFilled(int filled);
		int getTFilled();
		void setTFilled(int filled);
		std::stack<std::array<int,2>> getLocations();
		void setLocations(std::stack<std::array<int,2>> loc);
		std::stack<std::array<int,2>> getTemp();
		void setTemp(std::stack<std::array<int,2>> temp);
		int determineN();
		bool canBeAttacked(std::array<int,2> newQueen, std::array<int,2> onBoard);
		bool newRowFailed(std::array<int,2> newQueen);
		void refillLocations();
		void decrementTemp();
		void decrementLocations();
		void changeFilled(bool increment);
		void changeTFilled(bool increment);
		//std::array<int,2> determineOnBoard(std::array<int,2> board);
		void emptyTemp();
		std::array<int,2> determineOnBoard();
		//void removeConflicts(std::array<int,2> newQueen, std::array<int,2> onBoard);
		std::array<int,2> removeConflicts(std::array<int,2> newQueen, std::array<int,2> onBoard);
		std::vector<int> start();
		std::string getPosition(std::array<int, 2>);
		//int getColumn(std::stack<std::array<int,2>> temporary);
		constexpr int nValue();
		//void drawRow(int m, std::array<int, nValue()> arr);	
		void drawSquare();

}; //end definition

#endif
