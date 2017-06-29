#include <iostream>
#include <string>
#include <iomanip>
#include "matrix.h"

using namespace std;

void create(float m[][MATRIX_SIZE], int row_size) {

  // Loop through the matrix, zeroing each cell

  for(int i=0; i < row_size; i++) {
    for (int j = 0; j < row_size; j++) {
      m[i][j]=0;
    }
  }
}

void read_matrix(float m[][MATRIX_SIZE],int row_size, ifstream& inputFile) {

  // Using the given stream object, read the matrix from the file and
  // insert it into the matrix array

  for(int i=0; i < row_size; i++) {
    for (int j = 0; j < row_size; j++) {
      inputFile >> m[i][j];
    }
  }
}

void write_matrix(const float m[][MATRIX_SIZE], int row_size) {

  // Write the given matrix to the console, with appropriate space
  // formatting 

  for(int i=0; i < row_size; i++) {
    for (float v: m[i]) {
      if (v>=10000) {
        cout << fixed << setw(9) << " OVERFLOW ";        
      }
      else {
        cout << fixed << setw(9) << setprecision(2) << v << " ";
      }
    }
    cout << endl;
  }
}

float cell_product(float m1[][MATRIX_SIZE], float m2[][MATRIX_SIZE], int i, int j, int row_size) {

  // The chosen matrix multiplication method relies on this function to return the
  // matrix product for a given row (i) and column (j).
  
  // To compute a cell product for row, col use the following formula
  // sum from k=0 to m-1 of A(i,k) * B(k,j)

  float sum = 0.0;
  for (int k=0; k < row_size; k++) {
    sum += m1[i][k] * m2[k][j];
  }
  return sum;
}

void multiply(float m1[][MATRIX_SIZE], float m2[][MATRIX_SIZE], float m[][MATRIX_SIZE], int row_size) {

  // Since we have a function to give the product value of cell i, j
  // We can repeadly call cell_product through the result matrix and
  // build the result. 

  // First, we make sure the result matrix is zeroed, as we will be adding
  // sums
  
  create(m, row_size);

  // Compute the result by calling cell_product for each i, j in the source
  // matrix
  
  for(int i=0; i < row_size; i++) {
    for (int j=0; j < row_size; j++) {
      m[i][j] = cell_product(m1, m2, i, j, row_size);
    }
  }
}
