/*
Programmer: Kiana Vang
Date: June 1, 2021

Program Description:
Consider an array of n ticket prices, tickets. We define a number, m, to be the size of some subsequence, s, of tickets where each element covers an unbroken range of integers; that is to say, if you were to sort the elements in s, the difference between any elements j and j + 1 would be either 0 or 1. 

For example: tickets = [8, 5, 4, 8, 4] gives us sorted subsequences [4, 4, 5] and [8, 8]; these subsequences have m values of 3 and 2, respectively.

maxTickets function returns an integer denoting the maximum value of m.

So in the previous example, the value returned is 3 because this is the largest unbroken sequence of sorted consecutive integer whose adjacent elements have a maximum absolute difference of 1.


Note: Only the function is submitted. The remaining parts are added so that I can test and debug on my own machine.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxTickets(vector<int> tickets) {
	
	sort(tickets.begin(), tickets.end()); //sort vector in ascending order
	
	cout << endl;
	cout << "The sorted vector is: ";

	for (int i = 0; i < tickets.size(); i++) {
		cout << tickets[i] << " ";
	}
	const int SIZE = tickets.size();
	cout <<endl << "Vector length is: " << SIZE << endl;
	int max = 0;
	int cur_loc = tickets[0];
	int count = 1; // count the first element;
	
	for (int i = 0; i < SIZE; i++) {
		if ((((i - 1) >= 0) && ((i - 1) <= SIZE)) && (((i + 1) >= 0) && ((i + 1) <= SIZE))) { // make sure index is within boundaries
			//cout << i << endl;
			
			if (tickets[i] - tickets[i - 1] == 0 || tickets[i] - tickets[i - 1] == 1) {
				//cout << "Here, counting" << endl;

				//cout << tickets[i] << " - " << tickets[i - 1] << " = " << tickets[i] - tickets[i - 1] << endl;
				count++;

				//cout << "Count is: " << count << endl;
			}
			else {
				//cout << "Here, resetting" << endl;
				cur_loc = tickets[i]; // reset cur_loc to index i
				count = 1; // reset count
				//cout << "Count is: " << count << endl;

			}

			if (count > max) {
				max = count; // update max
				//cout << " i: " << i << " - max is: " << max << endl;
			}

		}
	}
	return max;
}

int main() {
	vector<int> tickets{ 4, 4, 8, 13, 2, 3, 5, 7, 10, 11, 12, 13, 14, 15, 1, 2, 3, 6}; 
	

	cout << "The original vector is: ";

	for (int i = 0; i < tickets.size(); i++) {
		cout << tickets[i] << " ";
	}

	int max = maxTickets(tickets);

	cout << endl;
	cout << "The max subsequence is: " << max << endl;

	return 0;
}