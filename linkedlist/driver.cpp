#include <iostream>
#include "linkedlist.h"
using namespace std;

int main() {

  // this was changed.. change it back
  
  Node *head;  
  ifstream datafile;  

  head = create();

  cout << "List after create: " << endl;
  write_list(head);

  cout << endl;

  datafile.open("data");

  read_list(head,MATRIX_SIZE,datafile);

  cout << "After reading: " << endl;
  write_list(head);
//   cout << "m1 after populated from data file" << endl;
//   write_matrix(m1,MATRIX_SIZE);
//   cout << endl;

//   // populate the 2D array with matrix data, m2, from the file
//   read_matrix(m2,MATRIX_SIZE,datafile);
//   cout << "m2 after populated from data file" << endl;
//   write_matrix(m2,MATRIX_SIZE);
//   cout << endl;

//   // close the data file
//   datafile.close();
//   // create the resultant matrix
//   m = create(MATRIX_SIZE);

//   // m = m1 * m2
//   multiply(m1, m2, m, MATRIX_SIZE);

//   cout << "m after multiplication between m1 and m2" << endl;
//   write_matrix(m,MATRIX_SIZE);
//   cout << endl;

//   return 0;
// }

  return 0;
}
