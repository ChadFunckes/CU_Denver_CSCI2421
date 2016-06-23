//Chad S Funckes
// Rolodex database using AVL tree data structure
/*
Purpose: This is th main driver file for the rolodex program.  It
		contains the main rolodex file, globaly used.  Opens
		the initial database from either command line, or user input
		and calls the main menu for the system.
*/

#include "RoloAVL.h"
#include "functions.h"
#include <iostream>
#include <fstream>
using namespace rolo;
using namespace std;
int main(int argc, char** argv) {
roloAVL mainData; // this is the main tree store
ifstream inFile;  // Input File object
	
cout << "Welcome to the Rolodex manager: \n";

if (argc < 2) {						 // check if there was command line input
	inFile.open(openFile().c_str()); // if so call openFile to handle it
}
else
	inFile.open(openFile(0, argv[1]).c_str()); // if not call openFile to get a file

if (inFile.is_open()) {				// load in inputs if file was opened
	loadInData(inFile, mainData);
	inFile.close();					// close the input file
}
// ***************** Initial File has been loaded into tree **********************	  
	mainMenu(mainData);
}