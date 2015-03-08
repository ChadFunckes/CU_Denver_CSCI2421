// Chad S Funckes
// CSCI 2421
//
// Main functions implementation for HW5 (linked lists)
// Please see functions.h for documentation

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cassert>
#include "node1.h"
#include "functions.h"

using namespace std;
using namespace main_savitch_5;

namespace FUNCKES_MAIN_HW5{
	node* Get_list(){
		string input, tokens; // original input string and it's tokens 
		ifstream inFile;
		node *head; // pointer to the begining of the list
		head = NULL;
		node *loc; // working pointer for the location of read in for the list
		loc = NULL;

		/// get the file from the user ///
		while (!inFile.is_open()){
			cout << "Enter a File name to get the words from:\n";
			getline(cin, input);

			inFile.open(input.c_str()); // converted to C-string for G++ compiler
			if (!inFile.is_open()){
				cout << "The file specified could not be found!\n"
					<< "Enter a valid filename and try again.\n";
			}
		}
		/* fetch the first line for the text, use string stream to break the line into tokens, create the new node, pointed to
		by the pointer head.  Utilize the pointer loc to track the position for data to be inserted into and read in all the
		tokens into the linked list as seperate string entities.
		*/
		getline(inFile, input);
		stringstream stream(input);
		stream >> tokens;
		head = new node(tokens); // use first word to seed data read
		for (loc = head; stream >> tokens; loc = loc->link()){ // read in the rest of the words
			list_insert(loc, tokens);
		}
		/* If there are additional lines of text in the file, then read in those lines one at a time, seperate them
		into tokens, and continue to use the loc pointer to place the tokens into the list one after another.
		*/
		while (!inFile.eof()){
			getline(inFile, input);
			stringstream stream(input);
			for (loc; stream >> tokens; loc = loc->link())		{
				list_insert(loc, tokens);
			}
		}
		inFile.close(); // close the file.
		return head; // return the position of the start of the linked list.
	}

	void output_list(const node* head){
		assert(head != NULL);
		ofstream outFile;
		outFile.open("output.txt");
		if (!outFile.is_open()){
			cout << "file did not open correctly\n";
			return;
		}
		for (head; head; head = head->link()){
			outFile << head->data() << " ";
		}
		outFile.close(); // close the file.
		return;
	}
}