// CSCI 2421
// CHAD S FUNCKES
/*
FILE: FUNCTIONS.h
DESC: THIS IS THE DEFINITIONS FOR THE MAIN FUNCTIONS USED IN THE PROGRAM

int coins(int)
	Pre: Takes an int value, that should be 1-4
	Post: Returns the value according to the following
			input 1 = 1 (for penny)
			input 2 = 5 (for nickel)
			input 3 = 10 (for dime)
			input 4 = 25 (for quarter)
			any other input returns 0;

int ways3(int)
	Pre: Takes an int value less than 100, representing amount to make change from
	Post: Returns the least number of coins required to make change via recursion

int get_input();
	Post: Asks user for a number and return the value 0-100.

void get_pennies(vector<vector <int> >&, const int&);
void get_nickels(vector<vector <int> >&, const int&);
void get_dimes(vector<vector <int> >&, const int&);
void get_quarters(vector<vector <int> >&, const int&);
	Pre: Requres a vector of vector<int> and a value from 0-100
	Post: Modifies the parameter vector with the combinations of pennies, nickels, dimes, or quarters based
		  Upon the amount input respective to the name.

void get_coins(vector<vector <int> > &, const int &);
	Pre: Requres a vector of vector<int> and a value from 0-100
	Post: Modifies the parameter vector with all combinations of pennies, nickels, dimes, and quarters based
		  Upon the amount input.

void print_coins(const vector<vector <int> >&);
	Pre: Vector of vector<int> that is filled with data from a get_XXX function.
	Post: Prints the 2D vector to show all ways to make change loaded.
	
void print_most_efficient(const vector<vector <int> >&);
	Pre: Vector of vector<int> that is filled with data from a get_XXX function.
	Post: Caluculates and prints the most efficient (least number of coins) 

void print_recursive(const int);
	Pre: A int amount from 0-100
	Post: The lease number of ways (most efficient) based soley on recursion.
*/

#ifndef FUNCKES_HW9
#define FUNCKES_HW9
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
namespace funckes_hw9{

	int coins(int);
	int ways3(int);
	// precondition: denomination = 1 (for penny), 2 (for nickel), 3 (for dime), or 4 (for quarter).
	//
	// postconditon: If amount < 0, then 0 has been returned. Otherwise, the value returned is the
	//               number of ways that amount can be changed into coins whose denomination is
	//               no larger than denomination
	int ways(int, int);
	int ways2(int, int);
	int count(int, int );
	int get_input();
	void get_pennies(vector<vector <int> >&, const int&);
	void get_nickels(vector<vector <int> >&, const int&);
	void get_dimes(vector<vector <int> >&, const int&);
	void get_quarters(vector<vector <int> >&, const int&);
	void get_coins(vector<vector <int> > &, const int &);
	void print_coins(const vector<vector <int> >&);
	void print_most_efficient(const vector<vector <int> >&);
	void print_recursive(const int);

}
#endif