#include "matrix.h"
#include "sparse_helper.h"

using namespace std;

sparse_matrix *create(int m_size) {
  sparse_matrix *s = new sparse_matrix();
  for (int i = 0; i < m_size; i++) {
    s->first_in_row[i]=NULL;
    s->first_in_column[i]=NULL;
  }
  return s;
}

node *create_node(int i, int j, float elt) {
  node *entry = new node();
  entry -> row = i;
  entry -> column = j;
  entry -> element = elt;
  entry -> next_in_row = NULL;
  entry -> next_in_column = NULL;
  return entry; 
}

void read_matrix(sparse_matrix *m, int m_size, ifstream &inputFile) {
  float elt;
  node *entry;
  
  for (int i = 0; i < m_size; i++) {
    for (int j = 0; j < m_size; j++) {
      inputFile >> elt;
      if (elt != 0.0) {
        entry = create_node(i, j, elt);
        add_entry_to_row(m -> first_in_row[i], entry);
        add_entry_to_column(m -> first_in_column[j], entry);
      }
    }
  }
}

void write_matrix(sparse_matrix *m, int m_size) {
  for (int i = 0; i < m_size; i++) {
    write_row(m->first_in_row[i], m_size);
  }
}


void multiply(sparse_matrix *m1, sparse_matrix *m2, sparse_matrix *m, int m_size) {
  for(int i=0; i < m_size; i++) {
    for (int j=0; j < m_size; j++) {
      float product = cell_product(m1, m2, i, j, m_size);
      if (product != 0) {
        node *entry = create_node(i, j, product);
        add_entry_to_row(m -> first_in_row[i], entry);
        add_entry_to_column(m -> first_in_column[j], entry);
      }
    }
  }
}




