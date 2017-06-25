#include <iostream>
#include "matrix.h"
using namespace std;

int main() {
	float m1[MATRIX_SIZE][MATRIX_SIZE];  // 2D array to store matrix m1
	float m2[MATRIX_SIZE][MATRIX_SIZE];  // 2D array to store matrix m2
	ifstream datafile;   // input file stream object
	float m[MATRIX_SIZE][MATRIX_SIZE];   // 2D array to store the resulting matrix m

	// just curious what is in m1 without initialization
	cout << "m1 without initialization" << endl;
	write_matrix(m1, MATRIX_SIZE);
	cout << endl;

	// just curious what is in m2 without initialization
	cout << "m2 without initialization" << endl;
	write_matrix(m2, MATRIX_SIZE);
	cout << endl;

	// initialize the matrices m1,m2 to 0.0
	create(m1, MATRIX_SIZE);
	create(m2, MATRIX_SIZE);

	// print out m1 in the matrix format and it should be 0
	cout << "m1 after initialization" << endl;
	write_matrix(m1, MATRIX_SIZE);
	cout << endl;

	// print out m2 in the matrix format and it should be 0
	cout << "m2 after initialization" << endl;
	write_matrix(m2, MATRIX_SIZE);
	cout << endl;

	// open the data file to input the matrices
	datafile.open("data");

	// populate the 2D array with matrix data, m1, from the file
	read_matrix(m1, MATRIX_SIZE, datafile);
	cout << "m1 after populated from data file" << endl;
	write_matrix(m1, MATRIX_SIZE);
	cout << endl;

	// populate the 2D array with matrix data, m2, from the file
	read_matrix(m2, MATRIX_SIZE, datafile);
	cout << "m2 after populated from data file" << endl;
	write_matrix(m2, MATRIX_SIZE);
	cout << endl;

	// close the data file
	datafile.close();

	// perform multiplication`
	multiply(m1, m2, m, MATRIX_SIZE);
	cout << "multiplication result m" << endl;
	write_matrix(m, MATRIX_SIZE);

	return 0;
}
