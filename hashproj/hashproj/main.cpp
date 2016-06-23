#include "functions.h"
//#include <tr1/unordered_set>
#include <unordered_set>

using namespace std;
using namespace std::tr1;

int main() {
	unordered_set<string> dictionary = unordered_set<string>(1373);
	vector<string> misspelled_words;

	if (load_dictionary(dictionary) == false) // if the dictionary didn't load exit.
		return 0;
	
	if (check_file(dictionary, misspelled_words) == false) // check a file against the dictionary
		return 0;

	cout << "The list of mis-spelled words was:\n";
	for (unsigned i = 0; i < misspelled_words.size(); ++i) { // print the words...
		cout << misspelled_words[i] << endl;
	}

	system("pause");

}