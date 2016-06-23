// CSCI 2421
// IMPLEMENTATION OF ROLODEX AND AFFILIATE CLASS, SEE ROLODEX.H FOR DOCUMENTATION

#include "rolodex.h"
#include <fstream>
#include <iostream>
#include <string.h>
#include <cstdlib>

using namespace std;

namespace rolo{
// CCONSTRUCTORS

	// Affiliate class constructors
	affiliate::affiliate(){
		first = "not specified";
		last = "not specified";
		mobile = "000-000-0000";
		email = "not specified";
	}
	affiliate::affiliate(string first, string last){
		this->first = check_name(first);
		this->last = check_name(last);
		mobile = "000-000-0000";
		email = "not specified";
	}
	affiliate::affiliate(string first, string last, string mobile, string email){
		this->first = check_name(first);
		this->last = check_name(last);
		this->mobile = check_phone(mobile);
		this->email = check_email(email);
	}
	
	// Rolodex constructors
	rolodex::rolodex(){  // create empty
		ID = 0;
		first = "not specified";
		last = "not specified";
		middle = "not specified";
		company = "not specified";
		home = "not specified";
		office = "not specified";
		email = "not specified";
		mobile = "not specified";
		street = "not specified";
		city = "not specified";
		state = "not specified";
		zip = "not specified";
		country = "not specified";
		vector<affiliate> affil;
	}
	rolodex::rolodex(int ID){
		this->ID = ID;
	}
	rolodex::rolodex(int ID, string first, string last, string middle){ // set name only
		this->ID = check_ID(ID);
		this->first = check_name(first);
		this->last = check_name(last);
		this->middle = check_name(middle);
		company = "not specified";
		home = "not specified";
		office = "not specified";
		email = "not specified";
		mobile = "not specified";
		street = "not specified";
		city = "not specified";
		state = "not specified";
		zip = "not specified";
		country = "not specified";
		vector<affiliate> affil;
	} 
	rolodex::rolodex(int, string first, string last, string middle, string company, string home,
		string office, string email, string mobile, string street, string city,
		string state, string zip, string country, vector<affiliate> affil){
		this->ID = check_ID(ID);
		this->first = check_name(first);
		this->last = check_name(last);
		this->middle = check_name(middle);
		this->company = company;
		this->home = check_phone(home);
		this->office = check_phone(office);
		this->email = check_email(email);
		this->mobile = check_phone(mobile);
		this->street = street;
		this->city = city;
		this->state = state;
		this->zip = check_zip(zip);
		this->country = country;
		this->affil = affil;
	}

// MUTATORS
	// Affiliate class mutators
	void affiliate::set_first(string input){
		first = check_name(input); // limit to 20 chars
	}
	void affiliate::set_last(string input){
		last = check_name(input); // limit to 20 chars
	}
	void affiliate::set_mobile(string input){
		mobile = check_phone(input); // set phone IAW check_phone function
	}
	void affiliate::set_email(string input){
		email = check_email(input); // set email IAW check_email function
	}
	void affiliate::clear_affil() {
		first = "not specified";
		last = "not specified";
		mobile = "000-000-0000";
		email = "not specified";	
	}

