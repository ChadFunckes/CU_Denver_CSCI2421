// Chad S Funckes
// CSCI 2421
//
// Driver File for homework 5 (linked lists)
/*
This program gets a txt file from the user utilizes node1.h to stores each word of the file into in a node in a linked list.
The program then reverses the list and sends the reversed list to a file called output.txt.
*/

#include <iostream>
#include "node1.h"
#include "functions.h"

using namespace std;
using namespace main_savitch_5;
using namespace FUNCKES_MAIN_HW5;

int main(){
	node* theList = NULL; // pointer for a new list
	node* revList = NULL; // pointer for the reversed list

	theList = Get_list(); // fill the list with data from a file and set pointer to the created list.

	revList = reverse_list(theList); // reverse the list

	output_list(revList);  // send output to the file output.txt

// free up the memory from the heap //
	list_clear(theList);
	delete theList;
	theList = NULL;

	list_clear(revList);
	delete revList;
	revList = NULL;
}
