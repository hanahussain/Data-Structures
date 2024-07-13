#include <iostream>
#include <stdlib.h>
#include "nQueens.h"
#include <string>
#include <sstream>
#include <stack> 
#include <vector> 

/* nQueens algorithm
 * Hana Hussain
 * This program will have the user pick an integer n, and create a theoretical n rows x n cols chess board. n queens must be placed on this board such that no queen can attack each other.
 * The positions of these queens will be returned to user. There is also a GUI option (see README.txt for more information)
 */

//define constructor and have original queen set to {1,1} (aka row 1, col 1)
nQueens::nQueens(){
	nQueens::n = 4;
	nQueens::locations.push({1,1});
	nQueens::filled = 1;
	nQueens::tFilled = 0;
} //end constructor

//define all getter and setter methods
std::array<int,2> nQueens::getTop(){
	return locations.top();
} //end getTop

void nQueens::setN(int n){
	nQueens::n = n;
} //end setN

int nQueens::getN(){
	return n;
} //end getN

int nQueens::getFilled(){
	return filled;
} //end getFilled

void nQueens::setFilled(int filled){
	nQueens::filled = filled;
} //end setFilled

int nQueens::getTFilled(){
	return tFilled;
} //end getTFilled

void nQueens::setTFilled(int filled){
	nQueens::tFilled = filled;
} //end setTFilled

std::stack<std::array<int,2>> nQueens::getLocations(){
	return locations;
} //end getLocations

void nQueens::setLocations(std::stack<std::array<int,2>> loc){
	nQueens::locations = loc;
} //end setLocations

std::stack<std::array<int,2>> nQueens::getTemp(){
	return temp;
} //end getTemp

void nQueens::setTemp(std::stack<std::array<int,2>> temp){
	nQueens::temp = temp;
} //end setTemp

//have user pick n greater than 3 (since nqueens doesn't make sense when n<=3) and have error correction
int nQueens::determineN(){
	bool validInput = false;
	bool checker = true;
	std::string nStr;
	int n;
	std::stringstream ss;
	while(!validInput){ //as long as their input is invalid in some way
		validInput = true;
		std::cout << "Enter an integer greater than 3: ";
		std::cin >> nStr; //save what they entered as a string
		for(int i = 0; i < nStr.length(); i++){ //check each character in nStr 
			if(isdigit(nStr[i]) == false){ //if any character is not a number, it's not a number
				validInput = false; //so we need to ask them again
				i = nStr.length(); //exit loop
				std::cout << "Invalid input. Please enter an integer. \n";
			} //end if
		} //end for
		if(validInput){ //check to see if it passed integer test
			ss << nStr;
			ss >> n; //store input into an integer
			ss.clear();
			ss.str("");
			if(n <= 3){ //ensure their number is more than 3, otherwise
				validInput = false; //run through while loop again
				std::cout << "Your integer should be more than 3 \n"; //error message to user
			} //end if
		} //end outer if 	
	} //end while
	return n;
} //end determineN

//bring all values back from temporary stack into locations stack
void nQueens::refillLocations(){	
	std::stack<std::array<int,2>> loc = this->getLocations();
	while(tFilled > 0){ //as long as there is at least 1 value in temporary stack
		std::array<int,2> currQueen = this->getTemp().top(); //save the top of temp
		loc = this->getLocations();
		loc.push(currQueen); //push the saved value onto locations
		this->setLocations(loc); //save locations
		std::stack<std::array<int,2>> tem = this->getTemp();
		tem.pop(); //remove top value off temp
		this->setTemp(tem);
		//updated filled and tFilled accordingly
		this->changeFilled(true);
		this->changeTFilled(false);
	} //end while
} //end refillLocations

//determine if argument newQueen can be attacked by the given queen that's already on chess board
bool nQueens::canBeAttacked(std::array<int,2> newQueen, std::array<int,2> onBoard){
	if(newQueen[1] == onBoard[1]){ //it can be attacked if they're in same row
		return true;
	} else if(newQueen[0] == onBoard[0]){ //it can be attacked if they're in same column
		return true;
	} else if(std::abs(onBoard[0]-newQueen[0]) == std::abs(onBoard[1]-newQueen[1])){ //it can be attacked if they're in same diagonal, aka the dist of the row numbers = dist of the column numbers
		return true;
	} //end if else	
	return false;
} //end canBeAttacked

