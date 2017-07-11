#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

// Consider quadratic Diophantine equations of the form:

// x^2 – Dy^2 = 1

// For example, when D=13, the minimal solution in x is 649^2 – 13×180^2 = 1.

// It can be assumed that there are no solutions in positive integers when D is square.

// By finding minimal solutions in x for D = {2, 3, 5, 6, 7}, we obtain the following:

// 32 – 2×22 = 1
// 22 – 3×12 = 1
// 92 – 5×42 = 1
// 52 – 6×22 = 1
// 82 – 7×32 = 1

// Hence, by considering minimal solutions in x for D ≤ 7, the largest x is obtained when D=5.

// Find the value of D ≤ 1000 in minimal solutions of x for which the largest value of x is obtained.

bool is_square(int d, vector<int> squares) {

  bool rval = 0;
  vector<int>::iterator it; 
  for(it = squares.begin() ; it < squares.end(); ++it) 
    if (*it == d) rval = 1;
  return rval;
}

long long search(int d, long long start_x, long long end_x, long long start_y, long long end_y) {

  long long rval = 0;
  bool solution_found = 0;

  for (long long y = 1; y < end_y; y++) {
    for (long long x = 1; x < end_x; x++) {
      if (x * x - d * y * y == 1) {
        rval = x;
        solution_found = 1;
        //        cout << "D = " << d << ", x = " << x << ", y = " << y << endl;
        y = end_y;
        x = end_x;
      }
    }
  }
  if (solution_found == 1) {
    return rval;
  }
  else {
    return -1;
  }
}

int main() {

  // Build an array of non-squares

  vector<int> squares;

  cout << "Building squares... " << endl;
  
  for (int i = 1; i*i <= 1000; i++) {
    squares.push_back(i*i);
  }
  
  int d=2;

  long long result[1001];
  long long max_x = 0;
  ifstream datafile;

  for (int i = 0; i < 1001; i++) {    
    result[i]=0;
    if (is_square(i, squares)) result[i]=0;
  }
  
  datafile.open("e66.data");

  datafile >> max_x;

  cout << "Reading datafile..." << endl;
  
  cout << "Max_x = " << max_x << " from file." << endl;

  while(! datafile.eof()) {
    int n;
    datafile >> n;
    result[n]=-1;
  }
    
  //  const unsigned long long MAX=9223372036854775807;
  cout << endl;
  cout << "Calculating... " << endl;

  int solutions_found = 0;
  int incr=10000;
  long long start_x=10000;
  long long start_y=10000;
  long long end_x=incr+start_x;
  long long end_y=incr+start_y;

  d = 2;
  while(d < 1001) {
    if (result[d] == -1) {
      cout << d << " " << flush;
      long long this_max = search(d, start_x, end_x, start_y, end_y);
      if (this_max != -1) {
        solutions_found ++;
        result[d] = this_max;
        cout << "D = " << d << ", x = " << this_max << endl;
      }
      max_x = max_x < this_max ? this_max : max_x;
    }
    d++;
    while (is_square(d,squares)) d++;
  }
  
  cout << endl;
  cout << solutions_found << " solutions found." << endl;

  cout << "remaining to be processed: " << endl;
  
  for (int i = 1; i < 1001; i++) {
    if (result[i] == -1) {
      cout << i << " ";
    }
  }
  cout << endl;
  cout << "max_x so far: " << max_x << endl;;
    
}
