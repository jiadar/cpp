#include <fstream>

using namespace std;

// this is unused, but needed for the driver

const int MATRIX_SIZE=18;

struct Column {
  int col;
  Column *next;
};

struct Row {
  int row;
  Column *columns;
  Row *next;
};

struct SparseMatrix {
  Row *rows;
  SparseMatrix();
};

SparseMatrix *create(int m_size);
void read_matrix(SparseMatrix *m, int m_size, ifstream &inputFile);
void write_matrix(SparseMatrix *m, int m_size);
void multiply(SparseMatrix *m1, SparseMatrix *m2, SparseMatrix *m, int m_size);