//checks to see if queen we want to add has been tested through the whole row & had conflicts each time
bool nQueens::newRowFailed(std::array<int,2> newQueen){
	return newQueen[1] >= this->getN(); //if it's at the last position in the row and there's a conflict, this row fails
} //end newRowFailed


//used to ensure an updated queen checks with each row for conflicts, even ones that worked for queen's previous position
void nQueens::decrementTemp(){
	std::stack<std::array<int,2>> tem = this->getTemp();
	std::array<int,2> currQueen = tem.top(); //save the top of tem
	tem.pop(); //now pop & remove top value
	this->setTemp(tem); //save tem
	this->changeTFilled(false); //decrement tFilled since we removed a value off tem
	std::stack<std::array<int,2>> loc = this->getLocations();
	loc.push(currQueen); //push the saved value onto loc
	this->setLocations(loc); //save this for locations
	this->changeFilled(true); //increment filled since we added a value to locations
}

//remove top value of locations stack
void nQueens::decrementLocations(){
	std::stack<std::array<int,2>> loc = this->getLocations();
	loc.pop();
	this->setLocations(loc);
	this->changeFilled(false);
} //end decrementLocations

//update value of filled, either increment or decrement
void nQueens::changeFilled(bool increment){
	int fill = this->getFilled();
	if(increment){
		fill++;
	} else {
		fill--;	
	} //end if else
	this->setFilled(fill);
} //end incrementFilled

//update value of tFilled, either increment or decrement
void nQueens::changeTFilled(bool increment){
	int tFill = this->getTFilled();
	if(increment){
		tFill++;
	} else {
		tFill--;	
	} //end if else
	this->setTFilled(tFill);
} //end incrementFilled

//empty out temp stack's contents when backtracking bc we will no longer need these values
void nQueens::emptyTemp(){
	std::stack<std::array<int,2>> tem = this->getTemp();
	while(not tem.empty()){ //as long as tem isn't empty
		tem.pop(); //pop off the top value 
		this->changeTFilled(false); //decrement tFilled because we removed an element off tem
	} //end while
	this->setTemp(tem);
} //end emptyTemp

//called in the case where we've popped all the way to row 1 and need to update row 1's position
std::array<int,2> nQueens::determineOnBoard(){
	this->emptyTemp(); //get rid of all temp values because we've backtracked
	this->decrementLocations();
	//store the current top value so we can edit & use it
	std::array<int,2> onBoard = this->getTop();
	onBoard = {onBoard[0], onBoard[1]+1};
	//since top will be modified, no longer need current top
	this->decrementLocations();
	if(not this->newRowFailed(onBoard)){ //assuming we can increment it
		std::stack<std::array<int,2>> loc = this->getLocations();
		loc.push(onBoard);
		this->setLocations(loc);
		this->changeFilled(true);
		return onBoard;
	} else { //we can't increment it, so let's reset and try again until we can
		determineOnBoard();
	} //end if else
	return {-1,-1}; //shouldnt reach this line but just to make compiler happy
} //end determineOnBoard

//very convoluted recursive function that removes conflicts & places new queen positions in stack
std::array<int,2> nQueens::removeConflicts(std::array<int,2> newQueen, std::array<int,2> onBoard){
	if(this->canBeAttacked(newQueen, onBoard)){
			if(this->newRowFailed(newQueen)){ //if the queen we're comparing it to cannot be incremented anymore
				this->refillLocations(); //first bring back all elements from temp into locations
				newQueen = this->getLocations().top(); //forget about newQueen and start to evalute previous row's position as the new newQueen
				if(this->newRowFailed(newQueen)){ //if this second queen also cannot be incremented anymore
					std::array<int, 2> board = this->determineOnBoard();
					newQueen = {board[0]+1, 1}; //reset newQueen to the current onBoard's next row up, starting again at column 1
				} else {
					newQueen = {newQueen[0], newQueen[1]+1}; //increment the column of the row we're on
					//next few lines is just removing the top element of stack so that we can update it with newQueen
					std::stack<std::array<int,2>> currLoc = this->getLocations(); 
					currLoc.pop();
					this->setLocations(currLoc);
					this->changeFilled(false); 
					this->refillLocations();
				} //end inner if else
			} else { //need to increment column of current row
				newQueen = {newQueen[0], newQueen[1]+1};
				this->refillLocations(); 
			} //end inner if else	
	} else {
		//all following lines is just removing the top off location and putting it into temp since we need to check newQueen against everything in locations stack
		std::stack<std::array<int,2>> tem = this->getTemp();
		tem.push(this->getTop());
		this->setTemp(tem);
		std::stack<std::array<int,2>> loc = this->getLocations();
		loc.pop();
		this->setLocations(loc);
		this->changeFilled(false); //decrement filled
		this->changeTFilled(true); //increment filled
		if(not this->getLocations().empty()){
			//do nothing, newQueen was already updated above
		} else { //locations is empty, everything has been checked and queen's current location works
			this->refillLocations();
			std::stack<std::array<int,2>> loc = this->getLocations(); //call back all elements from temp
			loc.push(newQueen); //push the working queen onto the stack
			this->setLocations(loc);
			this->changeFilled(true); //increment filled bc we just pushed a value
			newQueen = {newQueen[0]+1, 1}; //start the next newQueen in the first position of the next row
		}
	} //end outer if else
	return newQueen;
} //end removeConflicts

