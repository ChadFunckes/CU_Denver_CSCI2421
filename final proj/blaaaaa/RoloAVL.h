//Chad S Funckes
// Purpose: RoloAVL class serves as an adapter class that derives from AVL.h
//			It enables extra rolodex specific data to be used on top of the AVL
//			Class implementation.  Like the AVl implementation, several function
//			overloads exist in private, for ease of use of the user and to allow
//			access to private member data.
/*
struct ECsearch is used in search criteria for search functions to allow the user to 
specify E for exact, C for Contains searches and the test to search on

// Constructors
	roloAVL()
		Post: AVL class constructor used, nothing done here
	~roloAVL()
		Post: AVL class desctructor used, no extra data created by this class
// Accessors
	Node<rolodex>* FindID(int findme);
		Post: Returns a pointer to the rolodex item than was found with matching ID number.
	void Display(Node<rolodex>* N);
		Pre: Needs a pointer to a rolodex node item
		Post: Displays full record data
	void chooseDisplayOptions()
		Post: Sets the display options for this roloAVL object;
	void CustomDisplay(ostream& outputStream);
		Post: outputs to the output stream (screen or file, etc.) the output as defined in ChooseDisplayOptions().
	void Search();
		Post: Inside the search function the user is able to choose any field to include in 
			  a search of the tree.  In any field chosen, they are able to select Exact or Contains
			  criteria as well as the text to search on.  All field and types of search are
			  non-case sensitive.
	void WriteOut(string);
		PRE: A string that is the name of a file that will be written of the database
		POST: A file name that matches the input string will be written to the HDD.
//Mutators
	void ModID(Node<rolodex>* N)
		Post: Allows used to modify the rolodex value data at the Node
	void Add_Person();
		Post: Allows the user to add an unconstructed person to the tree.
*/
#ifndef ROLOAVL_FINAL
#define ROLOAVL_FINAL
#include "avl.h"
#include "rolodex.h"
#include <map>
#include <string>
using namespace std;
namespace rolo {
	struct ECsearch {
		char EC;
		string searchcrit;
	};

	class roloAVL : public AVL<rolodex> {
	public:
		typedef AVL<rolodex> avl;
		roloAVL() { display[14] = { false }; display[0] = display[2] = true; } // no pointers made, obj is constructed in avl class
		~roloAVL() {} // nothing to destroy
	//Accessors
		Node<rolodex>* FindID(int findme);
		void Display(Node<rolodex>* N);
		void Search();
		void WriteOut(string);
		void chooseDisplayOptions();
		void CustomDisplay(ostream& outputStream);
		//Mutators
		void ModID(Node<rolodex>* N);
		void Add_Person();

	private:
		bool display[14];
		void Search(map<int, ECsearch> criteria, roloAVL& results, Node<rolodex>*);
		void SearchMenu(map<int, ECsearch>& criteria);
		void ElimSearch(map<int, ECsearch>& eCriteria, roloAVL& results, roloAVL& origResults, Node<rolodex>*);
		Node<rolodex>* FindID(Node<rolodex>* N, int findme);
		void CustomDisplay(ostream& outputStream, Node<rolodex>* N);
		void WriteOut(Node<rolodex>* N, ofstream& outFile);
		ECsearch Exact_Contain();
	};
}
#endif