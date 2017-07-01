#include <iostream>
#include <string>
#include <iomanip>
#include "matrix.h"
#include "sparse_helper.h"

using namespace std;

SparseMatrix *create(int m_size) {
  return new SparseMatrix();
}

void read_matrix(SparseMatrix *m, int m_size, ifstream &inputFile) {
  Entry *cur_row = m->rows;
  
  for (int i = 0; i < m_size; i++) {
    read_row(i, cur_row, m_size, inputFile);
    cur_row=cur_row->next_row;
  }
} 

void write_matrix(SparseMatrix *m, int m_size) {
  Entry *cur_row = m->rows;

  for (int i = 0; i < m_size; i++) {
    write_row(i, cur_row, m_size);
    cur_row=cur_row->next_row;
  } 
}

void multiply(SparseMatrix *m1, SparseMatrix *m2, SparseMatrix *m, int m_size) {

  Entry *cur_row = m->rows;
  Entry *cur_col = m->rows;
  
  for(int i=0; i < m_size; i++) {
    for (int j=0; j < m_size; j++) {
       float product = cell_product(m1, m2, i, j, m_size);
       if (product != 0) {
         //         cout << "product ( " << i << "," << j << ") = " << product << endl;
         set_entry(cur_col, i, j, product);
         cur_col->next_column = new Entry();
         cur_col = cur_col->next_column;
       }
    }
    cur_row=cur_row->next_row;
    cur_col=cur_row;
  }
}


