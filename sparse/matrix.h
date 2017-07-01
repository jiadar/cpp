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

struct sparse_matrix {
  Entry *rows;
  Entry *columns;
  bool initialized = FALSE;
  sparse_matrix();
};

sparse_matrix *create(int m_size);
void read_matrix(sparse_matrix *m, int m_size, ifstream &inputFile);
void write_matrix(sparse_matrix *m, int m_size);
void multiply(sparse_matrix *m1, sparse_matrix *m2, sparse_matrix *m, int m_size);

#endif
