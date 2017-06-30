#include <iostream>
#include <string>
#include <iomanip>
#include "matrix.h"

using namespace std;


SparseMatrix *create(int m_size) {
  SparseMatrix s;
  s.rows = new Row();
  Row *rows = s.rows;
  rows->r = 0;
  for (int i = 1; i < MATRIX_SIZE; i++) {
    rows->next = new Row();
    rows->next->r = i;
    cout << "created row " << rows->r << endl;
  }
  //cout << "New Matrix Created with Size " << MATRIX_SIZE << endl;
  return new SparseMatrix();
}

void write_column(Column *column, int m_size) {
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
}

void read_matrix(SparseMatrix *m, int m_size, ifstream &inputFile) {

  // float elt;
  // Row *row = m->rows;
  // Column *column = row->columns;
  // Column *temp;
  // int i, j;

  // for (i = 0; i < m_size; i++) {
  //   column = row->columns;
  //   cout << "Row " << i << ": ";
  //   for (j = 0; j < m_size; j++) {
  //     inputFile >> elt;
  //     if (elt != 0) {
  //       if (column == NULL)  {
  //         column = new Column(j, elt);
  //         cout << "N";
  //       }
  //       else {
  //         temp = new Column(j, elt);
  //         column->next = temp;
  //         column = column->next;
  //         cout << "X";
  //       }
  //     }
  //     else {
  //       cout << "z";
  //     }
  //   }
  //   write_column(row->columns, m_size);
  //   row = row->next;
  //   cout << endl;
  // }
}


void write_matrix(SparseMatrix *m, int m_size) {
}

void multiply(SparseMatrix *m1, SparseMatrix *m2, SparseMatrix *m, int m_size) {
  cout << "unimplemented" << endl;
}

