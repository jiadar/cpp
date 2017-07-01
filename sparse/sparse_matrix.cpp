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
    write_row(i, cur_row, m_size, TRUE);
    cur_row=cur_row->next_row;
  } 
}

void multiply(SparseMatrix *m1, SparseMatrix *m2, SparseMatrix *m, int m_size) {
  cout << "unimplemented" << endl;
}

