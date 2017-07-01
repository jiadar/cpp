#include <iostream>
#include <string>
#include <iomanip>
#include "matrix.h"
#include <sstream>

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

void set_entry(Entry *e, int row, int column, float data) {
  e->row = row;
  e->column = column;
  e->data = data;
  e->initialized = TRUE;
}

void read_row(int r, Entry *row, int m_size, ifstream &inputFile) {

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

string Entry::detail() {
  ostringstream o;
  o << "{";
  o << " row: " << this->row ;
  o << " col: " << this->column ;
  o << " data: " << this->data;
  o << "} ";
  return o.str();
}

string format_float(float f) {
  ostringstream o;
  o << setprecision(2) << fixed << setw(9) << f;
  return o.str();  
}

string Entry::format() {
  return format_float(data);
}

void write_row(int r, Entry *row, int m_size, bool detail) {
  int i=0;
  Entry *cur = row;

  while(i < m_size) {
    if (cur->column == i && cur->initialized) { 
      cout << (detail ? cur->detail() : cur->format());
      cur=cur->next_column;
    }
    else cout << (detail ? "" : format_float(0));
    i++;
  }
  cout << endl;
}

void write_row(int r, Entry *row, int m_size) {
  write_row(r, row, m_size, FALSE);
}

Entry *get_entry(SparseMatrix *m, int row, int column) {
  Entry *cur = m->rows;
  while (cur != NULL) {
    if (cur->row == row) {
      while (cur != NULL && cur->initialized) {
        if (cur->column == column) 
          return cur;
        cur=cur->next_column;
      }
    }
    cur=cur->next_row;
  }
  return NULL;
}

float get_entry_data(SparseMatrix *m, int row, int column) {
  Entry *e = get_entry(m, row, column);
  return e == NULL ? 0.0 : e->data;
}


float cell_product(SparseMatrix *m1, SparseMatrix *m2, int i, int j, int m_size) {

  // The chosen matrix multiplication method relies on this function to return the
  // matrix product for a given row (i) and column (j).

  // To compute a cell product for row, col use the following formula
  // sum from k=0 to m-1 of A(i,k) * B(k,j)

  float sum = 0.0;
  
  for (int k=0; k < m_size; k++) {
    float a, b;
    a = get_entry_data(m1, i, k);
    b = get_entry_data(m2, i, k);
    sum += a * b;
    cout << i << "," << k << " : sum += " << a << " * " << b << " = " << sum << endl;
  }
  cout << "sum for " << i << "," << j << ": " << sum << endl;
  return sum;
}



