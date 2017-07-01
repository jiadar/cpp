
// Public functions for Sparse Matrix as defined by the header file

#include <iostream>
#include <string>
#include <iomanip>
#include "matrix.h"
#include "sparse_helper.h"

using namespace std;

sparse_matrix *create(int m_size) {

  // Create a new sparse matrix with the constructor

  return new sparse_matrix();
}


void read_matrix(sparse_matrix *m, int m_size, ifstream &inputFile) {

  // Read a matrix from a file by reading each row
  // The current row is incremented to the matrix size, and
  // we use the helper function to read the row

  Entry *cur_row = m->rows;
  
  for (int i = 0; i < m_size; i++) {
    read_row(i, cur_row, m_size, inputFile);
    cur_row=cur_row->next_row;
  }
} 

void write_matrix(sparse_matrix *m, int m_size) {

  // Write a matrix to the screen by writing each row
  // The current row is incremented to the matrix size and
  // we use the helper function to write the row

  Entry *cur_row = m->rows;

  for (int i = 0; i < m_size; i++) {
    write_row(i, cur_row, m_size);
    cur_row=cur_row->next_row;
  } 
}

void multiply(sparse_matrix *m1, sparse_matrix *m2, sparse_matrix *m, int m_size) {

  // Multiply the matrix by using the cell product helper function
  // After getting the product, if it is non-zero, we insert it into
  // a sparse matrix by setting the entry, making a new entry in the
  // next column, and incrementing the column. Finally, we increment
  // the row and set the column back to the start of the next row. 
  
  Entry *cur_row = m->rows;
  Entry *cur_col = m->rows;
  
  for(int i=0; i < m_size; i++) {
    for (int j=0; j < m_size; j++) {
       float product = cell_product(m1, m2, i, j, m_size);
       if (product != 0) {
         set_entry(cur_col, i, j, product);
         cur_col->next_column = new Entry();
         cur_col = cur_col->next_column;
       }
    }
    cur_row=cur_row->next_row;
    cur_col=cur_row;
  }
}


