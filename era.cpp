#include <iostream>
using namespace std;

int main()
{
  int innings, runs;

  cout << "How many innings were pitched? ";
  cin >> innings;
  cout << "How many runs were given up? ";
  cin >> runs;

  float era = runs * 9.0/innings;
  cout << "The ERA is " << era << endl;

  return 0;

                                               
}
  
