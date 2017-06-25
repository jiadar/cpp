#include <iostream>
#include <string>
using namespace std;

int main()
{
  string teams[2];
  int runs[2];
  bool low_scores[2];
  char prompt = 'n';

  do {
  for(int i=0; i<2; i++) {
    cout << "What is the name of the baseball team #" << i+1 << "? ";
    getline(cin, teams[i]);
    cout << "What is the score for " << teams[i] << "? ";
    cin >> runs[i];
    cin.ignore();
    low_scores[i] = runs[i] < 3;
  }

  int winner = runs[0] > runs[1] ? 0 : 1;

  for(int i=0; i<2; i++) {
    cout << "Team " << teams[i] << " scored " << runs[i] << " runs." << endl;
    if (low_scores[i]) {
      cout << teams[i] << " had a low score." << endl;
    } 
  }

  cout << teams[winner] << " was the winner! " << endl;

  cout << "Would you like to go again (y/n)? ";
  cin >> prompt;

  } while (prompt == 'y');
  
  return 0;
}
  
