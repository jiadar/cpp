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

string Entry::format() {
  ostringstream o;
  o << setprecision(2) << fixed << setw(7) << data;
  return o.str();
}

void write_row(int r, Entry *row, int m_size, bool detail) {
  int i=0;
  Entry *cur = row;

  while(i < m_size) {
    if (cur->column == i && cur->initialized) { 
      cout << (detail ? cur->detail() : cur->format());
      cur=cur->next_column;
    }
    else cout << (detail ? "" : cur->format());
    i++;
  }
  cout << endl;
}

void write_row(int r, Entry *row, int m_size) {
  write_row(r, row, m_size, FALSE);
}

void link_entry(Entry *e1, Entry *e2) {
  // Link e1's column entry to e2 (go down column e1 -> e2)
  
}
