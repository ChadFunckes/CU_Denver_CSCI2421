//Eliot Nemecek 830307888
//CSC 2421
//Homework 2
//September 7, 2009
//This program reads two matrices from an input file,
//and computes and displays their sum and product.

#include <iostream>
#include <fstream>
#include "matrix.h"
#include "matrix_functions.h"


int main(int argc, char* argv[])
{
  //Uses the file name given at the command line,
  //or a default file name if none is given
  const char* input_file;
  if(argc == 2)
    input_file = argv[1];
  else
    input_file = "input.dat";

  //Greets the user, and gives a brief description of the program
  greeting(input_file);

  //Populates two arrays with data from an input file
  int m1_array[3][3], m2_array[3][3];
  populate_arrays(m1_array, m2_array, input_file);

  //Uses the data from the file to create two matrices
  //Then displays the matrices
  matrix matrix_1(m1_array); 
  matrix_1.get_matrix();

  matrix matrix_2(m2_array);
  matrix_2.get_matrix();

  //Computes and displays the sum of the two matrices
  matrix sum = matrix_1 + matrix_2;
  show_sum(sum);

  //Computes and displays the product of the two matrices
  matrix product = matrix_1 * matrix_2;
  show_product(product);

  return 0;
}


