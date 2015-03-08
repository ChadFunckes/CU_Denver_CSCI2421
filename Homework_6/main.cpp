// Chad S Funckes
// CSCI 2421
//
// Driver File for homework 6 (circular double linked lists)
/*
This program simulates a travel agent selecting customers for a free world cruize.  The user selects how many contestants are in the pool.
Then those numbers are dropped into a hat and randomly selected by the agent.

The program then takes the number selected from the hat, and then starting at the begining of the list walks forward that many people and the person
they end up at is eliminated from the competition.  The agent then turns around and walks back the other direction the same number of people and then that person
is eliminated.  This process is continued until only 1 person is left in the game and that person is the winner of the competition.
*/

#include <iostream>
#include "node1.h"
#include "functions.h"

using namespace std;
using namespace funckes_6;

int main(){
	int n=0, m=0; // n and m are variables used by all program functions.
	node* theList = NULL; // global pointer for the contestant list

	fill_list(theList, n, m); // create and fill the list

	calc_winner(theList, n, m); // calculate the winner

	cout << "\n\nThe winner of the contest is: " << theList->data() << endl;

// free up the memory from the heap //
	list_clear(theList); // call function just in case operations did not clear the list completely by error.
	delete theList;		// delete the list member.
	theList = NULL;
}
