#include <iostream>
#include <stdlib.h>
#include <stack>
#include <vector>
#include <string>
#include <sstream>
#include <time.h>
#include <random>
#include "span.h"
#include <iomanip>

//Note - a vector was used for prices and span in place of array because n is user defined and not a constant, so the compiler is unhappy

//null constructor intializes n based on user input and initializes stock price vector using pseudo random number generation
span::span(){
	span::n = determineN();
	span::prices = fillPrices();
} //end constructor

//getters
int span::getN(){
	return n;
} //end getN

std::vector<float> span::getPrices(){
	return prices;
} //end getPrices

//have user determine size of stock/span lists (aka number of days)
int span::determineN(){
	bool validInput = false;
	bool checker = true;
	std::string nStr;
	int n;
	std::stringstream ss;
	while(!validInput){ //as long as their input is invalid in some way
		validInput = true;
		std::cout << "Enter an integer: ";
		std::cin >> nStr; //save what they entered as a string
		for(int i = 0; i < nStr.length(); i++){ //check each character in nStr 
			if(isdigit(nStr[i]) == false){ //if any character is not a number, it's not a number
				validInput = false; //so we need to ask them again
				i = nStr.length(); //exit loop
				std::cout << "Invalid input. Please enter an integer. \n";
			} //end if
		} //end for
	} //end while
	ss << nStr; //now that we know the user inputted an integer, we can put it in an integer
	ss >> n;
	return n;
} //end determineN

//initializes prices of stock using pseudo random number generation
//NOTE: I tried to round the numbers to 2 decimal places but it didn't work out so I gave up -- it doesn't mess anything up, but the prices aren't formatted ideally for the user
std::vector<float> span::fillPrices(){
	std::vector<float> price;
	srand(time(NULL)); //seed the random number generation based on time, so that it's always a new seed
	for(int i = 0; i < n; i++){
		float nextNum = ((float)rand()) / ((float)RAND_MAX)*500+1; //generating a price from 0-499.99
		int num = (int)((nextNum * 100) + 0.5); //alg to try to round number 2 decimal places
		nextNum = (float) num/100;
		price.push_back(nextNum); //add this generated number to prices vector
	} //end for
	return price;
} //end fillPrices

//print the prices vector to user
void span::displayPrices(){
	std::vector<float> p = this->getPrices();
	std::string sStr = "{";
	for(int i = 0; i < n; i++){
		if(i < n-1){
			sStr += "$" + std::to_string(p[i]) + ", "; //for every element except the last, want to follow up with comma
		} else {
			sStr += "$" + std::to_string(p[i]) + "}\n"; //otherwise, want to close list with closing bracket
		} //end if else
	} //end for
	std::cout << sStr; //print out the string we've made
} //end displaySpan

//print the spans for brute force and stack to user
void span::displaySpan(std::vector<int> s){
	std::string sStr = "{";
	for(int i = 0; i < n; i++){
		if(i < n-1){
			sStr += std::to_string(s[i]) + ", "; //for every element except the last, want to follow up with comma
		} else {
			sStr += std::to_string(s[i]) + "}\n"; //otherwise, want to close list with closing bracket
		} //end if else
	} //end for
	std::cout << sStr;
} //end displaySpan

//implement pseudocode from slides - aka calculate span of stock iteratively without a stack
std::vector<int> span::bruteForce(){
	std::vector<int> span;
	int s;
	for(int i = 0; i < n; i++){
		s = 1; //span starts at 1
		if(i != 0){
			while(s <= i and prices[i-s] <= prices[i]){ //keep going until s exceeds i or the current price becomes smaller
				s++;
			} //end while
		} //end while
		span.push_back(s); //add span value to span vector	
	} //end for 
	return span; //return span to program
} //end bruteForce

//implement solution using stack as described by lecture slides
std::vector<int> span::usingStack(){
	std::stack<int> biggest;
	std::vector<int> span;
	int j = 0;
	biggest.push(prices[0]); //immediately push the first element in list
	span.push_back(1); //span of first day is always 1
	for(int i = 1; i < n; i++){ //start from 1 because day 0 is already evaluated
		while(not biggest.empty() and biggest.top() < prices[i]){ //as long as the stack isn't empty and it's top value isn't less than the current price
			biggest.pop(); //take off top element
			j--; //j is decremented accordingly
		} //end while
		if(biggest.empty()){
			j = -1; //since h(1) = -1
		} //end if 
		span.push_back(i-j); //since h(1) exists and is j
		biggest.push(prices[i]);
		j = i; //update j since the top value is now the value of prices at i
	} //end for
	return span;
} //end usingStack

//connect different functions together
void span::start(){
	bool keepGoing = true;
	std::cout << "Stock prices over " << this->getN() << " days are: ";
	this->displayPrices();
	while(keepGoing){
		int n = this->makeChoice();
		if(n == 0){
			keepGoing = false;
		} else if(n == 1){
			std::vector<int> bf = this->bruteForce();
			std::cout << "Span when calculated through brute force: ";
			this->displaySpan(bf);
		} else if(n == 2){
			std::cout << "Span when calculated using a stack: ";
			std::vector<int> st = this->usingStack();
			this->displaySpan(st);
		} else { 
			std::cout << "\nYour integer wasn't 0, 1 or 2. Let's try this again. \n";
		} //end if else
	} //end while
} //end start

//the point of this function is to let user choose how they want span to be calculated
int span::makeChoice(){
	std::cout << "\nHow would you like to calculate span? \n0) Quit \n1) Brute Force Method \n2) Using a stack";
	bool validInput = false;
	std::string nStr;
	int n;
	std::stringstream ss;
	while(!validInput){ //as long as their input is invalid in some way
		validInput = true;
		std::cout << "\nEnter an integer choice between 0 and 2: ";
		std::cin >> nStr; //save what they entered as string to test it
		for(int i = 0; i < nStr.length(); i++){ //if any character is not a number, it's not a number
			if(isdigit(nStr[i]) == false){
				validInput = false; //need to ask them to enter again
				i = nStr.length(); //exit loop
				std::cout << "Invalid input. Please enter an integer. \n";
			} //end if
		} //end for
		if(validInput){ //check to see if it passed integer test
			ss << nStr;
			ss >> n; //store input into integer
			ss.clear();
			ss.str(""); //clear stringstream buffer in case while loop runs again
		} //if
	} //end while
	return n;
} //end start	
		