	// Rolodex class mutators
	void rolodex::set_ID(int id){
		this->ID = check_ID(id); 
	}
	void rolodex::set_first(string name){
		first = check_name(name);
	}
	void rolodex::set_last(string name){
		last = check_name(name);
	}
	void rolodex::set_middle(string name){
		middle = check_name(name);
	}
	void rolodex::set_company(string name){
		company = check_name(name);
	}
	void rolodex::set_home(string phone){
		home = check_phone(phone);
	}
	void rolodex::set_office(string phone){
		office = check_phone(phone);
	}
	void rolodex::set_email(string email){
		this->email = check_email(email);
	}
	void rolodex::set_mobile(string phone){
		mobile = check_phone(phone);
	}
	void rolodex::set_street(string street){
		this->street = street;
	}
	void rolodex::set_city(string city){
		this->city = city;
	}
	void rolodex::set_state(string state){
		this->state = state;
	}
	void rolodex::set_zip(string zip){
		this->zip = check_zip(zip);
	}
	void rolodex::set_country(string country){
		this->country = country;
	}
	void rolodex::add_affiliate(affiliate input){
		affil.push_back(input);
	}
	void rolodex::add_affiliate(string first, string last, string mobil, string email){
		affil.push_back(affiliate(first, last, mobil, email)); // affiliate constructor will check inputs for correctness.
	}
	void rolodex::modify_affiliates()
	{
		int find, menu;
		string input;
		unsigned i;
		do {
		cout << "\nCurrent Affilliates are:\n";
		for (i = 0; i < affil.size(); i++) {
			cout << "Affiliate number: " << i + 1 << endl
				<< "Name:\t" << affil[i].get_first() << " " << last << endl
				<< "Mobile:\t" << affil[i].get_mobile() << endl
				<< "Email:\t" << affil[i].get_email() << endl
				<< "---\n";
		}
			find = -1;
			cout << "Enter affiliate number to modify, or type add, delete, or exit to quit: \n";
			cin >> input;
			if (isdigit(input[0])) find = atoi(input.c_str());
			else if (stoupper(input) == "ADD") {
				string first, last, mobil, email;
				cout << "Enter Affiliate First Name: ";
				cin >> first;
				cout << "\nEnter Affiliate Last Name: ";
				cin >> last;
				cout << "\nEnter Affiliate Mobile Number, EX 000-000-0000: ";
				cin >> mobil;
				cout << "\nEnter Affiliate Email Address, EX test@thistest.com: ";
				cin >> email;
				add_affiliate(first, last, mobil, email);
				find = 0;
			}
			else if (stoupper(input) == "DELETE") { delete_affiliates(); find = 0; } //delete stuff
			else if (stoupper(input) == "EXIT") return;
			if (find < 0 || find > i)
				cout << "Enter an affiliate number between 1 and " << i + 1 << endl;
		} while (find <= 0 || find > i);

		do {
			cout << "Affiliate number" << find << endl
				<< "Name:\t" << affil[find - 1].get_first() << " " << affil[find-1].get_last() << endl
				<< "Mobile:\t" << affil[find - 1].get_mobile() << endl
				<< "Email:\t" << affil[find - 1].get_email() << endl
				<< "\n"
				<< "Please enter field to change:\n"
				<< "(1) First Name\n"
				<< "(2) Last Name\n"
				<< "(3) Mobile\n"
				<< "(4) Email\n"
				<< "(9) Exit\n\n";
			cin >> input;
			if (!isdigit(input[0])) menu = 20;
			else menu = atoi(input.c_str());
				 switch(menu) {
				 case (1) :
					 cout << "Enter a new first name: \n";
					 cin >> input;
					 affil[find - 1].set_first(input);
					 cin.ignore();
					 break;
				 case (2) :
					 cout << "Enter a new last name: \n";
					 cin >> input;
					 affil[find - 1].set_last(input);
					 cin.ignore();
					 break;
				 case (3) :
					 cout << "Enter a new mobile number, format: 000-000-0000\n";
					 cin >> input;
					 affil[find - 1].set_mobile(input);
					 cin.ignore();
					 break;
				 case(4) :
					 cout << "Enter a new email address:\n";
					 cin >> input;
					 affil[find - 1].set_email(input);
					 cin.ignore();
					 break;
				 case (9) :
					 cin.ignore();
					 return;
				 default:
					 cin.ignore();
					 cout << "please choose a valid menu option\n";
				 }
		} while (find != 9);
	}
	void rolodex::delete_affiliates() {
		int menu;
		string input;
		unsigned i;
		do {
			cout << "\nCurrent Affilliates are:\n";
			for (i = 0; i < affil.size(); ++i) {
				cout << "Affiliate number " << i + 1 << endl
					<< "Name:\t" << affil[i].get_first() << " " << last << endl
					<< "Mobile:\t" << affil[i].get_mobile() << endl
					<< "Email:\t" << affil[i].get_email() << endl
					<< "---\n";
			}
			cout << "Enter affiliate number to delete, or type exit\n";
			cin >> input;
			if (stoupper(input) == "EXIT") return;
			if (isdigit(input[0])) menu = atoi(input.c_str());
			else menu = -1;
			if (menu < 0 || menu > i + 1)
				cout << "Enter a valid affiliate number or type exit\n";
		} while (menu < 0 || menu > i + 1);
		affil.erase(affil.begin() + menu-1);
		return;
	}
	void rolodex::clear_data() {
		ID = 999999999;
		first = "not specified";
		last = "not specified";
		middle = "not specified";
		company = "not specified";
		home = "not specified";
		office = "not specified";
		email = "not specified";
		mobile = "not specified";
		street = "not specified";
		city = "not specified";
		state = "not specified";
		zip = "not specified";
		country = "not specified";
		affil.clear();
	}

/// ACCESSORS
	/// Rolodex Accessors
	int rolodex::get_ID() const			{ return ID; }
	string rolodex::get_first() const	{ return first; }
	string rolodex::get_last() const	{ return last; }
	string rolodex::get_middle() const	{ return middle; }
	string rolodex::get_company()const  { return company; }
	string rolodex::get_home() const	{ return home; }
	string rolodex::get_office() const	{ return office; }
	string rolodex::get_email() const	{ return email; }
	string rolodex::get_mobile() const	{ return mobile; }
	string rolodex::get_street() const	{ return street; }
	string rolodex::get_city() const	{ return city; }
	string rolodex::get_state() const	{ return state; }
	string rolodex::get_zip() const		{ return zip; }
	string rolodex::get_country() const	{ return country; }
	void rolodex::show_affiliates(ostream& outputStream) const {
		for (unsigned i = 0; i < affil.size(); ++i){
			outputStream << "Afilliate Number: " << i + 1 << endl;
			outputStream << "Name:\t" << affil[i].get_first() << " " << affil[i].get_last() << endl
				<< "Mobile:\t" << affil[i].get_mobile() << endl
				<< "Email:\t" << affil[i].get_email() << endl
				<< "\n---------------\n";
		}
	}
	void rolodex::print_rolodex() const
	{
		cout << "\nID: \t\t" << ID << endl;
		cout << "First Name:\t" << first << endl;
		cout << "Middle Name:\t" << middle << endl;
		cout << "Last Name:\t" << last << endl;
		cout << "Company Name:\t" << company << endl;
		cout << "Home Phone:\t" << home << endl;
		cout << "Office Phone:\t" << office << endl;
		cout << "Email:\t\t" << email << endl;
		cout << "Mobile Phone:\t" << mobile << endl;
		cout << "Street Address:\t" << street << endl;
		cout << "City:\t\t" << city << endl;
		cout << "State:\t\t" << state << endl;
		cout << "Zip Code:\t" << zip << endl;
		cout << "Country:\t" << country << endl;
		cout << "--------- Affiliates ------------\n";
		show_affiliates(cout);
	}
	void rolodex::FileWrite_affilliates(ofstream& outFile){
		for (unsigned i = 0; i < affil.size(); i++) {
			outFile << affil[i].get_first() << ","
				<< affil[i].get_last() << ","
				<< affil[i].get_mobile() << ","
				<< affil[i].get_email() << ";" << endl;
		}
	}
	bool rolodex::has_affiliate(string test) const {
		for (unsigned int i = 0; i < affil.size(); i++) {
			if (stoupper(affil[i].get_first()) == stoupper(test)) return true;
			if (stoupper(affil[i].get_last()) == stoupper(test)) return true;
			if (stoupper(affil[i].get_email()) == stoupper(test)) return true;
			if (stoupper(affil[i].get_mobile()) == stoupper(test)) return true;
		}		
		return false;
	}
	bool rolodex::has_affiliate_contain(string test) const {
		size_t found;
		for (unsigned int i = 0; i < affil.size(); i++) {
			found = stoupper(affil[i].get_first()).find(stoupper(test));
			if (found != string::npos) return true;
			found = stoupper(affil[i].get_last()).find(stoupper(test));
			if (found != string::npos) return true;
			found = stoupper(affil[i].get_email()).find(stoupper(test));
			if (found != string::npos) return true;
			found = stoupper(affil[i].get_mobile()).find(stoupper(test));
			if (found != string::npos) return true;
		}
		return false;
	}

