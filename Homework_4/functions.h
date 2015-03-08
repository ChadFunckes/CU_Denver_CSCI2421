//Chad S. Funckes
// CSCI 2421
//
// FILE: functions.h
//   
// This file contains the functions for HW4, text formattting excercise.
// The functions used are as follows:
//
//	ifstream Open_Input(int& exist_test, char** filename)
//     Precondition: argv and arc functions must be parameters of the main function
//     Postcondition: an input filestream object of either a file specified at the command line
//					  or the default data.txt file or an unopened stream.  Error displays are handled
//					  by the function, but the use need to check the stream completed.
//
//	void Get_Width()
//		post condition: returns an int value, after asking how many columns.
//
//	void Format_Input(ifstream& InFile, const int& text_width, vector<my_string>& lines)
//		precondition: Input file stream must exist.  User inputs the width of the format and a vector for the format output
//		post condition: a vector filled with properly formatted text, specified by the input width from the user.
//
//	void Display_Output(vector<my_string>& text)
//		post condition: text displayed to the screen of a line by line output of the vector file served as input.
//
//	void Save_Output(vector<my_string>& text)
//		post condition: a file called data.out is created containing a line by line output of the vector served as input.

#ifndef FUNCKES_HW4
#define FUNCKES_HW4

#include <vector>
#include "mystring.h"
using namespace std;
namespace hw4{
	ifstream Open_Input(int& exist_test, char** filename);
	int Get_Width(); 
	void Format_Input(ifstream& InFile, const int& text_width, vector<my_string>& lines);
	void Display_Output(vector<my_string>& text);
	void Save_Output(vector<my_string>& text); 
} 
#endif