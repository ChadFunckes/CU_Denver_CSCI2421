//
//CSC 2421
//Homework 2
//September 7, 2009
//Support functions for the matrix program

#include <iostream>
#include <fstream>
#include "matrix_functions.h"
#include "matrix.h"

//Opens a data file, and reads integers into two arrays
void populate_arrays(int array1[3][3], int array2[3][3], const char*
file_name)
{
  //Opens the data file
  const char* data_file = file_name;
  std::ifstream read_data(data_file);

  //Populates the first array
  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      read_data >> array1[i][j];
    }
  }

  //Populates the second array
  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      read_data >> array2[i][j];
    }
  }

  //Closes the input file
  read_data.close();
}

//Displays the sum of two matrices
void show_sum(matrix sum)
{
  std::cout << "The sum of the matrices is:\n";
  sum.get_matrix();
}

//Displays the product of two matrices
void show_product(matrix product)
{
  std::cout << "The product of the matrices is:\n";
  product.get_matrix();
}

//Displays a greeting and brief program description
void greeting(const char* file_name)
{
  std::cout << "\nMatrix Program\n\n";
  std::cout << "This program reads two matrices from the data file,\n";
  std::cout << "and computes the sum and product of the matrices.\n\n";
  std::cout << "Reading data from the file: " << file_name << "\n\n";
  std::cout << "The matrices are:\n";
}

