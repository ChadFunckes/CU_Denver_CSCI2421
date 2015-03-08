//Chad S Funckes
//CSC 2421
//Homework 1
//Functions for the my_random class

#include <iostream>
#include "my_random.h"

My_random::My_random(){  // Constructor sets initial values //
multiplier = 40; 
increment = 725; 
modulus = 729; 
seed = 0; 
}
void My_random::changeSeed(int newseed){ // sets seed number to an int value from function call //
	seed = newseed;
}
int My_random::make_Rnumber(){ // Creates Psudorandom number based on user input for seed //
	int newSeed = (multiplier * seed + increment)%modulus;
	return newSeed;
}
