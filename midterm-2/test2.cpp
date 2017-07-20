#include <iostream>
#include <iomanip>
using namespace std;

  int getI(int initialize=0, int loopend=3) {
    for(int i=0; i<loopend;i++) {
      int inside=initialize;
      inside+=i;
      cout << inside << "," << i << endl;
      if (inside==6) return i;
    }
    return 0;
  }

int main() {
  int returnval;
  returnval=getI(3);
  cout << returnval << endl;
}
