#include <fstream>
#include "matrix.h"

using namespace std;

#ifndef SPARSE_HELPER_H
#define SPARSE_HELPER_H

void set_entry(Entry *e, int row, int column, float data);
void read_row(int r, Entry *row, int m_size, ifstream &inputFile);
void write_row(int r, Entry *row, int m_size, bool detail);
void write_row(int r, Entry *row, int m_size);
float get_entry_data(sparse_matrix *m1, int row, int column);
float cell_product(sparse_matrix *m1, sparse_matrix *m2, int i, int j, int m_size);

#endif

