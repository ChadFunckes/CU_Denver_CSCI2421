#include "functions.h"
#include <string>
#include <fstream>
#include "RoloAVL.h"

using namespace std;
namespace rolo {
	void mainMenu(roloAVL& mainData) {
		int menuInput, tempint;
		string tempString;
		Node<rolodex>* foundID = NULL;
		ifstream inFile; ofstream outFile;
		do {
			cout << endl << endl;
			cout << "(1) Load a file into the database\n"
				<< "(2) Add a person into the database\n"
				<< "(3) Delete a person from the database\n"
				<< "(4) Modify a person by ID#\n"
				<< "(5) Search for a person in the database\n"
				<< "(6) List people in the database\n"
				<< "(7) Choose Custom Display options\n"
				<< "(8) Send Custom Display info to a file (NOT a database save)\n"
				<< "(9) Write the current database out to a file (save databse)\n"
				<< "(50) Clear the working database (does not save, save first!)\n"
				<< "(99) Exit\n";
			cin >> tempString;
			if (isdigit(tempString[0])) menuInput = atoi(tempString.c_str());
			else menuInput = 20;
			switch (menuInput) {
			case (1) :
				cout << "\nEnter a filename to load: ";
				cin >> tempString;
				inFile.open(openFile(0, tempString).c_str());
				if (inFile.is_open()) { loadInData(inFile, mainData); inFile.close(); } // if the filename passes and opens, load data.
				break;
			case(2) :
				mainData.Add_Person();
				break;
			case(3) :
				cout << "\nEnter an ID# to delete\n";
				cin >> tempString;
				if (isdigit(tempString[0])) {
					tempint = atoi(tempString.c_str());
					mainData.Delete(tempint);
				}
				else cout << "Enter a valid ID#\n";
				break;
			case(4) :
				do {
					cout << "\nEnter an ID#: ";
					cin >> tempString;
					if (isdigit(tempString[0])) {
						tempint = atoi(tempString.c_str());
						foundID = mainData.FindID(tempint);
						if (foundID != NULL) {
							mainData.ModID(foundID); // modify the ID
							foundID = NULL;
							tempint = -1;
						}
					}
					if (tempint != -1)
						cout << "That ID was not found, enter a new ID or type -1 to exit\n";
				} while (tempint != -1);
				break;
			case(5) :
				mainData.Search();
				break;
			case(6) :
				mainData.CustomDisplay(cout);
				break;
			case(7) :
				mainData.chooseDisplayOptions();
				mainData.CustomDisplay(cout);
				break;
			case(8) :
				cout << "\nEnter file name for output: ";
				cin >> tempString;
				outFile.open(tempString.c_str());
				if (outFile.is_open()) {
					mainData.chooseDisplayOptions();
					mainData.CustomDisplay(outFile);
					outFile.close();
				}
				else cout << "File did not open correctly, please try again\n";
				break;
			case(9) :
				cout << "Enter the name of the file to output to: \n";
				cin >> tempString;
				mainData.WriteOut(tempString);
				break;
			case(50) :
				mainData.ClearTree();
				break;
			case(99) :
				return;
			default:
				cout << "Please select a valid menu option to continue.\n";
			}
		} while (menuInput != 99);
	}
	string openFile(int type, string filename) {
		ifstream theFile;
		// type 1 occurs when no file was specified at run time
		if (type == 1) {
			cout << "No filename was specified at run time\n"
				<< "If you wish to open a current database file please enter the name of the file\n"
				<< "or type 'NONE' to continue without a file\n";
			cin >> filename;
			if (stoupper(filename) == "NONE")
				return filename;
			theFile.open(filename.c_str());
			if (!theFile.is_open()) {
				filename = openFile(2, filename);
				return filename;
			}
		}
		//type 2 occurs when the filename was not correct
		else if (type == 2) {
			do {
				cout << "The file " << filename << " was not found in the working directory\n"
					<< "Please enter a valid filename or type 'NONE' to continue without a file\n";
				cin >> filename;
				if (stoupper(filename) == "NONE")
					return filename;
				theFile.open(filename.c_str());
			} while (!theFile.is_open());
		}
		// default case
		theFile.open(filename.c_str());
		if (!theFile.is_open()) // if the filename is not correct handle
			openFile(2, filename);

		return filename;
	}
	bool loadInData(ifstream& inFile, roloAVL& mainData) {
		if (!inFile.is_open()) // Check open flag.
			return false;

		rolodex temp;
		affiliate tempafil;
		int tempID;
		string tempString;

		while (!inFile.eof()) {
			// get ID from the File
			tempID = inFile.peek();
			if (!isdigit(tempID)) {
				if (tempID != -1) {
					cout << "File Error: Record must begin with a valid ID\n";
					return false;
				}
				return true; // there was an extra line break at the end
			}
			else {
				inFile >> tempID;
				temp.set_ID(tempID);
				inFile.ignore();
			}
			// get first name from the file
			getline(inFile, tempString, '\n');
			temp.set_first(tempString);
			// get middle name from the file
			getline(inFile, tempString, '\n');
			temp.set_middle(tempString);
			// get last name from the file
			getline(inFile, tempString, '\n');
			temp.set_last(tempString);
			// get company name
			getline(inFile, tempString, '\n');
			temp.set_company(tempString);
			// get home phone
			getline(inFile, tempString, '\n');
			temp.set_home(tempString);
			// get office phone
			getline(inFile, tempString, '\n');
			temp.set_office(tempString);
			// get email
			getline(inFile, tempString, '\n');
			temp.set_email(tempString);
			// get mobile number
			getline(inFile, tempString, '\n');
			temp.set_mobile(tempString);
			// get street address
			getline(inFile, tempString, '\n');
			temp.set_street(tempString);
			// get city
			getline(inFile, tempString, '\n');
			temp.set_city(tempString);
			// get state
			getline(inFile, tempString, '\n');
			temp.set_state(tempString);
			// get zip code
			getline(inFile, tempString, '\n');
			temp.set_zip(tempString);
			// get country
			getline(inFile, tempString, '\n');
			temp.set_country(tempString);
			// get affiliates
			while (inFile.peek() != '|') { // as long as the record has not ended
				getline(inFile, tempString, ','); // put in data until a comma
				if (tempString != "") tempafil.set_first(tempString); // if there was data, write it to affiliate
				getline(inFile, tempString, ','); // store the data until the comma
				if (tempString != "") tempafil.set_last(tempString); // if there is nothing to write, don't write
				else inFile.ignore();
				getline(inFile, tempString, ',');
				if (tempString != "") tempafil.set_mobile(tempString);
				getline(inFile, tempString, ';');
				if (tempString != "") tempafil.set_email(tempString);
				inFile.ignore();
				temp.add_affiliate(tempafil); // add affiliate to temp rolodex
				tempafil.clear_affil(); // clear affiliate for new add
			}
			// add to AVL tree
			mainData.Insert(temp);
			// clear temp for new person
			temp.clear_data();
			// clear | marker
			getline(inFile, tempString, '\n');
		}
		return true;
	}
}