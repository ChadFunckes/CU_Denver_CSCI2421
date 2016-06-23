// CSCI 2421
// FINAL DATABASE PROJECT
/*
FILE: THIS FILE CONTAINS THE CLASSES AFFILIATE AND ROLODEX AS WELL AS HELPER FUNCTIONS
	  THAT ALL OPERATE IN THE NAMESPACE rolo.

**** CLASS AFFILIATE ****
// Constructors
	affiliate()
		Post condition: First, Last, email: set to "not specified", mobile set to 000-000-0000.
	affiliate(first, last)
		Post Condition: First and last name set as input, mobile set to 000-000-0000 and email to "not specified"
	affiliate(string first, string last, string mobile, string email);
		Post Condition: first name, last name, mobile number and email set within standards defined by 
					functions check_phone and check_email.
// Accessor functions
	string get_first()
		Post Condition: String value with affiliate last name returned.
	string get_last()
		Post Condition: String values with the affiliate first name returned.
	string get_mobile()
		Post Condition: String value with the affiliate phone number returned.
	string get_email()
		Post Condition: String value with the affiliate email returned.
// Mutator functions 
	void set_first(string)
		Post condition: First name set, limited to 20 charactors.
	void set_last(string)
		Post Condition: Last name set, limited to 20 charactors.
	void set_mobile(string)
		Post condition: mobile number set according to standards in function check_phone function
	void set_email(string);
		Post Condition: email set according to standards set in function check_email function
	void clear_affil();
		Post Condition: Deletes all data in the affiliate object
// Operators
	bool operator == (const affiliate&)
		Post Condition: bool true is first name and last name are exact;

**** CLASS ROLODEX ****
// Constructors
	rolodex();
		Post: Default values of ID 0 and "not specified" for text fields
	rolodex(int);
		Post: Only ID initialized with int value
	rolodex(int ID, string first, string last, string middle)
		Post: Ony specified fields initialized
	rolodex(int, string first, string last, string middle, string company, string home,
		string office, string email, string mobile, string street, string city,
		string state, string zip, string country, vector<affiliate> affil)
		Post: All fields initialized
// Accessors
	int rolodex::get_ID() const	
	string get_first() const
	string get_last() const
	string get_middle() const
	string get_company()const 
	string get_home() const
	string get_office() const
	string get_email() const
	string get_mobile() const
	string get_street() const
	string get_city() const
	string get_state() const
	string get_zip() const	
	string get_country() const
	void show_affiliates() const
		- Post: returns the apropriate field
	void rolodex::print_rolodex()
		Post: Output to the screen the entire rolodex item, with field names
	void FileWrite_affilliates(ofstream& outFile)
		Post: Writes out affiliate data to a file
	bool has_affiliate(string test)
		Post: Returns true if a string matched exactly in affiliate data
	bool has_affiliate_contain(string test);
		Post: Returns true if a string mathed partially in affiliate data
// Mutators
		void set_ID(int);
		void set_first(string);
		void set_last(string);
		void set_middle(string);
		void set_company(string);
		void set_home(string);
		void set_office(string);
		void set_email(string);
		void set_mobile(string);
		void set_street(string);
		void set_city(string);
		void set_state(string);
		void set_zip(string);
		void set_country(string);
			Post: Sets the value of the fields
		void add_affiliate(affiliate); 
			Pre: an affiliate already constructed
			Post: Constructed affiliate added to rolodex item
		void add_affiliate(string first, string last, string mobil, string email);
			Post: add an afiliate not yet constructed
		void modify_affiliates();
			Post: Changes data on an affiliate already in place
		void delete_affiliates();
			Post: Allows deletion of a current affiliate chose by user
		void clear_data();
			Post: sets all data in rolodex item back to starting defaults.
//Operators 
	Affiliate has over loaded == operator that check equality between first and last names
	Rolodex has overloaded <, <=, >, >=, == operators all based on ID number alone.
	Rolodex also has overloaded << operator that outputs the ID number.

***** Helper Functions *****
	string check_phone(string)
		Pre-Condition: Any string input.
		Post Condition: Properly formatted phone number as 000-000-0000
	string check_email(string)
		Pre-Condition: Any string input.
		Post Condition: Formatted email address that include at @ symbol and a domain
					 of .xxx or .xx specified.
	int check_ID(int);
		Pre-Condition: An int value to be used as an ID
		Post Condition: Returns an int value that is not out of range.
	string check_name(string);
		Post: Cuts the string length to 20 chars
	string check_zip(string);
		Post: Check valid format for zip code
	string stoupper(std::string)
		Pre-Condition: A string with only ASCII carictors.
		Post-Condition: A string is returned converted to all capital letters.
	int Get_INT();
		Post: returns and int value no matter what is typed at the prompt.
*/

