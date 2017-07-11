// Sparse Matrix struct and method definitions 

#ifndef MATRIX_H
#define MATRIX_H

#include <fstream>
#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>

using namespace std;

const int MATRIX_SIZE=18;

struct node {
  float element;
  int row;
  int column;
  node *next_in_row;
  node *next_in_column;
};

struct sparse_matrix {
  node *first_in_row[MATRIX_SIZE];
  node *first_in_column[MATRIX_SIZE];
};

  
sparse_matrix *create(int m_size);
void read_matrix(sparse_matrix *m, int m_size, ifstream &inputFile);
void write_matrix(sparse_matrix *m, int m_size);
void multiply(sparse_matrix *m1, sparse_matrix *m2, sparse_matrix *m, int m_size);

#endif
