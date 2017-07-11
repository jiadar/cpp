// This file contains utility functions to support the sparse_matrix

#include "matrix.h"
#include "sparse_helper.h"

using namespace std;

// Create a new node with row i, column j, and element elt

node *create_node(int i, int j, float elt) {
  node *entry = new node();
  entry -> row = i;
  entry -> column = j;
  entry -> element = elt;
  entry -> next_in_row = NULL;
  entry -> next_in_column = NULL;
  return entry; 
}

// Utility function to format a float, to avoid duplicated code

string format_float(float f) {

  ostringstream o;
  o << setprecision(2) << fixed << setw(9) << f;
  return o.str();  
}

// Detail a node's contents for debugging

void node_detail(node *n) {
  if (n == NULL) {
    cout << "{ NULL }" << endl;
    return;
  }
  cout << "{element: " << n->element << ", " ;
  cout << "row: "<< n->row << ", ";
  cout << "column: "<< n->column<< "} " << endl;
}

// Link a node entry to the end of the row list at head

void add_entry_to_row(node *&head, node *entry) {
  if (head == NULL) { 
    head  = entry;
  }        
  else {
    node *cur = head;
    while (cur->next_in_row != NULL) 
      cur = cur -> next_in_row;
    cur -> next_in_row = entry;
  } 
}

// Link a node entry to the end of the column list at head

void add_entry_to_column(node *&head, node *entry) {
  if (head == NULL) { 
    head  = entry;
  }        
  else {
    node *cur = head;
    while (cur->next_in_column != NULL) 
      cur = cur -> next_in_column;
    cur -> next_in_column = entry;
  } 
}

// Write a row at head to the console

void write_row(node *head, int m_size) {

  node *cur = head;
  for (int i=0; i < m_size; i++) {
    if (cur == NULL) {
      cout << format_float(0.0);
    }
    else {
      if (cur->column == i) {
        cout << format_float(cur -> element);
        cur = cur -> next_in_row;
      }
      else
        cout << format_float(0.0);      
    }
  }
  cout << endl;
}

// Get the data for the node at row, col in matrix m

float get_node_data(sparse_matrix *m, int row, int col) {
  node *cur = m -> first_in_row[row];
  while (cur != NULL) {
    if (cur -> row == row && cur -> column == col)
      return cur -> element;
    cur = cur -> next_in_row;
  }
  return 0;
}

// Compute the cell product

float cell_product(sparse_matrix *m1, sparse_matrix *m2, int i, int j, int m_size) {

  // The chosen matrix multiplication method relies on this function to return the
  // matrix product for a given row (i) and column (j).

  // To compute a cell product for row, col use the following formula
  // sum from k=0 to m-1 of A(i,k) * B(k,j)

  // We use the get_entry_data function to get the arguments to multiply
  // This would be more efficient using a list iterator
  
  float sum = 0.0;
  
  for (int k = 0; k < m_size; k++) 
    sum += get_node_data(m1, i, k) * get_node_data(m2, k, j);
  
  return sum;
}

