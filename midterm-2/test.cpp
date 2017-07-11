#include <iostream>
#include <iomanip>
using namespace std;

// #include <iostream>
// #include <cstring>

// class libraryBook{
// private:
//   char title[80];
//   int available;

// public:
//   void enterBook(char initTitle[]);
//   void borrowBook();
//   void returnBook();
//   void displayStatus();
// };

// void libraryBook::enterBook(char initTitle[]){
//   strcpy(title,initTitle);
//   available = 1;
// }

// void libraryBook::borrowBook() {
//   available = 0;
// }

// void libraryBook::returnBook() {
//   available = 1;
// }

// void libraryBook::displayStatus() {
//   cout << title << "=" << available << endl;
// }

// int main() {
//   libraryBook b1;
//   libraryBook b2;
//   b1.enterBook("Computing");
//   b2.enterBook("Writing");
//   b2.displayStatus();
//   b2.borrowBook();
//   b2.displayStatus();
//   b2.returnBook();
//   b2.displayStatus();
//   b1.displayStatus();
//   return 0;
// }

struct Employee {
  int id_num;
  double pay_rate;
  double hours;
};

int main() {
  Employee emps[100];
  for (int i=0; i<100; i++) {
    emps[i].hours = 1;
  }
  double total=0;
  for (int j=0; j<100; j++) {
    total+= emps[j].hours;
  }
  cout << total;
}
// double pay(Employee *e) {
//   return e->pay_rate * e->hours;
// }

// int main() {
//   Employee *cody = new Employee();
//   cody->id_num=12312;
//   cody->pay_rate=15;
//   cody->hours=10;
//   cout << pay(cody);
// }
  
// int main() {
//   char *c = "TestMe";
//   int i=0;
//   while (c[i]!=0) {
//     i++;
//   }
//   cout << i << endl;
//   c[i-1]=0;
//   cout << c << endl;
// }

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