//returns current stack element (current queen's position) as a string for printing
std::string nQueens::getPosition(std::array<int,2> pos){
	std::string yeet = "{" + std::to_string(pos[0]) + "," + std::to_string(pos[1]) + "}\n";
	        return yeet;
}

//driver function for base assignment
std::vector<int> nQueens::start(){
	//get n from user and set it
	int n = determineN();
	nQueens n1;
	n1.setN(n);
	std::vector<int> colLocs; //this will be returned to draw chess board, no effect on base assignment
	colLocs.push_back(n); //save n as first element in list
	std::array<int,2> newQueen = {2,1}; //original new queen will be in second row since original queen is already placed on first
	while(n1.getFilled() < n){
		newQueen = n1.removeConflicts(newQueen, n1.getTop());
	} //end while
	std::stack<std::array<int,2>> tem = n1.getLocations();
	//goes through tem stack and prints out each queen's location using the getPosition formatting function
	for(int i = 1; i <= n; i++){
		std::cout << "\nQueen " << ((n-i)+1) << ": " << n1.getPosition(tem.top());
		std::array<int,2> top = tem.top();
		colLocs.push_back(top[1]); //adds the current array's column value to the chess board vector
		tem.pop();
	} //end for, original assignment ends here
	return colLocs; //for chess board, not base assignment
} //end start	


/******************************************************
************DRAWING CHESS BOARD FOR BONUS**************
*******************************************************/

//idea is to consider each square as its top row and left column lines, then add on to that horizontally in the k, i and j loops, then add to that vertically (making rows 2-n) with y loop
void nQueens::drawSquare(){
	std::vector<int> colLocs = this->start();
	int n = colLocs[0]; //had to send n over as the first element in colLocs because it was saved to local n1 object in start() method
	std::stack<std::array<int,2>> loc = this->getLocations();
	for(int y = 0; y < n; y++){
		//takes array of column positions produced by start function and makes current row, writing Q for queens
		int counter = 0;
		std::string square = "\n ---------"; //top rows
		for(int k = 1; k < n; k++){ //making n columns
			square += " ---------"; //making column's tops
		}
		for(int i = 1; i < 4; i++){ //space formatting for | characters
			//y+1 because when y=0 that's not a position that's just n, so each location if offset by 1
			if(counter == colLocs[y+1] && i == 2){ //this entire if structure is to place first column's queen
				square += "\n|    Q    ";
				loc.pop();
			} else {
				square += "\n|         ";
			} //end if else
			counter++;
			for(int j = 1; j < n; j++){ //this loop makes columns 2-n, playing queens if needed
				if(j != n-1){
					if(j == colLocs[y+1]-1 & i == 2){
						square += "|    Q    ";
					} else {
						square += "|         ";
					} //end inner if else
				} else { //since we're at the last column, need to close off board with last line
					if(j == colLocs[y+1]-1 && i ==2){
						square += "|   Q    |";
					} else {
						square += "|        |";
					} //end inner if else
				} //end if else
			} //end for
		} std::cout << square;
		if(y == n-1){
			std::cout << "\n ---------";
			for(int j = 1; j < n; j++){
				std::cout << " ---------";
			} //end inner for
		} //end if
	} //end for
} //end function


