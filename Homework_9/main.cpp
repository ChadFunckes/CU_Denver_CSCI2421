// CSCI 2421
// CHAD S FUNCKES
/*
FILE: MAIN.CPP
DESC: THIS PROGRAM TAKES A NUMBER OF CHANGE FROM 0-100 FROM THE USER AND
TELLS YOU ALL OF THE POSSIBLE COMBINATIONS TO GIVE CHANGE BACK.  IT THEN
TELLS YOU WHAT THE MOST EFFICIENT WAY IS (LEAST AMOUNT OF COINS) USING A 2D
VECTOR AND ALSO USING TO RECURSION.

*/

#include <vector>
#include "functions.h"

using namespace std;
using namespace funckes_hw9;

int main(){
	vector<vector <int> > keeper; // storage for coin lists.

	int amount = get_input(); // get amount from the user
	get_coins(keeper, amount); // get the coin lists
	print_coins(keeper); // print out the coin lists
	print_most_efficient(keeper); // print most efficient method
	print_recursive(amount); // use recursion to verify the coin count
}
