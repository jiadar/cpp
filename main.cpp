#include <iostream>
#include <string>
#include "shrimp_alert.h"

using namespace std;

int main() {
	const int NUMTYPES = 4;
	string burritos[] = {"carnitas", "beef", "shrimp", "veg"};
	int burritos_sold[] = {0, 0, 0, 0};
	int total_sold = 0, most_sold, i;


	for (i=0; i<NUMTYPES; i++) {
	   cout << "number of " << burritos[i] << " sold : ";
	   cin >> burritos_sold[i];
	   total_sold += burritos_sold[i];
	   if (i == 0)
	      most_sold = burritos_sold[i];
	   else if (burritos_sold[i] > most_sold)
	      most_sold = burritos_sold[i];
	}

	for (i=0; i<NUMTYPES; i++)
	   if (most_sold == burritos_sold[i])
	      cout << burritos[i] << " sold " << burritos_sold[i] << " most" << endl;
	   else
	      cout << burritos[i] << " sold " << burritos_sold[i] << endl;

	cout << "total number of burritos sold " << total_sold << endl;

        shrimp_alert(burritos, burritos_sold);
        
	return 0;
}

