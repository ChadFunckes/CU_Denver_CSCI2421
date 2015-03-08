//Chad S. Funckes
// CSCI 2421
//
// FILE: main.cpp
//
// This file contains a program utilizing the class my_string 
// It takes an input text file of any number of lines and any number of columns from
// either a command line parameter or using the default file name data.txt.
// The program then takes from the user a specified column width and then formats that input
// text into a vector that is exactly that many columns wide.  If a word spans the line a hyphen
// is added to the end of the line just past the specified width.
//
// For documentation of program functions please see functions.h

#include <iostream>
#include <fstream>
#include <vector>
#include "mystring.h"
#include "functions.h"

using namespace hw4;
using namespace std;

int main(int argc, char** argv){
	my_string test;
	int number_of_columns;
	vector<my_string> formatted_text; // vector to hold formated text.

	ifstream InFile("data.txt"); // open the input file
	if (!InFile.is_open())
		return 0; 

	number_of_columns = Get_Width(); // get number of columns for output //

	Format_Input(InFile, number_of_columns, formatted_text); // do the work....
	
	InFile.close(); // close input file
	
	Display_Output(formatted_text); // Print the output to the screen
	
	Save_Output(formatted_text); // output data to file
}
