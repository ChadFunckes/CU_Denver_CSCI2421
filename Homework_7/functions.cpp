// CSCI 2421
// Chad S Funckes
/*
Implementation for the functions.h file.  For documentation please refer to functions.h
*/

#include "functions.h"
#include <string>
using namespace std;

namespace HW7{

	void display_menu(){

		cout << "Welcome to the gift idea list program\n"
			<< "Please make a selection from the list.\n\n"
			<< "1. Import list from a file.\n"
			<< "2. View Lists\n"
			<< "3. Add gift ideas to a persons list\n"
			<< "4. Remove gift ideas from a persons list\n"
			<< "5. Add a person to the list\n"
			<< "6. Remove a person from the list\n"
			<< "X. Exit from the program\n\n";
	}

	void fill_data(char* argv, map<string, set<string> > &list){
		ifstream inFile;
		string name_in, item_in;

		inFile.open(argv);
		if (!inFile.is_open()){
			cout << "The file " << argv << " specified did not open\n"
				<< "Open a file via the menu.\n";
			return;
		}
		while (!(inFile.eof())){ // fill the list from the file
			getline(inFile, name_in, ' ');
			inFile.ignore(100, '"');
			getline(inFile, item_in, '"');
			inFile.ignore(100, '\n');
			list[name_in].insert(item_in);
		}
		inFile.close(); // close the file.
		return; // return the list back to the function.
	}

	void fill_data(map<string, set<string> > &list){
		ifstream inFile;
		string input = "";
		string name_in;
		string item_in;

		while (!inFile.is_open()){
			cout << "Enter a filename to input data from, or type EXIT: ";
			cin >> input;
			if (input == "EXIT"){ return; } // exit function is exit typed
			inFile.open(input.c_str());
			if (!inFile.is_open()){
				cout << "There aprears to be a problem with the name you entered\n"
					<< "Please try again.\n";
			}
		}

		while (!(inFile.eof())){ // fill the list from the file
			getline(inFile, name_in, ' ');
			inFile.ignore(100, '"');
			getline(inFile, item_in, '"');
			inFile.ignore(100, '\n');
			list[name_in].insert(item_in);
		}
		inFile.close(); // close the file.
		return; // return the list back to the function.
	}

	void display_list(map<string, set<string> > &ideaList){
		if (ideaList.size() == 0){
			cout << "No list exists yet.\n";
			return;
		}
		cout << "The Current list is:\n";
		for (map<string, set<string> >::iterator ii = ideaList.begin(); ii != ideaList.end(); ++ii){
			cout << ii->first << " : \n";
			for (set<string>::iterator it = ii->second.begin(); it != ii->second.end(); ++it){
				cout << "  " << *it << endl;
			}
		}
	}

	void add_gift(map<string, set<string> > &ideaList){
		string name;
		string item;
		bool found = false;
		map<string, set<string> >::iterator it;

		while (found == false){
			cout << "Which person do you want to add gifts for?\n";
			cin >> name;

			for (map<string, set<string> >::iterator ii = ideaList.begin(); ii != ideaList.end() && found == false; ii++){
				if (ii->first == name)
					found = true;
			}
			if (found == true){
				it = ideaList.find(name);
				cout << "What gift would you like to add to " << it->first << "'s list?\n";
				cin.ignore();
				getline(cin, item);
				it->second.insert(item);
			}
			else{
				cout << name << " was not found in the list, please try again\n";
			}
		}
	}

	void remove_gift(map<string, set<string> > &ideaList){
		string name;
		string item;
		bool found_name = false;
		bool found_item = false;
		map<string, set<string> >::iterator it;

		while (found_name == false){
			cout << "Which person do you want to remove gifts from?\n";
			cin >> name;
			for (map<string, set<string> >::iterator ii = ideaList.begin(); ii != ideaList.end() && found_name == false; ii++){
				if (ii->first == name)
					found_name = true;
			}
			if (found_name == true){
				it = ideaList.find(name);
				while (found_item == false){
					cout << "What gift would you like to remove from " << it->first << "'s list?\n";
					cin.ignore();
					getline(cin, item);
					if (it->second.erase(item) == true){
						found_item = true;
						cout << item << " was deleted from the list" << endl;
					}
					else {
						cout << item << " was not found in the list, please try again\n" << endl;
					}
				}
			}
			else{
				cout << name << " was not found in the list, please try again\n";
			}
		}
	}

	void add_person(map<string, set<string> > &ideaList){
		string name;
		cout << "Enter a name to add to the list:\n";
		cin >> name;
		ideaList[name];
	}

	void rem_person(map<string, set<string> > &ideaList){
		string name;
		map<string, set<string> >::iterator it;
		bool found = false;

		while (found == false){
			cout << "Enter a name to remove from the list:\n";
			cin >> name;
			for (map<string, set<string> >::iterator ii = ideaList.begin(); ii != ideaList.end() && found == false; ii++){
				if (ii->first == name)
					found = true;
			}
			if (found == true){
				it = ideaList.find(name);
				it->second.clear();
				ideaList.erase(name);
			}
			else{
				cout << name << " was not found in the list, please try again\n";
			}
		}
	}

}