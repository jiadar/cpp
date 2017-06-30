#include <iostream>
#include <string>
#include <iomanip>
#include "matrix.h"

using namespace std;

sparse_matrix *create(int m_size) {
  sparse_matrix *mp = new sparse_matrix();
  int i;
  for (i = 0; i < m_size; i++) {
    mp->row[i]=new node();
    mp->col[i]=new node();
  }
  return mp;
}

void read_matrix(sparse_matrix *m, int m_size, ifstream &inputFile) {
  cout << "unimplemented" << endl;
}

void write_matrix(sparse_matrix *m, int m_size) {
  cout << "unimplemented" << endl;  
}

void multiply(sparse_matrix *m1, sparse_matrix *m2, sparse_matrix *m, int m_size) {
  cout << "unimplemented" << endl;
}

