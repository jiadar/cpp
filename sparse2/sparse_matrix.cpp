#include "matrix.h"

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

string format_float(float f) {

  // Utility function to format a float, to avoid duplicated code

  ostringstream o;
  o << setprecision(2) << fixed << setw(9) << f;
  return o.str();  
}

void node_detail(node *n) {
  if (n == NULL) {
    cout << "{ NULL }" << endl;
    return;
  }
  cout << "{element: " << n->element << ", " ;
  cout << "row: "<< n->row << ", ";
  cout << "column: "<< n->column<< "} " << endl;
}

void link_row(node *head, node *entry) {
  node *cur = head;
  while (cur->next_in_column != NULL ) {
    cur = cur -> next_in_column;
  }
  cur -> next_in_column = entry;
}

void link_column(node *head, node *entry) {

  node *cur = head;
  while (cur->next_in_row != NULL ) {
    cur = cur -> next_in_row;
  }
  cur -> next_in_row = entry;  
}


void read_matrix(sparse_matrix *m, int m_size, ifstream &inputFile) {
  float elt;
  node *entry;
  
  for (int i = 0; i < m_size; i++) {
    for (int j = 0; j < m_size; j++) {
      inputFile >> elt;
      if (elt != 0.0) {
        entry = create_node(i, j, elt);

        if (m -> first_in_row[i] == NULL) { 
          m -> first_in_row[i] = entry;
        }        
        else {
          node *cur = m->first_in_row[i];
          while (cur->next_in_row != NULL) {
            cur = cur -> next_in_row;
          }
          cur -> next_in_row = entry;
        }

        if (m -> first_in_column[j] == NULL) {
          m -> first_in_column[j] = entry;
        }
        else {
          node *cur = m->first_in_column[i];
          while (cur->next_in_column != NULL) {
            cur = cur -> next_in_column;
          }
          cur -> next_in_column = entry;
        }
      }
    }
  }
}

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

void write_matrix(sparse_matrix *m, int m_size) {
  for (int i = 0; i < m_size; i++) {
    write_row(m->first_in_row[i], m_size);
  }
}

void multiply(sparse_matrix *m1, sparse_matrix *m2, sparse_matrix *m, int m_size) {
  // for(int i=0; i < m_size; i++) {
  //   for (int j=0; j < m_size; j++) {
  //     float product = cell_product(m1, m2, i, j, m_size);
  //     if (product != 0) {
  //       node *entry = create_node(i, j, product);
  //     }
  //   }
  // }

  //       cur_col->next_column = new Entry();
  //       cur_col = cur_col->next_column;
  //     }
  //   }
  //   cur_row=cur_row->next_row;
  //   cur_col=cur_row;
  // }
}




