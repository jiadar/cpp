// This helper contains various methods that enable the creation of the
// public methods for sparse matrix. 

#include <iostream>
#include <string>
#include <iomanip>
#include "matrix.h"
#include <sstream>

using namespace std;

// Initialization Constructors

Entry::Entry() {

  // Since we start with empty entries for the start of each row and column,
  // hold a boolean initialized to tell if the entry has real data in it, or
  // is just a stub
  
  initialized = FALSE;
}

sparse_matrix::sparse_matrix() {

  // To create a new sparse matrix, create entries for the rows and columns
  // and link them together up to matrix size
  
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

string format_float(float f) {

  // Utility function to format a float, to avoid duplicated code

  ostringstream o;
  o << setprecision(2) << fixed << setw(9) << f;
  return o.str();  
}

string Entry::detail() {

  // Prints detail of an entry, useful for debugging
  
  ostringstream o;
  o << "{";
  o << " row: " << this->row ;
  o << " col: " << this->column ;
  o << " data: " << this->data;
  o << "} ";
  return o.str();
}

string Entry::format() {
  return format_float(data);
}

// Helper functions

void set_entry(Entry *e, int row, int column, float data) {

  // Sets an entry at row, column to data value and initializes the entry
  
  e->row = row;
  e->column = column;
  e->data = data;
  e->initialized = TRUE;
}

void read_row(int r, Entry *row, int m_size, ifstream &inputFile) {

  // Reads a row from a file into the passed in row entry
  // To do this, we read a non-zero entry into the current entry
  // create a new entry and append that to next, and increment through
  // the list
  
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

void write_row(int r, Entry *row, int m_size, bool detail) {

  // Writes a row to the screen. We need to print 0's while writing,
  // and allow a detail flag for deubbing. Walk the columns in the row
  // printing the detail if requested, or the data using the format
  // helper function. 
  
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

  // Row write function that does not print detail

  write_row(r, row, m_size, FALSE);
}

Entry *get_entry(sparse_matrix *m, int row, int column) {

  // Get the entry at a particular row, col by walking the list
  // If there is no entry at row, col returns a NULL entry

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

float get_entry_data(sparse_matrix *m, int row, int column) {

  // Get the data for an entry at row, col by getting the entry using
  // the helper function, returning 0 if it is null and otherwise returning
  // the data
  
  Entry *e = get_entry(m, row, column);
  return e == NULL ? 0.0 : e->data;
}


float cell_product(sparse_matrix *m1, sparse_matrix *m2, int i, int j, int m_size) {

  // The chosen matrix multiplication method relies on this function to return the
  // matrix product for a given row (i) and column (j).

  // To compute a cell product for row, col use the following formula
  // sum from k=0 to m-1 of A(i,k) * B(k,j)

  // We use the get_entry_data function to get the arguments to multiply
  // This would be more efficient using a list iterator
  
  float sum = 0.0;
  
  for (int k=0; k < m_size; k++) 
    sum += get_entry_data(m1, i, k) * get_entry_data(m2, k, j);
  
  return sum;
}



