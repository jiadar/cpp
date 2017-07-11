#include <fstream>

using namespace std;

const int MATRIX_SIZE=18;

void create(float m[][MATRIX_SIZE], int row_size);
void read_matrix(float m[][MATRIX_SIZE],int row_size, ifstream& inputFile);
void write_matrix(const float m[][MATRIX_SIZE], int row_size);
void multiply(float m1[][MATRIX_SIZE], float m2[][MATRIX_SIZE], float m[][MATRIX_SIZE], int row_size);


