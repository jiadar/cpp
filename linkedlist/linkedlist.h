#include <fstream>

using namespace std;

// this is unused, but needed for the driver

const int MATRIX_SIZE=18;

struct Node {
  float data;
  Node *next;
  bool initialized = 0;
  Node();
};

struct Column {
  int c;
  Column *next;
  float data;
};

struct Row {
  int r;
  Column *columns;
  Row *next;
};

struct SparseMatrix {
  Row *rows;
};

Node *create();
void write_list(Node *head);
void read_list(Node *head, int m_size, ifstream &inputfile);
