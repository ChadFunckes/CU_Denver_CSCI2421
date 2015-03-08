// Chad S Funckes
// CSCI 2421
//
// Main functions implementation for HW6 (double circular linked lists)
// Please see functions.h for documentation

#include <iostream>
#include "node1.h"
#include "functions.h"

using namespace std;

namespace funckes_6 {
	
	void fill_list(node*& theList, int& n, int& m){
		node* loc; // will be location pointer to fill list
		loc = NULL;

		if (theList != NULL){  // check is list input is not uninitialized, if it is not null make it so.
			list_clear(theList);
			delete theList;
			theList = NULL;
		}

		while (n < 2){  // while loop check a valid number of contestants
			cout << "How many contestants do you have: ";
			cin >> n;
			if (n < 2)
				cout << "The Number of contestants must be greater than 1\n";
		}
		while (m > n || m <= 0){ // while loop checks a valid number was drawn 1 through n.
			cout << "\nWhich number was drawn from the hat? ";
			cin >> m;
			if (m > n || m < 1)
				cout << "\nThat number is impossible, it must be a number 1-# of contestants" << n;
		}
		theList = new node(1); // start the list, fist data field is 1 because the list has to have at least the number 1
		loc = theList;		  // set the location pointer to the head of the list
		for (int num = 2; num <= n; num++){ // start putting numbers in at 2 until the n number of contestants is reached
			list_insert(theList, loc, num); // use the modified insert toolbox function to place the next data element
			loc = loc->link();				// advance the location pointer.
		}
	}

	void calc_winner(node*& loc, const int& n, const int& m){
/// ** input error checking		
		if (loc == NULL){
			cout << "\n***Error, input list is null, cannot continue****\n";
			return;}
		if (n <= 0 || m <= 0){
			cout << "\n***Error, number of contestants and number drawn must not be 0, cannot continue***\n";
			return;}
/// *** end input error checking

		for (int i = n - 1; i > 0; i--){
			if (loc == loc->link()) // check if there is only 1 node in the list
				break;
			for (int forward = 1; forward < m; forward++){ // move the location forward m number of times
				loc = loc->link();
			}
			cout << "\nThe contestant eliminated is " << loc->data();
			loc = loc->last(); // move loc to be sent to the remove func to the previous pointer
			list_remove(loc); // remove the desired position
			loc = loc->link();// put loc at the poistion after the delete per instructions
			i--; // count cyclce completion	
			if (loc == loc->link()) // check if there is only one node in the list
				break;
			for (int backwards = 1; backwards < m; backwards++){ // move the position backwards by the number selected
				loc = loc->last();
			}
			cout << "\nThe contestant eliminated is " << loc->data();
			loc = loc->last(); // move loc to be sent to the remove func to the previous pointer
			list_remove(loc); // remove desired position
		}
	}
}