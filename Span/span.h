#include <vector>
#include <string>
#include <stack>

#ifndef SPAN_H_EXISTS
#define SPAN_H_EXISTS

class span{
	private:
		int n;
		std::vector<float> prices;

	public:
		span();
		std::vector<float> fillPrices();
		int determineN();
		int getN();
		void setN(int n);
		std::vector<float> getPrices();
		std::vector<int> bruteForce();
		void displaySpan(std::vector<int> s);
		void displayPrices();
		std::vector<int> usingStack();
		void start();
		int makeChoice();
}; //end definition

#endif
