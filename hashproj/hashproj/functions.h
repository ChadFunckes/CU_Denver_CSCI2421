#ifndef MAIN_FUNC_HW10
#define MAIN_FUNC_HW10
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

ifstream& getWord(ifstream&, string&);
bool load_dictionary(unordered_set<string>&);
bool check_file(unordered_set<string>&, vector<string>&);
#endif