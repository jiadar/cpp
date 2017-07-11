#include "matrix.h"

#ifndef SPARSE_HELPER_H
#define SPARSE_HELPER_H

string format_float(float f);
void node_detail(node *n);
void link_row(node *head, node *entry);
void link_column(node *head, node *entry);
void add_entry_to_row(node *&head, node *entry);
void add_entry_to_column(node *&head, node *entry);
void write_row(node *head, int m_size);
float get_node_data(sparse_matrix *m, int row, int col);
float cell_product(sparse_matrix *m1, sparse_matrix *m2, int i, int j, int m_size);

#endif

