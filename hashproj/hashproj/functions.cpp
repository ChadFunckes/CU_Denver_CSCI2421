#include "functions.h"


ifstream& getWord(ifstream& fin, string& w)
{
	char c;

	w = ""; // clear the string of characters

	while (fin.get(c) && !isalpha(c)); // do nothing. just ignore c

									   // return on end-of-file
	if (fin.eof())
		return fin;

	// record first letter of the word
	w += tolower(c);

	// collect letters and digits
	while (fin.get(c) && (isalpha(c) || isdigit(c)))
		w += tolower(c);

	return fin;
}

bool load_dictionary(unordered_set<string>& dictionary) {
	string input;
	ifstream inFile("dict.dat");
	if (!inFile.is_open()) {
		cout << "Could not load dict.dat, please make sure it is in this directory\n";
		return false;
	}
	do {
		getline(inFile, input);
		dictionary.insert(input);
	} while (!inFile.eof());
	inFile.close();
	return true;
}

bool check_file(unordered_set<string>& dictionary, vector<string>& words) {
	string input;
	ifstream inFile;

	cout << "Please enter a file name to check against the dictionary\n";
	cin >> input;

	inFile.open(input);
	if (!inFile.is_open())
		return false;

	do {
		getWord(inFile, input);
		unordered_set<string>::iterator found = dictionary.find(input.c_str());
		if (found != dictionary.end());
		else
			words.push_back(input);
	} while (!inFile.eof());

	return true;
}
