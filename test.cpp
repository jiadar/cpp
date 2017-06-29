#include <iostream>

using namespace std;

int main() {
  int a[3][3];
  int i,j;
  for (i=0; i<3; i++) {
    for (j=0; j<3; j++)
      a[i][j]=i+j;
  }
  for (i=0; i<3; i++) {
    for (j=0; j<3; j++)
      cout << a[i][j];
  cout << endl;
  }  
}
