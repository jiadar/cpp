#include <iostream>
#include <string>
using namespace std;

void shrimp_alert(string burritos[], int burritos_sold[]) {
  const int NUMTYPES = 4;
  int i;
  for (i=0; i<NUMTYPES; i++) {
    if (burritos[i] == "shrimp" && burritos_sold[i] > 0) {
      cout << "A shrimp has been ordered! " << endl;
    }
  }
}