	/// Affilitate Accsessors
	string affiliate::get_first() const	{ return first; }
	string affiliate::get_last() const	{ return last; }
	string affiliate::get_mobile() const{ return mobile; }
	string affiliate::get_email() const	{ return email; }

/// helpers
	int Get_INT(){ // get a valid int number (for menus, ID's etc...) return -1 if input is invalid
		int c = cin.peek();
		if (isdigit(c)){
			int n;
			cin >> n;
			cin.ignore();
			return n;
		}
		else
			cin.ignore();
		return -1;
	}	
	string check_phone(string input){ // function to check phone number formatting
		bool correct;
		do {
			correct = true;
			if (input.length() != 12)  // if phone number lenth is not 12, false will prevent 
				correct = false;	   // the - check from goung out of bounds.

			else if (input[3] != '-' && input[7] != '-') // if dashes are not correct
				correct = false;

			if (correct == false){
				cout << "\nThe phone number input " << input << " is not formatted correctly.\n"
					<< "The correct format is 000-000-0000\n"
					<< "Please reformat and try again, or type 0 for default: ";
				cin >> input;
				if (input == "0")
					input = "000-000-0000";
			}
		} while (correct == false);
			return input;
	}
	string check_email(string input){
		bool correct;
		const char * at1;
		const char * at2;
		do{
			at1 = NULL;
			at2 = NULL;
			correct = true;
			at1 = strchr(input.c_str(), '@'); // find first @
			at2 = strrchr(input.c_str(), '@');// find last @

			if (at1 == NULL) // if no @
				correct = false;

			else if (at1 != at2) // if more than one @
				correct = false;

			else if (input.length() < 5) // check if the email is long enouph, a false flag prevents the . check from
				correct = false;		// escaping the bounds of the string.

			else if (input[input.length() - 4] != '.' && input[input.length() - 3] != '.') // check if the dot is in the correct place
				correct = false;

			if (correct == false){ // if format is not correct force correction.
				cout << "\nThe email you entered: " << input << " was not formatted correctly.\n"
					<< "The correct format is xxx@xxx.com\n"
					<< "Please provide a properly formated email or type 'none': ";
				cin >> input;
				if (input == "none") // allow none as an input email.
					correct = true;
			}
		} while (correct == false);
		return input;
	}
	int check_ID(int ID){
		bool correct;
		do{
			correct = true;
			if (ID < 1 || ID > 999999999) // check if out of range
				correct = false;	

			if (correct == true){ // if the range is good, check for duplicates
				/// put functions here to check duplicate ID's ************************************ !!
			}
			if (correct == false){ // if the int value is not correct, then get a new one
				cout << "\nThe ID " << ID << " is not valid.\n"
					<< "Enter a unique ID number up to 9 digits\n";
				ID = Get_INT(); // will get an int value protected from BS input, return -1 if 
								// BS and that will fall outside of the range and will force a return to this prompt
			}
		} while (correct == false);
	return ID;
	}
	string check_name(string input){
		input = input.substr(0, 20);
		return input;
	}
	string check_zip(string input){
		bool correct;
		do{
			correct = true;
			if (input.length() != 5)
				correct = false;

			if (correct == false){
				cout << "\nZip code format of " << input << " is not correct.\n"
					<< "Correct format is: 00000\n"
					<< "Please input in correct format: ";
				cin >> input;
			}

		} while (correct = false);
		return input;
	}
	string stoupper(string s){
		string::iterator i = s.begin();
		string::iterator end = s.end();
		while (i != end) {
			*i = toupper((unsigned char)*i);
			++i;
		}
		return s;
	}

/// Operators
	// Affiliate operators
	bool affiliate::operator == (const affiliate& rside){
		/// combine first and last names of the comparison
		string left_test = this->first + this->last;
		string right_test = rside.first + rside.last;
		/// use the stoupper helper function to turn both comparisons to uppercase
		left_test = stoupper(left_test);
		right_test = stoupper(right_test);

		if (left_test != right_test)
			return false;
		else
			return true;
	}
	// Rolodex operators
	bool rolodex::operator == (const rolodex& rside) {
	/// Test if the id numbers are equal
		if (this->ID == rside.ID)
			return true;
		else
			return false;
	}
	bool operator == (const rolodex& lside, const rolodex& rside) {
		if (lside.get_ID() == rside.get_ID())
			return true;
		else
			return false;	
	}
	bool rolodex::operator < (const rolodex& rside) {
	/// Test if ID number is <
		if (this->ID < rside.ID)
			return true;
		else
			return false;
	}
	bool rolodex::operator<=(const rolodex& rside){
		if (this->ID <= rside.ID)
			return true;
		else
		return false;
	}
	bool operator < (const rolodex& lside, const rolodex& rside) {
		if (lside.get_ID() < rside.get_ID())
			return true;
		else
			return false;
	}
	bool operator>(const rolodex & lside, const rolodex & rside){
		if (lside.get_ID() > rside.get_ID())
			return true;
		else
			return false;
	}
	bool rolodex::operator > (const rolodex& rside) {
	/// Test if ID number is >
		if (this->ID > rside.ID)
			return true;
		else
			return false;
	}
	bool rolodex::operator>=(const rolodex& rside){
		if (this->ID >= rside.ID)
			return true;
		else
			return false;
	}
	ostream& operator<<(ostream& stream, const rolodex & rside)
	{
		cout << rside.get_ID();
		return stream;
	}
}
