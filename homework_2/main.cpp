//Chad Funckes
//CSC 2421
//Homework 1
//February 3, 2015
//This program generates a psuedorandom number based on
//an input number from the user, using the class My_random.

#include <iostream>
#include "my_random.h"
using namespace std;

int main()
{
	int number;		  // The number to be used as seed number
	My_random rnumber;// New instance of random_number class called Rnumber

	cout << "This program will generate 3 psuedorandom integers based on an initial seed number\n"
		 << "Please Input the initial seed value as an Integer:\n";
	cin >> number;

	for (int i=1; i < 4; i++){  //Carries out 3 iterations of numbers.
	rnumber.changeSeed(number); //Sets value of the seed in the class
	number=rnumber.make_Rnumber(); //Changes value of the random number generated
	cout << "Random number "<< i << " is " << number << endl;
	}
}
