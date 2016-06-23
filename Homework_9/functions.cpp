// CSCI 2421
// CHAD S FUNCKES
/*
FILE: FUNCTIONS.CPP
DESC: THIS IS THE IMPLEMENTATION FOR THE MAIN FUNCTIONS USED IN THE PROGRAM
PLEASE SEE FUNCTIONS.H FOR DETAILS
*/

#include "functions.h"
using namespace std;
namespace funckes_hw9{

	int coins(int input){
		if (input == 1) // Penny
			return 1;
		else if (input == 2) // Nickel
			return 5;
		else if (input == 3) // Dime
			return 10;
		else if (input == 4) // Quarter
			return 25;
		return 0; // Bogus input
	}
	int ways3(int amount)
	{
		if (amount <= 0) return 0; // return 0 on the base case
		int coinNum = 100; // no more than 100 coins can be used, becuase it's less than a dollar, so start max 100
		for (int i = 1; i < 5; i++) { // 1-5 to use the coins function
			if (coins(i) <= amount)
				coinNum = min(coinNum, ways3(amount - coins(i)) + 1); // use recursion to get the lowest sum of coins
		}
		return coinNum; // return new amt
	}
	int ways(int amount, int denom){ /// using recursion, but only returns quarters - dimes - nickels....etc
		if (amount <= 0) return 0;
		int i = amount / coins(denom); // the new amount / the amount the current coin is worth
		if (denom == 4 && i > 0)
			cout << i << " Quarters, ";
		else if (denom == 3 && i > 0)
			cout << i << " Dimes, ";
		else if (denom == 2 && i > 0)
			cout << i << " Nickels, ";
		else if (denom == 1 && i > 0)
			cout << i << " Pennies. ";
		amount = amount - (coins(denom)*i); // taking off the previous coin amt
		i = i + ways(amount, denom - 1); // adding up a return amount for total coins
		return i;
	}
	int ways2(int amount, int denom){  // non-working method, using a loop from the main it works until the numbers get larger and screws up
		if (amount <= 0) return 0;
		int i = amount / coins(denom);
		//int a;

		if (denom == 4 && i > 0)
			cout << i << " Quarters, ";
		else if (denom == 3 && i > 0)
			cout << i << " Dimes, ";
		else if (denom == 2 && i > 0){
			if (i > 1){
				for (int xx = 1; xx < i; xx++){
					int amount2 = amount - coins(denom)*xx;
					int a = i - xx;
					cout << i - a << "Nickels, ";
					ways2(amount2, denom - 1);
				}
			}
			cout << i << " Nickels, ";
		}
		else if (denom == 1 && i > 0)
			cout << i << " Pennies. ";

		amount = amount - (coins(denom)*i);
		i = i + ways2(amount, denom - 1);
		return i;
	}
	int count(int amount, int denom){ // non-working, almost had this one from the main loop, but got messed up in dimes of large numbers
		int sum = 0;				 // messing with this setup is how I got to the method I used.	
		if (amount <= 0) return 0;

		if (denom > 1){
			if (amount / coins(denom) > 1){
				sum = count(amount - coins(denom), denom - 1) + 1;
			}
			sum = count(amount - coins(denom), denom - 1) + 1;
		}
		if (denom == 1){
			sum = count(amount - coins(denom), denom) + 1;
		}

		return sum;
	}
	int get_input(){ // get input from the user
		int amount;
		do{
			cout << "Enter a number less than 100 to get change for\n";
			cin >> amount;
			if (amount > 0 && amount < 100)
				return amount;
		} while (amount < 0 || amount > 100); // while not out of bounds
	}
	void get_pennies(vector<vector <int> > &keeper, const int &amount){ // do pennies, fill vector with results
		int vs = keeper.size(); // get current vector size to start adding
		if (amount > 0){ /// do pennies if more than 0 pennies
			keeper.push_back(vector<int>(4)); vs++; // pushback vector and increase vs (vector size variable)
			keeper[vs - 1][0] = 0;
			keeper[vs - 1][1] = 0;
			keeper[vs - 1][2] = 0;
			keeper[vs - 1][3] = amount;
		}
	}
	void get_nickels(vector<vector <int> > &keeper, const int &amount){ // do nickels, fill vector with results
		int vs = keeper.size(); // get current vector size to start adding
		if (amount / coins(2) > 0){
			int i = 2;
			int m = amount / coins(i); // max coins divisable
			while (m > 0){			   // loop until all nickels added back
				int xx = amount / coins(i); 
				int xy = xx - (xx - m + 1);
				keeper.push_back(vector<int>(4)); vs++; // pushback vector and increase vs (vector size variable)
				keeper[vs - 1][0] = 0;
				keeper[vs - 1][1] = 0;
				keeper[vs - 1][2] = xy + 1;
				keeper[vs - 1][3] = count(amount - (coins(i)*xy), i) - 1;
				m--; // put a nickel back (not the band)
			}
		}
	}
	void get_dimes(vector<vector <int> > &keeper, const int &amount){ // do dimes, fill vector with results
		int vs = keeper.size(); // get current vector size to start adding
		if (amount / coins(3) > 0){
			int i = 3;
			int vs = keeper.size();
			int m = amount / coins(i); // max coins divisable
			while (m > 0){			  // loop until all dimes added back
				int xx = amount / coins(3);
				int xy = xx - (xx - m + 1);
				keeper.push_back(vector<int>(4)); vs++; // pushback vector and increase vs (vector size variable)
				keeper[vs - 1][0] = 0;
				keeper[vs - 1][1] = xy + 1;
				keeper[vs - 1][2] = (amount - (keeper[vs - 1][1] * coins(3))) / coins(2);
				keeper[vs - 1][3] = amount - (keeper[vs - 1][1] * coins(3) + keeper[vs - 1][2] * coins(2));
				m--; // put a dime back
			}
		}
	}
	void get_quarters(vector<vector <int> > &keeper, const int &amount){ // do quarters
		int vs = keeper.size(); // get current vector size to start adding
		if (amount / coins(4) > 0){
			int i = 4;
			int m = amount / coins(i); // max coins divisable
			while (m > 0){			   // loop until all dimes added back
				int xx = amount / coins(4);
				int xy = xx - (xx - m + 1);
				keeper.push_back(vector<int>(4)); vs++; // pushback vector and increase vs (vector size variable)
				keeper[vs - 1][0] = xy + 1;
				keeper[vs - 1][1] = (amount - (keeper[vs - 1][0] * coins(4))) / coins(3);
				keeper[vs - 1][2] = (amount - ((keeper[vs - 1][0] * coins(4))) - (keeper[vs - 1][1] * coins(3))) / coins(2);
				keeper[vs - 1][3] = (amount - ((keeper[vs - 1][0] * coins(4))) - (keeper[vs - 1][1] * coins(3))) - (keeper[vs - 1][2] * coins(2));
				m--;
			}
		}
	}
	void get_coins(vector<vector <int> > &keeper, const int &amount){ // just runs all the gets in a row
		get_pennies(keeper, amount);
		get_nickels(keeper, amount);
		get_dimes(keeper, amount);
		get_quarters(keeper, amount);

	}
	void print_coins(const vector<vector <int> > &keeper){ // print the output
		string coin_names[] = { "Quarter(s)", "Dime(s)", "Nickel(s)", "Penny(s)" }; // array holds the names to avoid multiple loops
		for (int o = 0; o < keeper.size(); o++){ // outside loop
			for (int i = 0; i < 4; i++) { // inside loop
				if (keeper[o][i] != 0) // if the number is 0 we don't care 
					cout << keeper[o][i] << " " << coin_names[i] << " "; // print the number at the location with the proper nounage (nickel, dime, etc.)
			}
			cout << endl;
		}
		cout << "\nThere was " << keeper.size() << " ways to make change.\n"; // say how many ways there was
	}
	void print_most_efficient(const vector<vector <int> > &keeper){
		string coin_names[] = { "Quarter(s)", "Dime(s)", "Nickel(s)", "Penny(s)" }; // array of coin names for ease of display
		int minimum[4]; // this array will home the min combination
		int min_size = 100; // 100 will be the max coins, because it's less than a dollar
		int sum = 0; // coin number tracker
		for (int o = 0; o < keeper.size(); o++){ // outside loop
			for (int i = 0; i < 4; i++) // inside loop
				sum += keeper[o][i]; // add tha number of coins within the outside o
			if (sum < min_size){  // if the new sum is smaller than the smalles then....
				min_size = sum;  // let that be the new min_size and ...
				for (int i = 0; i < 4; i++){ // fill the minimum[] array with the data from the minimum set
					minimum[i] = keeper[o][i];
				}
			}
			sum = 0; // reset cout back to zero
		}

		cout << "\nThe Minimum number of coins was: " << min_size << endl
			<< "The coins were: ";
		for (int i = 0; i < 4; i++){ // go through the minimum array holding the smallest group
			if (minimum[i] != 0)
				cout << minimum[i] << " " << coin_names[i] << " ";
		}
		cout << endl;
	}
	void print_recursive(int amount){ // print the output of the recursive function ways3
		cout << "\nUsing recursion the min number of coins is: " << ways3(amount) << endl;
	}
}