#ifndef FINAL_ROLODEX
#define FINAL_ROLODEX
#include <string>
#include <vector>

using namespace std;
namespace rolo {
	class affiliate {
	public:
		/// Constructors
		affiliate();
		affiliate(string, string);
		affiliate(string, string, string, string);
		/// Accsessors
		string get_first()const;
		string get_last()const;
		string get_mobile()const;
		string get_email()const;
		/// Mutators
		void set_first(string);
		void set_last(string);
		void set_mobile(string);
		void set_email(string);
		void clear_affil();
		/// operators
		bool operator == (const affiliate&);

	private:
		string first, last, mobile, email;
	};

	class rolodex {
	public:
		/// constructors
		rolodex(); // create empty
		rolodex(int);
		rolodex(int, string, string, string); // set name only
		rolodex(int, string first, string last, string middle, string company, string home,
			string office, string email, string mobile, string street, string city,
			string state, string zip, string county, vector<affiliate> affil);

		/// Accessors
		int get_ID() const;
		string get_first() const;
		string get_last() const;
		string get_middle() const;
		string get_company() const;
		string get_home() const;
		string get_office() const;
		string get_email() const;
		string get_mobile() const;
		string get_street() const;
		string get_city() const;
		string get_state() const;
		string get_zip() const;
		string get_country() const;
		void show_affiliates(ostream& outputStream) const;
		void print_rolodex() const;
		void FileWrite_affilliates(ofstream& outFile);
		bool has_affiliate(string test) const;
		bool has_affiliate_contain(string test) const;

		/// Mutators
		void set_ID(int);
		void set_first(string);
		void set_last(string);
		void set_middle(string);
		void set_company(string);
		void set_home(string);
		void set_office(string);
		void set_email(string);
		void set_mobile(string);
		void set_street(string);
		void set_city(string);
		void set_state(string);
		void set_zip(string);
		void set_country(string);
		void add_affiliate(affiliate); // add an affiliate already constructed
		void add_affiliate(string first, string last, string mobil, string email); // add an afiliate not yet constructed
		void modify_affiliates();
		void delete_affiliates();
		void clear_data();

		/// operators
		bool operator==(const rolodex &);
		bool operator<(const rolodex &);
		bool operator<=(const rolodex &);
		bool operator>(const rolodex &);
		bool operator>=(const rolodex &);

	private:
		int ID;
		string first, last, middle, company, home, office, email, mobile,
			street, city, state, zip, country;
		vector<affiliate> affil;

	};

	/// helper functions
	string check_phone(string); // function to check phone number formatting
	string check_email(string); // function to check email formatting
	int check_ID(int);			// check for valid ID
	string check_name(string);  // cuts a name to 20 char length
	string check_zip(string);	// check for valid zip
	string stoupper(string);	// converts a string to uppercase letters for comparison,
								// does not change the input string to uppercase at address.
								// to convert use string1 = stoupper(string1).
	int Get_INT();				// use instead of cin to get an guaranted INT value

	/// overloaded non-member operators
	bool operator<(const rolodex & lside, const rolodex & rside);
	bool operator>(const rolodex& lside, const rolodex& rside);
	bool operator == (const rolodex& lside, const rolodex& rside);
	ostream& operator << (ostream& stream, const rolodex& rside);
}
#endif