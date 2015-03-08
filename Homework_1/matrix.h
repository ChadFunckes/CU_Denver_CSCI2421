//
//CSC 2421
//Homework 2
//September 7, 2009
//Matrix Class prototypes

#ifndef H_MATRIX
#define H_MATRIX

//Data and functions for a 3 X 3 matrix
class matrix{
  public:
          //Constructor
          matrix(int[3][3]);

          //Displays the matrix
          void get_matrix();
          
          //Calculates and returns the sum of two matrices
          friend matrix operator +(const matrix&, const matrix&);

          //Calculates and returns the product of two matrices
          friend matrix operator *(const matrix&, const matrix&);


  private:
          int mtx_array[3][3];

};

#endif
