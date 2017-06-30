#include <fstream>

using namespace std;

// this is unused, but needed for the driver

const int MATRIX_SIZE=18;

struct Node {
  float data;
  int r;
  int c;
  Node *next_col;
  Node *next_row;
  Node();
  Node(int row, int col, float elt);
};

struct SparseMatrix {
  Node *head;
  SparseMatrix();
};

SparseMatrix *create(int m_size);
void read_matrix(SparseMatrix *m, int m_size, ifstream &inputFile);
void write_matrix(SparseMatrix *m, int m_size);
void multiply(SparseMatrix *m1, SparseMatrix *m2, SparseMatrix *m, int m_size);



