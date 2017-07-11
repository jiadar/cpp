#include <stdio.h>

void truncate(char *c) {
  int length=0;
  while (c[length]!=0) {
    length++;
  }
  c[length-1]=0;
}

int main() {
  char c[10] = {'T', 'e', 's', 't', 'm', 'e'};
  truncate(c);
  printf("c = %s\n", c);
}

/* int main() { */
/*   char *c = "TestMe"; */
/*   int i=0; */
/*   while (c[i]!=0) { */
/*     i++; */
/*   } */
/*   printf("%d\n", i); */
/*   printf("%s\n", c); */
/*   char d[i]; */
/*   int j; */
/*   for(j=0; j<i; j++) { */
/*     d[j] = c[j]; */
/*   } */
/*   d[j-1] = 0; */
/*   printf("c = %s\n", c); */
/*   printf("d = %s\n", d); */
/*   //  cout << c << endl; */
/* } */

// int main()
// {
//   char *c = "Testy";
//   char *d; 
//   int i = 0;
//   while (c[] != 0) {
//     d[i]=c[i+1]
//     cout << (c[i+1]) << endl;
//     i++;
//   }
//   cout << i << endl;
//   *p=c[i-1];
//   p='\0';
//   //cout << c;

// }

// class student {
// private: 
//   int id;
//   double grade_points;
//   double credits;
// public:
//   void initStudent();
//   void initStudent(int i, double g, double c);
//   void showGpa();
// };

// void student::initStudent(int i, double g, double c) {
//   id=i;
//   grade_points=g;
//   credits=c;  
// }

// void student::initStudent() {
//   initStudent(-1, 0.0, 0.0);
// }

// void student::showGpa() {
//   cout << "ID " << id << ", GPA ";
//   cout << fixed << setprecision(1) << (credits == 0 ? 0.0 : grade_points/credits) << endl;
// }

// int main() {
//   student aStudent;
//   student anotherStudent;
//   aStudent.initStudent(5555,120.0, 37.5);
//   anotherStudent.initStudent();
//   aStudent.showGpa();
//   anotherStudent.showGpa();
//   return 0;
// }
