//
//CSC 2421
//Homework 2
//September 7, 2009
//Functions for the matrix class

#include <iostream>
#include "matrix.h"

//Constructor
matrix::matrix(int input_array[3][3])
{
  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      mtx_array[i][j] = input_array[i][j];
    }
  }
}

//Displays a matrix
void matrix::get_matrix()
{
  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      std::cout << mtx_array[i][j] << ' ';
    }
    std::cout << '\n';
  }
  std::cout << '\n';
}

//Calculates and returns the sum of two matrices
matrix operator +(const matrix& m1, const matrix& m2)
{
  int sum_array[3][3];

  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      sum_array[i][j] = m1.mtx_array[i][j] + m2.mtx_array[i][j];
    }
  }

  matrix sum(sum_array);
  return sum;
}

//Calcualtes and returns the product of two matrices
matrix operator *(const matrix& m1, const matrix& m2)
{
  int prod_array[3][3];

  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      int sum = 0;
      for (int k = 0; k < 3; k++)
      {
        sum += m1.mtx_array[i][k] * m2.mtx_array[k][j];
      }
      prod_array[i][j] = sum;
    }
  }

  matrix product(prod_array);
  return product;
}

