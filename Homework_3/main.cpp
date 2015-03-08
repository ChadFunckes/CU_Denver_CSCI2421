//Chad S Funckes
// csci 2421
// 
// FILE: main.cpp
// 
// DESCRIPTION:  This program utilises the set class (an extended version of bag from chapter 3)
//   To input two sets of integers from a file named input.dat.  Each set of integers will be on a single line
//   separated by a end of line charictor.  After input of the data set, all duplicate numbers in the data set
//	 will be deleted, so that the set only contains one copy of any integer.
//
//	 The two input sets will then be added togather using the set class overloaded operator +.  This will
//	 place the two set togather and then eliminate any common numbers, so that the new set is once again a single
//	 "set" of integers with no repeating numbers and then display the resulting set for the user.
//
//	 The program will then take the two original sets and utilize the overloaded - operator of the set class
//	 to remove all of the items present in the second set from the first set.  and then display the resulting set
//	 to the user.


#include <iostream>
#include <fstream>
#include <cassert>
#include "set.h"
#include "functions.h"

using namespace std;
using namespace Chad_Funckes_HW3;

int main(){

	// create initial input sets
	set sets[NUMBER_OF_SETS];

	// take inputs from a file
	if (Get_Sets(sets) == false) // Get_Sets returns a bool of 1 upon any error code displayed.
		return 0;

	// add inputs togather
	set set3 = sets[0] + sets[1];

	// Print the new set
	cout << "After additions ";
	Print_Set(set3);
	cout << endl;

	// subract inputs
	cout << "After subtractions ";
	set set4 = sets[0] - sets[1];
	
	// Print the new set
	Print_Set(set4);
	cout << endl;

	return 0;
}