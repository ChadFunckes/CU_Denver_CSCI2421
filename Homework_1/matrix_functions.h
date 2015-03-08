//
//CSC 2421
//Homework 2
//September 7, 2009
//Support functions for the matrix program

#include "matrix.h"

#ifndef H_MATRIX_FUNCTIONS
#define H_MATRIX_FUNCTIONS

//Displays a greeting and brief description of the program
void greeting(const char* file_name);

//Populates two arrays with data from an input file
void populate_arrays(int[3][3], int[3][3], const char*);

//Displays the sum of two matrices
void show_sum(matrix sum);

//Displays the product of two matrices
void show_product(matrix product);

#endif
