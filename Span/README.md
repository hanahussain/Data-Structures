# Span
2 solutions to the stock span problem in C++

### Purpose
This program demonstrates two methods to solve the stock span problem, commonly used in financial markets to analyze stock price trends and volatility. 
It calculates the stock span for randomly generated stock prices. The stock span of a day is the maximum number of consecutive previous days where the stock price was 
less than or equal to the current day's price.

### Features
-Random Generation: Generates a list of random stock prices.

-Brute Force Method: Calculates spans using loops to go through through previous days.

-Stack-Based Method: Utilizes a stack to backtrack and efficiently calculate spans by comparing prices.

### Running Instructions
Download the .zip file and extract all the files. In a Linux environment (Windows PowerShell, Git Bash, etc), enter the command make run to start the program.
Between runs, you may enter the command make clean to clean out output files.

The program will prompt you to choose an integer value. Enter an integer for the number of days to calculate the span over. The program will then have you choose which 
method to calculate span by (either brute force or span). 


