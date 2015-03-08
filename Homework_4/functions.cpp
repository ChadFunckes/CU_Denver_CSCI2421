//Chad S. Funckes
// CSCI 2421
//
// FILE: functions.cpp
// 
// Implementation of functions.h
// Please see functions.h for documentation

#include <iostream>
#include <vector>
#include <cassert>
#include <fstream>
#include "functions.h"
#include "mystring.h"
using namespace std;

namespace hw4{

/*	ifstream Open_Input(int& exist_test, char** filename){
		/// PRE-TEST FOR COMMAND ARGUMENT//// Test if a file name was specified before any operations occur.
		if (exist_test < 2){
			cout << "There was no file specified at run time, the default file 'data.txt will be used'\n";
			ifstream InFile("data.txt");
			if (!InFile.is_open()){ // Error check if data.txt can not open
				cout << "The file data.txt or specified file was not found.  Please put data.txt\n"
					<< "in the default directory or specify a file at run time EX: hw4 thisfile.txt\n";
				return InFile;
			}
		} // end error checking

		ifstream InFile(filename[1]);
		if (!InFile.is_open()){
			cout << "The file " << filename[1] << " was not found.\n"
				<< "Please check the filename and try again.\n";
			return InFile;
		}
		return InFile;
	}
*/
	int Get_Width(){
		int text_width;
		char input[25] = "a"; // intermediate input to check number value is entered
		while (!isdigit(input[0]) || atoi(input) < 1){ // loop until a digit is inupt for the width
			cout << "How many columns wide should the output be?\n";
			cin >> input;
			if (isdigit(input[0]) && atoi(input) > 0){
				text_width = atoi(input); // convert to a int value
				return text_width;
			} // return back the width for formatting.
			cout << "Please enter a width as a number greater than 0 EX: 50\n";
		}
		return 0; // will never hit this return, it just clears compiler warning.
	}
	void Format_Input(ifstream& InFile, const int& text_width, vector<my_string>& lines){
		assert(InFile.is_open()); // check a valid open input file.
		my_string incomming; // used for read in and out going text
		my_string housing;  // houses intermediate my_string
		unsigned place = 0; // Keeps track of the charictor number
		int width = text_width; // width is a modifiable text_width, to increase the char read loop by one if the first is a space
		bool first = true; // Keeps track if the charictor is the first on the line (to eliminate a first char space)
		housing.reserve(1000); // reserves space to prevent re-sizing
		incomming.reserve(1000); // reserves space to prevent resizing
		/* -------------------------
		Loop gets all lines of input from the file, overloaded getline from the class
		my_string already eliminates white space.  Assemble lines in a single
		my_string called housing.
		---------------------------- */
		for (int i = 0; !InFile.eof(); i++){
			getline(InFile, incomming);
			housing += incomming + " ";
		}
		incomming = "";
		/* ------------------------
		Place Keeps track of read in charactors and compared them with the total size of the text.
		Inside loop, reads in charictors until the proper size is reached.
		When the proper length is reached, pushes the correctly sized line out a vector
		and resets the read in my_string.
		--------------------------- */
		while (place < housing.length() - 1){
			for (int loop = 0; loop < width && place < housing.length() - 1; loop++){  //for loop control lines written to vector.
				if (first == true && housing[place] == ' '){ width++; } // determines if the charictor is first on a line and also a space, if so increase the width and skip the write.
				else{ incomming += housing[place]; } // if it is not the first and not a space, then apend the char to the string for output
				first = false;// set first = false, as we are through the loop once
				++place; // increment the place in the original string regardless of space status.
			}
			if (housing[place - 1] != ' ' && housing[place - 1] != '.'){ // if the word is running over the line then add a -
				incomming += '-';
			}
			lines.push_back(incomming); // push into the vector the completely formatted line
			incomming = ""; // clear the incomming my_string
			width = text_width; // ensure width = proper length regardless of first char space status
			first = true; // set first back to true, to start the loop back on first char.
		}
	}
	void Display_Output(vector<my_string>& text){
		cout << "The formated text is:\n";
		for (unsigned i = 0; i < text.size(); i++){
			cout << text[i] << endl;
		}
	}
	void Save_Output(vector<my_string>& text){
		ofstream OutFile("data.out"); // open file for output, erases and data.out that exists
		if (!OutFile.is_open()){
			cout << "output.dat did not open\n";
			return;
		}
		for (unsigned i = 0; i < text.size(); i++){ // send output to file
			OutFile << text[i];
			OutFile << endl;
		}
		OutFile.close(); // close file
	}
}
