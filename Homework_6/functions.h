// Chad S Funckes
// CSCI 2421
//
// Main functions definitions for HW6 (linked lists)
/*
FUNCTIONS: 

void fill_list(node*&, int& n, int& m)
	precondition: input is a null pointer of node type. First int is the number of contestants and second is the number drawn
				the list and int values should be un-itialized, if they are not input list will be erased and n and m values input will be changed by the function.
	post condition: The list will be filled with n numbers of data members and the original values passed from n and m into the func
				will be changed by the function to reflect user inputs.

void calc_winner(node*&, const int&, const int&)
	precondition: input is a pointer to a circular double linked list that is NOT NULL and first and second int represents
					the number of contestants and the number drawn respectivly.
	postcondition: the input list pointer will be modified so that ONLY the winning member remains.  All other data members will be eliminated from the list.
*/

#ifndef FUNCKES_HW5
#define FUNCKES_HW5
#include "node1.h"

using namespace std;

namespace funckes_6{

	void fill_list(node*&, int&, int&);

	void calc_winner(node*&, const int&, const int&);
}
#endif