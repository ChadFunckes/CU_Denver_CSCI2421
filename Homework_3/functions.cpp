//Chad S Funckes
// csci 2421
// Set implementation (modification of bag class, HW3)
//
// FILE: functions.cpp
// Function implementations from the functions.h file.
// see functions.h for documantations.

#include <iostream>
#include "functions.h"
using namespace std;

namespace Chad_Funckes_HW3{
	
	bool Get_Sets(set a[]){  // input sets of integers from a file into the class sets 
		int i=0;
		string incomming; // holds an entire line from the file
		string token; // holds the integer that will be picked off from the stream

		// set the file stream and checks if the file opened, return false upon error
		ifstream InFile; 
		InFile.open("input.dat");
		if (!InFile){
			cout << "The file name is not valid, please choose a valid file.\n";
			return false;}

		/* read in data in full lines using getline, then turn the resulting string into an input stream
		   using stringstream.  Then check every incomming block to ensure it is an integer before conversion.
		   If a non-integer input is found, retun a bool false and end function.  If the incomming block is
		   deemed correct, then convert the string segment into an integer and place is into a set class object
		   using the set class insert function.  Then finally use the set class function clear_dups to ensure the set
		   contains all unique numbers. */
		
		for (int out_loop = 0; out_loop < NUMBER_OF_SETS; out_loop++){
			getline(InFile, incomming);  // puts a single line in a string
			stringstream ss(incomming); // streams the sting incomming
			i = 0;
			while (getline(ss, token, ' ') || i > 30){ //while getline is still functioning keep storing data
				if (!isdigit(token[0]) && token[0] != '-'){ // checks if the input is a number
					cout << "The File must have only integer values.  One of you values is not an integer, check the file\n"
						<< "and try again\n";
					InFile.close();
					return false;}
				a[out_loop].insert(atoi(token.c_str()));  // inserts the int version into the array via set mbr function.
				++i;
			}  
			a[out_loop].clear_dups(); // takes duplicates out of the numbers
		}	
		InFile.close();
		return true;
	}

	void Print_Set(set& a){  // Prints the values of integers stored.
		cout << "The integer values for the set are:\n";		
		for (unsigned i = 0; i < a.size(); i++){
			cout << a.display(i) << " ";
		}
		cout << endl;	
	}
}