# CU_Denver_CSCI2421

This directory is my reposity for my homework assignments in CSCI 2421 (data structures and program design)

Homework 1 - 
The program takes a number from the user and generates a random
number using the linear congruence method and a user input as a seed number.
The multiplier, increment and modulus are all set by the class constructor,
and the only modifiable element is the seed number input from the user.

Homework 2 -
This program uses the quadratic class to set up two quadratic equations
The user enters two diffent sets of coefficients
The expressions are then added togather to create a third quadratic
The user then enters one number for x, to see the resulting quadratic results
The user is then asked for a number to multilpy the quadratic by.
For Ex:4 would be 4(ax^2 + bx + c) and shown the final quadratic expression.

Homework 3 -
This program utilises the set class (an extended version of bag from chapter 3)
To input two sets of integers from a file named input.dat.  Each set of integers will be on a single line
separated by a end of line charictor.  After input of the data set, all duplicate numbers in the data set
will be deleted, so that the set only contains one copy of any integer.

The two input sets will then be added togather using the set class overloaded operator +.  This will
place the two sets togather and then eliminate any common numbers, so that the new set is once again a single
"set" of integers with no repeating numbers and then display the resulting set for the user.

The program will then take the two original sets and utilize the overloaded - operator of the set class
to remove all of the items present in the second set from the first set.  and then display the resulting set
to the user.

Homework 4 -
This file contains a program utilizing the class my_string 
It takes an input text file of any number of lines and any number of columns from
either a command line parameter or using the default file name data.txt.
The program then takes from the user a specified column width and then formats the output
text so that is exactly that many columns wide.  If a word spans the line a hyphen
is added to the end of the line just past the specified width.

Homework 5 -
This program gets a txt file from the user utilizes node1.h to stores each word of the file
into in a node in a linked list. The program then reverses the list and send the reversed list
to a file called output.txt.

Homework 6 -
This program uses a circular doubly linked list to simulate a travel agent selecting customers for 
a free world cruize.  The user selects how many contestants are in the pool.
Then those numbers are dropped into a hat and randomly selected by the agent.

The program then takes the number selected from the hat, and then starting at the begining of the list
walks forward that many people.  The person they end up at is eliminated from the competition.  The agent
then turns around and walks back the other direction the same number of people and then that person
is eliminated.  This process is continued until only 1 person is left in the game and that person
is the winner of the competition.
