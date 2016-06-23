// CSCI 2421
// Chad S Funckes
/*
This program uses STL classes to make a gift list.  It takes input from a file with names listed first and a gift in quotes on each line.
ex: Tom "book"
The input file can be sepcified at run time: HW7 input.dat, or within the program.  You can add multiple input files togather.

The names on the list can not repeat and gift ideas for any person can not repeat.  To accomplish this I used an
STL called set for the gift lists and nested that inside an STL map that uses the name as the key.
*/

#include <iostream>
#include <string>
#include <map>
#include <set>
#include "functions.h"

using namespace std;
using namespace HW7;

int main(int argc, char* argv[]){
	char menu_inputs='0'; 
	map<string, set<string> > ideaList;
	//// Section checks if there was a file specified at run time
	while (argc > 1){
		cout << "An input file named " << argv[1] << "was sepcified at run time\n"
			 << "Do you wish to use this input file? (Y/N)\n";
		cin >> menu_inputs;
		if (toupper(menu_inputs) == 'Y'){
			fill_data(argv[1], ideaList);
			break;
		}
		if (toupper(menu_inputs) == 'N'){
			break;
		}
		else{
			cout << "Please Enter either Y or N\n";
		}
	}
	//// Start Program menu	
	while (menu_inputs != 'X'){
		display_menu();
		cin >> menu_inputs;
		cin.ignore();
		menu_inputs = toupper(menu_inputs);
		
		switch (menu_inputs){
		case '1':
			//import from file
			fill_data(ideaList);
			break;
		case '2':
			// view list
			display_list(ideaList);
			break;
		case '3':
			// add gift to a list
			display_list(ideaList);
			add_gift(ideaList);
			break;
		case '4':
			// remove from a list
			display_list(ideaList);
			remove_gift(ideaList);
			break;
		case '5':
			// add a person to the lists
			add_person(ideaList);
			break;
		case '6':
			// remove a person from the list
			display_list(ideaList);
			rem_person(ideaList);
			break;
		case 'X':
			break;
		default:
			cout << "Please enter a menu item from the list\n";
		}
	}
}
