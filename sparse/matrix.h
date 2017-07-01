#include <fstream>

using namespace std;

// this is unused, but needed for the driver

#ifndef MATRIX_H
#define MATRIX_H

const int MATRIX_SIZE=18;
const int TRUE=1;
const int FALSE=0;

struct Entry {
  int row;
  int column;
  float data;
  Entry *next_row;
  Entry *next_column;
  bool initialized = FALSE;
  Entry();
  Entry(int row, int column, float data);
  string detail();
  string format();
};

struct SparseMatrix {
  Entry *rows;
  Entry *columns;
  bool initialized = FALSE;
  SparseMatrix();
};

SparseMatrix *create(int m_size);
void read_matrix(SparseMatrix *m, int m_size, ifstream &inputFile);
void write_matrix(SparseMatrix *m, int m_size);
void multiply(SparseMatrix *m1, SparseMatrix *m2, SparseMatrix *m, int m_size);


#endif
