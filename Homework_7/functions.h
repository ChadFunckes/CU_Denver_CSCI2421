// CSCI 2421
// Chad S Funckes
/*
Provides the definitions for functions to be used in HW7

Functions:

display_Menu();
	post condition: Program menu is displayed;
	
void fill_data(char* argv, map<string, set<string> > &list);
	post condition: The input map and set combo is filled by the information from the file specified at command line

void fill_data(map<string, set<string> > &list);
	post condition:  the map and set combo is addended by the information in a file specified

void display_list(map<string, set<string> > &ideaList);
	post condition:  the map and set combo is output to the screen

void add_gift(map<string, set<string> > &ideaList);
	post condition:  A gift is added to the list of the person specified.

void remove_gift(map<string, set<string> > &ideaList);
	post condition:  A gift is removed from the list of the person specified.

void add_person(map<string, set<string> > &ideaList);
	post condition: A person is added to the list to get gifts for

void rem_person(map<string, set<string> > &ideaList);
	post condition: a person is removed from the list to get gifts for
*/


#ifndef FUNCKES_HW6_FUNCTIONS
#define FUNCKES_HW6_FUNCTIONS

#include <iostream>
#include <fstream>
#include <map>
#include <set>
#include <string>
using namespace std;
namespace HW7{
	void display_menu();
	void fill_data(char* argv, map<string, set<string> > &list);
	void fill_data(map<string, set<string> > &list);
	void display_list(map<string, set<string> > &ideaList);
	void add_gift(map<string, set<string> > &ideaList);
	void remove_gift(map<string, set<string> > &ideaList);
	void add_person(map<string, set<string> > &ideaList);
	void rem_person(map<string, set<string> > &ideaList);
}
#endif
