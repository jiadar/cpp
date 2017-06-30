#include <iostream>
#include <string>
#include <iomanip>
#include "matrix.h"

using namespace std;

Node::Node() {
  next_row = NULL;
  next_col = NULL;
  data = 0.0;
}

Node::Node(int row, int col, float elt) {
  r = row;
  c = col;
  data = elt;
  next_row = NULL;
  next_col = NULL;  
}


SparseMatrix::SparseMatrix() {
  int i;
  head = new Node();
  Node *cur_row = head;
  Node *cur_col = head;
  for (i = 0; i < MATRIX_SIZE; i++) {
    cur_row->next_row = new Node();
    cur_col->next_col = new Node();
    cur_row = cur_row->next_row; 
    cur_col = cur_col->next_col;     
  }
  cout << "New Matrix Created with Size " << MATRIX_SIZE << endl;
}

SparseMatrix *create(int m_size) {
  return new SparseMatrix();
}

void add_next_entry(SparseMatrix m, int row, int col, float elt) {

  if (elt == 0) 
    return;

  // Make a new node for this entry

  Node *next_entry = new Node(row, col, elt);
  
  int i=0, j=0;
  Node *cur = m.head;

}

void read_matrix(SparseMatrix *m, int m_size, ifstream &inputFile) {
  // Using the given stream object, read the matrix from the file and
  // insert it into the matrix array

  float elt;
  int i, j;
  for(i = 0; i < m_size; i++) {
    for (j = 0; j < m_size; j++) {
      inputFile >> elt;
      add_next_entry(*m, i, j, elt);
    }
  }
}

void write_matrix(SparseMatrix *m, int m_size) {
  Node *cur_col = m->head;
  Node *cur_row = m->head;
  int i, j;
  float elt;
  for (i = 0; i < m_size; i++) {
    for (j = 0; j < m_size; j++) {
      if (cur_col->r == i && cur_col ->c == j) {
        elt = cur_col->data;         
        cur_col = cur_col->next_col == NULL ? NULL : cur_col->next_col;
      }
      else {
        elt = 0.0;
      }
      cout << fixed << setw(9) << setprecision(2) << elt << " ";  
    }
    cout << endl;
    cur_row = cur_row->next_row;
    cur_col = cur_row;
  }
}

void multiply(SparseMatrix *m1, SparseMatrix *m2, SparseMatrix *m, int m_size) {
  cout << "unimplemented" << endl;
}

