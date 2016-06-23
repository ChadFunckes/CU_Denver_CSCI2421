//Chad S Funckes
// Purpose: Functions used in the main program.
/*
functions: 

	openFile(int, string)
		POST: Checks if the input filename exists...if it does not, gets one.
	LoadInData(ifstream& roloAVL&)
		PRE: An open input file stream and an object to load the data into.
		Post load the data from a file into a roloAVL tree.
	MainMenu(roloAVL&)
		Performs main menu functions
*/

#ifndef MAIN_FUNCTIONS
#define MAIN_FUNCTIONS
//#include <iostream>
#include <fstream>
#include <string>
#include "RoloAVL.h"
//#include "rolodex.h"

using namespace std;
namespace rolo {
	string openFile(int type=1, string filename = "");
	bool loadInData(ifstream&, roloAVL&);
	void mainMenu(roloAVL&);
}
#endif