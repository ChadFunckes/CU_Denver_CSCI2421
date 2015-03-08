// Chad S Funckes
// CSCI 2421
//
// Main functions definitions for HW5 (linked lists)
/*
node* Get_list()
post condition: Returns a pointer to a linked list read in from a file name specified by the user.

void output_list(const node* head)
pre-conditions: head is a pointer to a linked list, head can not be null
post-condition: Outputs the list pointed to by head to a file called output.txt
*/

#ifndef FUNCKES_HW5
#define FUNCKES_HW5
#include "node1.h"

using namespace std;
using namespace main_savitch_5;

namespace FUNCKES_MAIN_HW5{

	node* Get_list();
	void output_list(const node* head);
}
#endif