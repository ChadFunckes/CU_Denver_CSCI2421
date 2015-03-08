// Chad S Funckes
// CSCI 2421
// FEB 16, 2014
//
// FILE: FUNCTIONS.H LISTS THE FUNCTIONS USED IN THE MAIN PROGRAM
//
// bool Get_Sets(set a[])
//    PRECONDITION: A data file named input.dat must exist in the directory with the program.
//			        there must be an intitalized array of set class objects to be passed to the function.
//	  POST CONDITION: Lines of integers seperated by spaces are placed into items of the set class objects.	
//					  Any error in reading in the integer sets will return a bool: false.
//
// void Print_Set(set& a)
//	  Postcondition: Returns the data stored in the set class object.

#ifndef CHAD_FUNCKES_FUNCTIONS_3
#define CHAD_FUNCKES_FUNCTIONS_3
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include "set.h"
using namespace std;
namespace Chad_Funckes_HW3{

const int NUMBER_OF_SETS = 2;
bool Get_Sets(set a[]);
void Print_Set(set& a);
}
#endif