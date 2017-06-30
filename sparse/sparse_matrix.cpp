#include <iostream>
#include <string>
#include <iomanip>
#include "matrix.h"

using namespace std;

Entry::Entry() {
  initialized = FALSE;
}


SparseMatrix::SparseMatrix() {
  rows = new Entry();
  columns = new Entry();
  initialized = FALSE;

  Entry *cur_row = rows;
  Entry *cur_column = columns;

  for (int i = 0; i < MATRIX_SIZE; i++) {
    cur_row->next_row = new Entry();
    cur_row=cur_row->next_row;
    cur_column->next_column = new Entry();
    cur_column=cur_column->next_column;
  }
  
  initialized=TRUE;

}

SparseMatrix *create(int m_size) {
  return new SparseMatrix();
}

void write_column(Entry *column, int m_size) {
  // float elt;
  // for (int i = 0; i < m_size; i++) {
  //   if (column==NULL) {
  //     elt = 0.00;      
  //   }
  //   else {
  //     cout << "P";
  //     elt = column->c == i ? column->data : 0;
  //     column=column->next;
  //   }
  //   cout << elt << " ";
  // }
  cout << "unimplemented" << endl;
}


void set_entry(Entry *e, int row, int column, float data) {
  e->row = row;
  e->column = column;
  e->data = data;
  e->initialized = TRUE;
}

void read_row(int r, Entry *row, int m_size, ifstream &inputFile) {

  // Reads the current row of the fstream

  float elt;
  int i;
  Entry *cur = row;
  
  for (i = 0; i < m_size; i++) {
    inputFile >> elt;
    if (elt != 0.0) {
      set_entry(cur, r, i, elt);
      cur->next_column = new Entry();
      cur = cur->next_column;
    }
  }
}


void read_matrix(SparseMatrix *m, int m_size, ifstream &inputFile) {
  Entry *cur_row = m->rows;

  for (int i = 0; i < m_size; i++) {
    read_row(i, cur_row, m_size, inputFile);
    cur_row=cur_row->next_row;
  }
}

void write_row(int r, Entry *row, int m_size) {
  int i=0;
  Entry *cur = row;

  while(i < m_size) {
    float elt = cur->column == i ? cur->data : 0.00;
    cout << setprecision(2) << fixed << setw(7) << elt << " ";
    if (elt != 0)
      cur=cur->next_column;
    i++;
  }
  cout << endl;
}

  

void write_matrix(SparseMatrix *m, int m_size) {
  Entry *cur_row = m->rows;

  for (int i = 0; i < m_size; i++) {
    write_row(i, cur_row, m_size);
    cur_row=cur_row->next_row;
  }
  
}

void multiply(SparseMatrix *m1, SparseMatrix *m2, SparseMatrix *m, int m_size) {
  cout << "unimplemented" << endl;
}

