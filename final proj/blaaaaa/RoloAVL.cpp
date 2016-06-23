//Chad S Funckes
// RoloAVL Class implementation, see RoloAVL.h for documentation

#include "RoloAVL.h"
#include <fstream>
#include <cstdlib>
using namespace std;
namespace rolo {
typedef AVL<rolodex> avl;

void roloAVL::Add_Person() { // Adds a unconstructed new person to the tree
	rolodex temp;
	int ID;
	string input;
	cin.ignore();
	do {
		cout << "Current ID's in the system are: \n";
		PrintInOrderTraversal(cout);
		cout << "\nPlease enter an ID# not in use\n";
		getline(cin, input);
		if (isdigit(input[0])) {
			ID = atoi(input.c_str());
			Node<rolodex>* foundID = FindID(ID);
			if (foundID == NULL) temp.set_ID(ID);
			else input = "return";
		}
		else {
			input = "return";
		}
	} while (input == "return");
	cout << "Enter First Name: ";
	getline(cin, input);
	temp.set_first(input);
	cout << "Enter Last Name: ";
	getline(cin, input);
	temp.set_last(input);
	cout << "Enter Middle Name: ";
	getline(cin, input);
	temp.set_middle(input);
	cout << "Enter Company Name: ";
	getline(cin, input);
	temp.set_company(input);
	cout << "Enter Home Phone: ";
	getline(cin, input);
	temp.set_home(input);
	if (input != temp.get_home())
		cin.ignore();
	cout << "Enter Office Phone: ";
	getline(cin, input);
	temp.set_office(input);
	if (input != temp.get_office())
		cin.ignore();
	cout << "Enter Email: ";
	getline(cin, input);
	temp.set_email(input);
	if (input != temp.get_email())
		cin.ignore();
	cout << "Enter Mobile: ";
	getline(cin, input);
	temp.set_mobile(input);
	if (input != temp.get_mobile())
		cin.ignore();
	cout << "Enter Street Address: ";
	getline(cin, input);
	temp.set_street(input);
	cout << "Enter State: ";
	getline(cin, input);
	temp.set_state(input);
	cout << "Enter City: ";
	getline(cin, input);
	temp.set_city(input);
	cout << "Enter Zip code: ";
	getline(cin, input);
	temp.set_zip(input);
	if (input != temp.get_zip())
		cin.ignore();
	cout << "Enter Country: ";
	getline(cin, input);
	temp.set_country(input);
	do {
		cout << "Add affiliates? Y/N : ";
		getline(cin, input);
		if (stoupper(input) == "N") { Insert(temp); return; }
		else if (stoupper(input) == "Y") {
			string first, last, mobil, email;
			cout << "Enter Affiliate First Name: ";
			getline(cin, first);
			cout << "\nEnter Affiliate Last Name: ";
			getline(cin, last);
			cout << "\nEnter Affiliate Mobile Number, EX 000-000-0000: ";
			getline(cin, mobil);
			cout << "\nEnter Affiliate Email Address, EX test@thistest.com: ";
			getline(cin, email);
			temp.add_affiliate(first, last, mobil, email);
		}
		else
			cout << "Please enter Y or N...\n";
	} while (input != "bogus");
}
Node<rolodex>* rolo::roloAVL::FindID(int findme){
	return FindID(Root, findme);
}
Node<rolodex>* roloAVL::FindID(Node<rolodex>* N, int findme){ // private func, searches for ID around ROOT
	if (N == EMPTY) return NULL;
	else if (N->value.get_ID() == findme)
		return N;
	else if (findme < N->value.get_ID())
		return FindID(N->left, findme);
	else
		return FindID(N->right, findme);
}
void roloAVL::ModID(Node<rolodex>* N) {
	int menuInput;
	string newValue;
	Display(N);
	cout << endl;
	do {
		cout << "Enter the field to modify, or 99 to exit\n"
			<< "(1) ID\n"
			<< "(2) First Name\n"
			<< "(3) Middle Name\n"
			<< "(4) Last Name\n"
			<< "(5) Company\n"
			<< "(6) Home Phone\n"
			<< "(7) Office\n"
			<< "(8) Email\n"
			<< "(9) Mobile\n"
			<< "(10) Address\n"
			<< "(11) City\n"
			<< "(12) State\n"
			<< "(13) Zip Code\n"
			<< "(14) Country\n"
			<< "(15) Change affiliate info\n";
		cin >> newValue;
		if (isdigit(newValue[0])) menuInput = atoi(newValue.c_str());
		else menuInput = -1;
		//menuInput = Get_INT();
		if (menuInput == 99) return;
		if (menuInput < 0 || menuInput > 15) cout << "Please enter a valide choice between 1 and 15\n";
		else if (menuInput != 15) {
			cout << "Please enter the new field value\n";
			cin.ignore();
			getline(cin, newValue);
		}
	if (menuInput == 1) { // change ID...
		if (isdigit(newValue[0])) {
			int n;
			n = atoi(newValue.c_str());
			rolodex* newbie = new rolodex; // make two copies of this nodes data
			rolodex* oldie = new rolodex; // one for the old and one for the new
			*newbie = N->value; // change the data for the new to match
			*oldie = N->value; // and the old to match
			newbie->set_ID(n); // change the new ID to the number wanted			
			// ** Must call delete with the value and insert with new value, because
			// Just changing the ID will cause the tree to be out of whack and no way to balance.
			Delete(*oldie); // Call delete on the original tree with the value of the old ID 
			Insert(*newbie); // Insert the copy with modified ID back into the tree. 
			N = AVL<rolodex>::Search(*newbie); // set this functions N (Node<rolodex>*) to the item just emplaced.
			delete newbie; // free the copy in memory
			delete oldie; // free the copy in memory 
		}
		else cout << "Invalid input, start again\n";
	} 
	else if (menuInput == 2) N->value.set_first(newValue);
	else if (menuInput == 3) N->value.set_middle(newValue);
	else if (menuInput == 4) N->value.set_last(newValue);
	else if (menuInput == 5) N->value.set_company(newValue);
	else if (menuInput == 6) N->value.set_home(newValue);
	else if (menuInput == 7) N->value.set_office(newValue);
	else if (menuInput == 8) N->value.set_email(newValue);
	else if (menuInput == 9) N->value.set_mobile(newValue);
	else if (menuInput == 10) N->value.set_street(newValue);
	else if (menuInput == 11) N->value.set_city(newValue);
	else if (menuInput == 12) N->value.set_state(newValue);
	else if (menuInput == 13) N->value.set_zip(newValue);
	else if (menuInput == 14) N->value.set_country(newValue);
	else if (menuInput == 15) N->value.modify_affiliates();
	} while (menuInput < 0 || menuInput > 15);
	return;
}	
void roloAVL::Display(Node<rolodex>* N) {
	cout << "ID:           " << N->value.get_ID()
		<< "\nFirst Name: " << N->value.get_first()
		<< "\nMiddle Name:" << N->value.get_middle()
		<< "\nLast Name:  " << N->value.get_last()
		<< "\nCompany:    " << N->value.get_company()
		<< "\nHome Phone: " << N->value.get_home()
		<< "\nOffice:     " << N->value.get_office()
		<< "\nEmail:      " << N->value.get_email()
		<< "\nMobile:     " << N->value.get_mobile()
		<< "\nAddress:    " << N->value.get_street()
		<< "\nCity:       " << N->value.get_city()
		<< "\nState:      " << N->value.get_state()
		<< "\nZip Code:   " << N->value.get_zip()
		<< "\nCountry:    " << N->value.get_country()
		<< "\n------------------------------------\n";
	N->value.show_affiliates(cout);
}
void roloAVL::Search(){
map<int, ECsearch> criteria; // a map that specifies Exact or Contains search and the fild text to search on
roloAVL results; // this will be the search results tree
ofstream outFile; // output file stream for search output to file
int menuInput;
string menu;
do {
	cout << "This search is an inclusion search...\n"
		<< "To use this search, first choose a search field\n"
		<< "Once you have chosen the search filed, you will be prompted\n"
		<< "If you want an (E) exact search in that field or a (C) field contains\n"
		<< "type of search.  Next you will prompted to enter the text to search, in only that field\n"
		<< "You will then return to the menu, until you specify ALL of the criteria you want to ADD\n"
		<< "To the searches result.  To remove a field from search, select the number again.\n"
		<< "Upon completion of selection, enter 15 to conduct search.\n"
		<< "If you later want to narrow your search, there will be an exclusion search that can be performed\n"
		<< "After this search result is made\n";

	SearchMenu(criteria);

	// === Execute search ====
	if (criteria.size() != 0) // if nothing sepcified then, results will be EMPTY and menu will return, but no need to search.
	Search(criteria, results, Root); // search for the results as specified in the criteria map.
	if (results.Root == results.EMPTY) { // if there was no results do this.....
		cout << "Nothing was found in the search, please try again...\n";
		return;
		menuInput = 99; // value will cause return to search menu
	}
	else { // if there was results then show the results menu
		do {
			Node<rolodex>* found = NULL; // set pointer to found object NULL
			cout << "Search results were: \n";
			results.CustomDisplay(cout); // call display basic from the results tree, around result tree's root.
			cout << "\nPlease make a menu selection: \n"
				<< "1. Edit an ID in this search\n"
				<< "2. Further refine on this search \n"
				<< "3. Delete an ID found in this search \n"
				<< "4. Change Search Display options\n"
				<< "5. Output Search results to a file\n"
				<< "99. Exit this search\n";
			cin >> menu;
			if (isdigit(menu[0])) menuInput = atoi(menu.c_str());
			if (menuInput == 99) return;
			if (menuInput == 1) {  // edit info on a searched id 
				cout << "Enter ID :\n";
				cin >> menu;
				if (isdigit(menu[0])) {
					menuInput = atoi(menu.c_str());
					found = FindID(menuInput); // set found pointer to the item in the original tree
					ModID(found);				// Modify the item in the original tree.
					results.DeallocMemory(results.Root); // clear the search tree
					results.Root = results.EMPTY; // set results back to empty value
					cout << "ID " << menuInput << " modifed....\n";
					return;
				}
				else { cout << "Invalid ID Specified\n"; menuInput = 20; }
			}
			else if (menuInput == 2) { // return to refine search to change cirteria
				cout << "\nThere are two way to refine search: \n"
					<< "1. Eliminiate items from search.\n"
					<< "2. Add to/change search criteria.\n"
					<< "3. Change Search Display options\n"
					<< "4. Output these results to a file\n";
				cin >> menu;
				if (isdigit(menu[0])) menuInput = atoi(menu.c_str());
				else menuInput = 20;
				
				if (menuInput == 1) {
					map<int, ECsearch> eCriteria;
					roloAVL OrigResults;
					OrigResults.Copy(results, OrigResults);
					cout << "This is an eliminations search.....\n"
						<< "This menu works similar to the inclusion search just performed\n"
						<< "Only anything you specify here will be EXCLUDED, from the search results\n"
						<< "you just obtained...for example, if you searched all first names with the letter T\n"
						<< "and now you want to exclude from those results, all of them will middle names contining Q\n"
						<< "Specify that here.  The search results will continue to be narrowed upon your inputs"
						<< "to this menu\n";
					SearchMenu(eCriteria);
					ElimSearch(eCriteria, results, OrigResults, OrigResults.Root); // deleted items from results as they apear matched in OrigResults
					 // OrigResults is deconstructed when this scope is left and that will free the memory.
					menuInput = 20; // back to the top of this menu with new results list
				}
				else if (menuInput == 2) { // gp back and re-make the search results
					results.DeallocMemory(results.Root); // clear the results tree
					results.Root = results.EMPTY; // set results root, back to empty value
					menuInput = 99; // exit this menu, return to upper menu
				}
				else if (menuInput == 3) {
					results.chooseDisplayOptions(); // choose options
				}
				else if (menuInput == 4) {
					cout << "Enter a File Name: ";
					cin >> menu;
					outFile.open(menu.c_str());		// open file stream
					results.chooseDisplayOptions(); // verify disply options
					results.CustomDisplay(outFile); // send to file
					outFile.close();				// close file
				}
				else {	cout << "Invalid input\n"; menuInput = 20;	}

			}
			else if (menuInput == 3) { // delete a found ID
				cout << "Enter ID :\n";
				cin >> menu;
				if (isdigit(menu[0])) {
					menuInput = atoi(menu.c_str());
					rolodex* deletethis = new rolodex(menuInput); // create a rolodex type pointer, constructed with ID of menuInput
					Delete(*deletethis);						 // call delete on using that new construction
					results.Delete(*deletethis);				// call delete on the results tree
					delete deletethis;					 // clear the memory used for rolodex obj, pointer will be out of scope in 1 line.
					menuInput = 20; // exit lower menu, return to upper menu
				}
				else { cout << "Invalid ID Specified\n"; menuInput = 20; }
			}
			else if (menuInput == 4) {
				results.chooseDisplayOptions(); // choose options
			}
			else if (menuInput == 5) {
				cout << "Enter a File Name: ";
				cin >> menu;
				outFile.open(menu.c_str());		// open file stream
				results.chooseDisplayOptions(); // verify disply options
				results.CustomDisplay(outFile); // send to file
				outFile.close();				// close file
			}
			else if (menuInput == 99) {
				results.DeallocMemory(results.Root); // clear the results tree
				results.Root = results.EMPTY; // set results root, back to empty value
				criteria.clear(); // clear search criteria upon return to main menu
			}
			else cout << "Please Choose Valid Menu Option\n\n"; // bad menu item specified.

		} while (menuInput !=99);
	}
} while (menuInput == 99);// return to top menu
return; // nothing should ever get here, but....
}
void roloAVL::SearchMenu(map<int, ECsearch>& criteria) {
	map<int, ECsearch>::iterator it; // iterator for the map
	ECsearch ecpair; // this is a struct containing E or C (exact or contain) and the search string
	string menu;
	int menuInput;
	do {
		// if a search in this field will occur an E or a C will be to the right on display
		it = criteria.find(1); if (it != criteria.end()) cout << it->second.EC;
		else cout << " "; // If not a placeholder space
						  // After the field, if the field will be searched, place the search text after for display, else return.
		cout << " 1. First Name\t\t"; if (it != criteria.end()) cout << ": " << it->second.searchcrit << endl; else cout << endl;
		it = criteria.find(2); if (it != criteria.end()) cout << it->second.EC;
		else cout << " ";
		cout << " 2. Last Name\t\t";  if (it != criteria.end()) cout << ": " << it->second.searchcrit << endl; else cout << endl;
		it = criteria.find(3); if (it != criteria.end()) cout << it->second.EC;
		else cout << " ";
		cout << " 3. Middle Name\t";  if (it != criteria.end()) cout << ": " << it->second.searchcrit << endl; else cout << endl;
		it = criteria.find(4); if (it != criteria.end()) cout << it->second.EC;
		else cout << " ";
		cout << " 4. Company\t\t";  if (it != criteria.end()) cout << ": " << it->second.searchcrit << endl; else cout << endl;
		it = criteria.find(5); if (it != criteria.end()) cout << it->second.EC;
		else cout << " ";
		cout << " 5. Home Phone\t\t";  if (it != criteria.end()) cout << ": " << it->second.searchcrit << endl; else cout << endl;
		it = criteria.find(6); if (it != criteria.end()) cout << it->second.EC;
		else cout << " ";
		cout << " 6. Office phone\t";  if (it != criteria.end()) cout << ": " << it->second.searchcrit << endl; else cout << endl;
		it = criteria.find(7); if (it != criteria.end()) cout << it->second.EC;
		else cout << " ";
		cout << " 7. Email\t\t";  if (it != criteria.end()) cout << ": " << it->second.searchcrit << endl; else cout << endl;
		it = criteria.find(8); if (it != criteria.end()) cout << it->second.EC;
		else cout << " ";
		cout << " 8. Mobile Number\t";  if (it != criteria.end()) cout << ": " << it->second.searchcrit << endl; else cout << endl;
		it = criteria.find(9); if (it != criteria.end()) cout << it->second.EC;
		else cout << " ";
		cout << " 9. Street Address\t";  if (it != criteria.end()) cout << ": " << it->second.searchcrit << endl; else cout << endl;
		it = criteria.find(10); if (it != criteria.end()) cout << it->second.EC;
		else cout << " ";
		cout << " 10. City\t\t";  if (it != criteria.end()) cout << ": " << it->second.searchcrit << endl; else cout << endl;
		it = criteria.find(11); if (it != criteria.end()) cout << it->second.EC;
		else cout << " ";
		cout << " 11. State\t\t";  if (it != criteria.end()) cout << ": " << it->second.searchcrit << endl; else cout << endl;
		it = criteria.find(12); if (it != criteria.end()) cout << it->second.EC;
		else cout << " ";
		cout << " 12. Zip\t\t";  if (it != criteria.end()) cout << ": " << it->second.searchcrit << endl; else cout << endl;
		it = criteria.find(13); if (it != criteria.end()) cout << it->second.EC;
		else cout << " ";
		cout << " 13. Country\t\t";  if (it != criteria.end()) cout << ": " << it->second.searchcrit << endl; else cout << endl;
		it = criteria.find(14); if (it != criteria.end()) cout << it->second.EC;
		else cout << " ";
		cout << " 14. Affiliate Data\t";  if (it != criteria.end()) cout << ": " << it->second.searchcrit << endl; else cout << endl;
		cout << " 15. Execute Search\n";
		cout << " 99. Quit Search\n";
		cout << endl;
		cin >> menu;
		if (menu == "99") return;
		if (isdigit(menu[0])) menuInput = atoi(menu.c_str());
		else { cout << "Please enter a valid menu option\n"; menuInput = 20; } // display bad choice and set menuInput out of range to force do loop
		if (menuInput > 0 && menuInput < 15) {
			it = criteria.find(menuInput); // set the iterator to the menu input number
			if (it != criteria.end())// If the field was specified once...then delete the field
				criteria.erase(it);

			else if (it == criteria.end()) { // if the input has not been specified
				ecpair = Exact_Contain();  // then set the Exact/Contain and search field struct
				criteria.insert(pair<int, ECsearch>(menuInput, ecpair)); // and Insert it into the search map
			}
		}
	} while (menuInput != 15);
}
void roloAVL::ElimSearch(map<int, ECsearch>& eCriteria, roloAVL& results, roloAVL& origResults, Node<rolodex>* N) {
	map<int, ECsearch>::iterator it;
	size_t foundit;
	if (N == origResults.EMPTY) return; // for some reason the result tree is empty
	it = eCriteria.find(1);
	if (it != eCriteria.end()) { // If this is a section to search in
		if (it->second.EC == 'E' && stoupper(N->value.get_first()) == stoupper(it->second.searchcrit)) results.Delete(N->value); // Delete from results if found exact
		else { // delete from results if found contains
			foundit = stoupper(N->value.get_first()).find(stoupper(it->second.searchcrit));
			if (foundit != string::npos) results.Delete(N->value);
		}
	}
	it = eCriteria.find(2);
	if (it != eCriteria.end()) { // If this is a section to search in
		if (it->second.EC == 'E' && stoupper(N->value.get_last()) == stoupper(it->second.searchcrit)) results.Delete(N->value); // Delete from results if found exact
		else { // delete from results if found contains
			foundit = stoupper(N->value.get_last()).find(stoupper(it->second.searchcrit));
			if (foundit != string::npos) results.Delete(N->value);
		}
	}
	it = eCriteria.find(3);
	if (it != eCriteria.end()) { // If this is a section to search in
		if (it->second.EC == 'E' && stoupper(N->value.get_middle()) == stoupper(it->second.searchcrit)) results.Delete(N->value); // Delete from results if found exact
		else { // delete from results if found contains
			foundit = stoupper(N->value.get_middle()).find(stoupper(it->second.searchcrit));
			if (foundit != string::npos) results.Delete(N->value);
		}
	}
	it = eCriteria.find(4);
	if (it != eCriteria.end()) { // If this is a section to search in
		if (it->second.EC == 'E' && stoupper(N->value.get_company()) == stoupper(it->second.searchcrit)) results.Delete(N->value); // Delete from results if found exact
		else { // delete from results if found contains
			foundit = stoupper(N->value.get_company()).find(stoupper(it->second.searchcrit));
			if (foundit != string::npos) results.Delete(N->value);
		}
	}
	it = eCriteria.find(5);
	if (it != eCriteria.end()) { // If this is a section to search in
		if (it->second.EC == 'E' && stoupper(N->value.get_home()) == stoupper(it->second.searchcrit)) results.Delete(N->value); // Delete from results if found exact
		else { // delete from results if found contains
			foundit = stoupper(N->value.get_home()).find(stoupper(it->second.searchcrit));
			if (foundit != string::npos) results.Delete(N->value);
		}
	}
	it = eCriteria.find(6);
	if (it != eCriteria.end()) { // If this is a section to search in
		if (it->second.EC == 'E' && stoupper(N->value.get_office()) == stoupper(it->second.searchcrit)) results.Delete(N->value); // Delete from results if found exact
		else { // delete from results if found contains
			foundit = stoupper(N->value.get_office()).find(stoupper(it->second.searchcrit));
			if (foundit != string::npos) results.Delete(N->value);
		}
	}
	it = eCriteria.find(7);
	if (it != eCriteria.end()) { // If this is a section to search in
		if (it->second.EC == 'E' && stoupper(N->value.get_email()) == stoupper(it->second.searchcrit)) results.Delete(N->value); // Delete from results if found exact
		else { // delete from results if found contains
			foundit = stoupper(N->value.get_email()).find(stoupper(it->second.searchcrit));
			if (foundit != string::npos) results.Delete(N->value);
		}
	}
	it = eCriteria.find(8);
	if (it != eCriteria.end()) { // If this is a section to search in
		if (it->second.EC == 'E' && stoupper(N->value.get_mobile()) == stoupper(it->second.searchcrit)) results.Delete(N->value); // Delete from results if found exact
		else { // delete from results if found contains
			foundit = stoupper(N->value.get_mobile()).find(stoupper(it->second.searchcrit));
			if (foundit != string::npos) results.Delete(N->value);
		}
	}
	it = eCriteria.find(9);
	if (it != eCriteria.end()) { // If this is a section to search in
		if (it->second.EC == 'E' && stoupper(N->value.get_street()) == stoupper(it->second.searchcrit)) results.Delete(N->value); // Delete from results if found exact
		else { // delete from results if found contains
			foundit = stoupper(N->value.get_street()).find(stoupper(it->second.searchcrit));
			if (foundit != string::npos) results.Delete(N->value);
		}
	}
	it = eCriteria.find(10);
	if (it != eCriteria.end()) { // If this is a section to search in
		if (it->second.EC == 'E' && stoupper(N->value.get_city()) == stoupper(it->second.searchcrit)) results.Delete(N->value); // Delete from results if found exact
		else { // delete from results if found contains
			foundit = stoupper(N->value.get_city()).find(stoupper(it->second.searchcrit));
			if (foundit != string::npos) results.Delete(N->value);
		}
	}
	it = eCriteria.find(11);
	if (it != eCriteria.end()) { // If this is a section to search in
		if (it->second.EC == 'E' && stoupper(N->value.get_state()) == stoupper(it->second.searchcrit)) results.Delete(N->value); // Delete from results if found exact
		else { // delete from results if found contains
			foundit = stoupper(N->value.get_state()).find(stoupper(it->second.searchcrit));
			if (foundit != string::npos) results.Delete(N->value);
		}
	}
	it = eCriteria.find(12);
	if (it != eCriteria.end()) { // If this is a section to search in
		if (it->second.EC == 'E' && stoupper(N->value.get_zip()) == stoupper(it->second.searchcrit)) results.Delete(N->value); // Delete from results if found exact
		else { // delete from results if found contains
			foundit = stoupper(N->value.get_zip()).find(stoupper(it->second.searchcrit));
			if (foundit != string::npos) results.Delete(N->value);
		}
	}
	it = eCriteria.find(13);
	if (it != eCriteria.end()) { // If this is a section to search in
		if (it->second.EC == 'E' && stoupper(N->value.get_country()) == stoupper(it->second.searchcrit)) results.Delete(N->value); // Delete from results if found exact
		else { // delete from results if found contains
			foundit = stoupper(N->value.get_country()).find(stoupper(it->second.searchcrit));
			if (foundit != string::npos) results.Delete(N->value);
		}
	}
	it = eCriteria.find(14);
	if (it != eCriteria.end()) {
		if (it->second.EC == 'E' && N->value.has_affiliate(it->second.searchcrit) == true) results.Delete(N->value);
		else if (N->value.has_affiliate_contain(it->second.searchcrit) == true) results.Delete(N->value);
	}
		ElimSearch(eCriteria, results, origResults, N->left);
		ElimSearch(eCriteria, results, origResults, N->right);
		return;
}
void roloAVL::Search(map<int, ECsearch> criteria, roloAVL& results, Node<rolodex>* N){
map<int, ECsearch>::iterator it;
size_t foundit;
	if (N == EMPTY) return; // master tree is empty

		it = criteria.find(1);
		if (it != criteria.end()) { // if I should search in the first field
			if (it->second.EC == 'E' && stoupper(N->value.get_first()) == stoupper(it->second.searchcrit)) results.Insert(N->value); // if exact an matches insert
			else { // non exact match, then search the string, if it was found then insert into results
				foundit = stoupper(N->value.get_first()).find(stoupper(it->second.searchcrit));
				if (foundit != string::npos) results.Insert(N->value);
			}
		}
		it = criteria.find(2);
		if (it != criteria.end()) { // if I should search in the first field
			if (it->second.EC == 'E' && stoupper(N->value.get_last()) == stoupper(it->second.searchcrit)) results.Insert(N->value); // if exact an matches insert
			else { // non exact match, then search the string, if it was found then insert into results
				foundit = stoupper(N->value.get_last()).find(stoupper(it->second.searchcrit));
				if (foundit != string::npos) results.Insert(N->value);
			}
		}
		it = criteria.find(3);
		if (it != criteria.end()) { // if I should search in the first field
			if (it->second.EC == 'E' && stoupper(N->value.get_middle()) == stoupper(it->second.searchcrit)) results.Insert(N->value); // if exact an matches insert
			else { // non exact match, then search the string, if it was found then insert into results
				foundit = stoupper(N->value.get_middle()).find(stoupper(it->second.searchcrit));
				if (foundit != string::npos) results.Insert(N->value);
			}
		}
		it = criteria.find(4);
		if (it != criteria.end()) { // if I should search in the first field
			if (it->second.EC == 'E' && stoupper(N->value.get_company()) == stoupper(it->second.searchcrit)) results.Insert(N->value); // if exact an matches insert
			else { // non exact match, then search the string, if it was found then insert into results
				foundit = stoupper(N->value.get_company()).find(stoupper(it->second.searchcrit));
				if (foundit != string::npos) results.Insert(N->value);
			}
		}
		it = criteria.find(5);
		if (it != criteria.end()) { // if I should search in the first field
			if (it->second.EC == 'E' && stoupper(N->value.get_home()) == stoupper(it->second.searchcrit)) results.Insert(N->value); // if exact an matches insert
			else { // non exact match, then search the string, if it was found then insert into results
				foundit = stoupper(N->value.get_home()).find(stoupper(it->second.searchcrit));
				if (foundit != string::npos) results.Insert(N->value);
			}
		}
		it = criteria.find(6);
		if (it != criteria.end()) { // if I should search in the first field
			if (it->second.EC == 'E' && stoupper(N->value.get_office()) == stoupper(it->second.searchcrit)) results.Insert(N->value); // if exact an matches insert
			else { // non exact match, then search the string, if it was found then insert into results
				foundit = stoupper(N->value.get_office()).find(stoupper(it->second.searchcrit));
				if (foundit != string::npos) results.Insert(N->value);
			}
		}
		it = criteria.find(7);
		if (it != criteria.end()) { // if I should search in the first field
			if (it->second.EC == 'E' && stoupper(N->value.get_email()) == stoupper(it->second.searchcrit)) results.Insert(N->value); // if exact an matches insert
			else { // non exact match, then search the string, if it was found then insert into results
				foundit = stoupper(N->value.get_email()).find(stoupper(it->second.searchcrit));
				if (foundit != string::npos) results.Insert(N->value);
			}
		}
		it = criteria.find(8);
		if (it != criteria.end()) { // if I should search in the first field
			if (it->second.EC == 'E' && stoupper(N->value.get_mobile()) == stoupper(it->second.searchcrit)) results.Insert(N->value); // if exact an matches insert
			else { // non exact match, then search the string, if it was found then insert into results
				foundit = stoupper(N->value.get_mobile()).find(stoupper(it->second.searchcrit));
				if (foundit != string::npos) results.Insert(N->value);
			}
		}
		it = criteria.find(9);
		if (it != criteria.end()) { // if I should search in the first field
			if (it->second.EC == 'E' && stoupper(N->value.get_street()) == stoupper(it->second.searchcrit)) results.Insert(N->value); // if exact an matches insert
			else { // non exact match, then search the string, if it was found then insert into results
				foundit = stoupper(N->value.get_street()).find(stoupper(it->second.searchcrit));
				if (foundit != string::npos) results.Insert(N->value);
			}
		}
		it = criteria.find(10);
		if (it != criteria.end()) { // if I should search in the first field
			if (it->second.EC == 'E' && stoupper(N->value.get_city()) == stoupper(it->second.searchcrit)) results.Insert(N->value); // if exact an matches insert
			else { // non exact match, then search the string, if it was found then insert into results
				foundit = stoupper(N->value.get_city()).find(stoupper(it->second.searchcrit));
				if (foundit != string::npos) results.Insert(N->value);
			}
		}
		it = criteria.find(11);
		if (it != criteria.end()) { // if I should search in the first field
			if (it->second.EC == 'E' && stoupper(N->value.get_state()) == stoupper(it->second.searchcrit)) results.Insert(N->value); // if exact an matches insert
			else { // non exact match, then search the string, if it was found then insert into results
				foundit = stoupper(N->value.get_state()).find(stoupper(it->second.searchcrit));
				if (foundit != string::npos) results.Insert(N->value);
			}
		}
		it = criteria.find(12);
		if (it != criteria.end()) { // if I should search in the first field
			if (it->second.EC == 'E' && stoupper(N->value.get_zip()) == stoupper(it->second.searchcrit)) results.Insert(N->value); // if exact an matches insert
			else { // non exact match, then search the string, if it was found then insert into results
				foundit = stoupper(N->value.get_zip()).find(stoupper(it->second.searchcrit));
				if (foundit != string::npos) results.Insert(N->value);
			}
		}
		it = criteria.find(13);
		if (it != criteria.end()) { // if I should search in the first field
			if (it->second.EC == 'E' && stoupper(N->value.get_country()) == stoupper(it->second.searchcrit)) results.Insert(N->value); // if exact an matches insert
			else { // non exact match, then search the string, if it was found then insert into results
				foundit = stoupper(N->value.get_country()).find(stoupper(it->second.searchcrit));
				if (foundit != string::npos) results.Insert(N->value);
			}
		}
		it = criteria.find(14);
		if (it != criteria.end()) {
			if (it->second.EC == 'E' && N->value.has_affiliate(it->second.searchcrit) == true) results.Insert(N->value);
			else if (N->value.has_affiliate_contain(it->second.searchcrit) == true) results.Insert(N->value);
		}

	Search(criteria, results, N->left);
	Search(criteria, results, N->right);
	return;
}
void roloAVL::chooseDisplayOptions() {
	string input;
	int menu;
	do {
		cout << "\nChoose the fields you want displayed in custom display\n"
			<< "An X will appear by the fields that will display, choose a number\n"
			<< "To add a field, if a field is selected, choose again to deselect\n"
			<< "Select 99, or type exit to show results\n";
		if (display[0] == true) cout << "X ";
		else cout << "  ";
		cout << "1. First Name\n";
		if (display[1] == true) cout << "X ";
		else cout << "  ";
		cout << "2. Middle Name\n";
		if (display[2] == true) cout << "X ";
		else cout << "  ";
		cout << "3. Last Name\n";
		if (display[3] == true) cout << "X ";
		else cout << "  ";
		cout << "4. Company Name\n";
		if (display[4] == true) cout << "X ";
		else cout << "  ";
		cout << "5. Home Phone\n";
		if (display[5] == true) cout << "X ";
		else cout << "  ";
		cout << "6. Office Phone\n";
		if (display[6] == true) cout << "X ";
		else cout << "  ";
		cout << "7. Email\n";
		if (display[7] == true) cout << "X ";
		else cout << "  ";
		cout << "8. Mobile Number\n";
		if (display[8] == true) cout << "X ";
		else cout << "  ";
		cout << "9. Street Address\n";
		if (display[9] == true) cout << "X ";
		else cout << "  ";
		cout << "10. City\n";
		if (display[10] == true) cout << "X ";
		else cout << "  ";
		cout << "11. State\n";
		if (display[11] == true) cout << "X ";
		else cout << "  ";
		cout << "12. Zip Code\n";
		if (display[12] == true) cout << "X ";
		else cout << "  ";
		cout << "13. Country\n";
		if (display[13] == true) cout << "X ";
		else cout << "  ";
		cout << "14. Affiliates\n"
			<< "99. Finished with selection\n";
		cin >> input;
		if (input == "99" || stoupper(input) == "EXIT") return;
		if (isdigit(input[0])) menu = atoi(input.c_str());
		else menu = 20;
		if (menu < 15) {
			for (int i = 0; i < 14; i++) {
				if (menu == i + 1 && display[i] == false) display[i] = true;
				else if (menu == i + 1 && display[i] == true) display[i] = false;
			}
		}
	} while (menu != 99);
}
void roloAVL::CustomDisplay(ostream& outputStream) {
	CustomDisplay(outputStream, Root);
}
void roloAVL::CustomDisplay(ostream& outputStream, Node<rolodex>* N) {
	if (N == EMPTY) return;
	CustomDisplay(outputStream, N->left);
	outputStream << "ID: " << N->value.get_ID() << endl;

	if (display[0] == true) outputStream <<"First Name: "<< N->value.get_first() << endl;
	if (display[1] == true) outputStream <<"Middle Name: "<< N->value.get_middle() << endl;
	if (display[2] == true) outputStream <<"Last Name: "<< N->value.get_last() << endl;
	if (display[3] == true) outputStream <<"Company: "<< N->value.get_company() << endl;
	if (display[4] == true) outputStream <<"Home Phone: "<< N->value.get_home() << endl;
	if (display[5] == true) outputStream <<"Office Phone: "<< N->value.get_office() << endl;
	if (display[6] == true) outputStream <<"Email: "<< N->value.get_email() << endl;
	if (display[7] == true) outputStream <<"Mobile Phone: "<< N->value.get_mobile() << endl;
	if (display[8] == true) outputStream <<"Street Address: "<< N->value.get_street() << endl;
	if (display[9] == true) outputStream <<"City: "<< N->value.get_city() << endl;
	if (display[10] == true) outputStream <<"State: "<< N->value.get_state() << endl;
	if (display[11] == true) outputStream <<"Zip Code: "<< N->value.get_zip() << endl;
	if (display[12] == true) outputStream << "Country: "<< N->value.get_country() << endl;
	if (display[13] == true) {
		outputStream << "--------------\n";
		N->value.show_affiliates(outputStream);
	}
	CustomDisplay(outputStream, N->right);
}
void roloAVL::WriteOut(string outputFile) {
	ofstream outFile(outputFile.c_str());
	if (!outFile.is_open()) {
		cout << "Error opening output file for write\n";
		return;
	}
	WriteOut(Root, outFile);
}
void roloAVL::WriteOut(Node<rolodex>* N, ofstream& outFile) { // write tree to a file in order
	if (N == EMPTY) return;
	WriteOut(N->left, outFile);
	outFile << N->value.get_ID() << endl;
	outFile << N->value.get_first() << endl;
	outFile << N->value.get_middle() << endl;
	outFile << N->value.get_last() << endl;
	outFile << N->value.get_company() << endl;
	outFile << N->value.get_home() << endl;
	outFile << N->value.get_office() << endl;
	outFile << N->value.get_email() << endl;
	outFile << N->value.get_mobile() << endl;
	outFile << N->value.get_street() << endl;
	outFile << N->value.get_city() << endl;
	outFile << N->value.get_state() << endl;
	outFile << N->value.get_zip() << endl;
	outFile << N->value.get_country() << endl;
	N->value.FileWrite_affilliates(outFile);
	outFile << "|" << endl;
	WriteOut(N->right, outFile);
}
ECsearch roloAVL::Exact_Contain(){ // helper to specify E or C and the search string
ECsearch EXC;
string option;
do{
cout << "Search (E)xact or (C)ontains?\n";
cin >> option;
if (toupper(option[0]) == 'E') EXC.EC = toupper(option[0]); 
else if (toupper(option[0]) == 'C') EXC.EC = toupper(option[0]); 
else cout << "Input must be E - for exact or C - for contains\n";
} while (toupper(option[0]) != 'E' && toupper(option[0]) != 'C');
cout << "Enter text to search for:\n";
cin >> EXC.searchcrit;
return EXC;
}
}
