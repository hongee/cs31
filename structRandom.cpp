#include <iostream>
#include <string>
using namespace std;

//data members - name/salary/age
//fields
//attributes
//instance variables

struct Employee {

  string name;
  double salary;
  int age;
  int attempts;

  Employee(string n="", double sal=0.0, int a=0) {
    name = n;
    salary = sal;
    age = a;
    attempts = 0;
  }

  void doubleMySalary() {
    if(attempts < 2) {
      cout << "You wish!" << endl;
      attempts++;
    }
    else {
      cout << "Fine." << endl;
      salary*=2;
    }
  }

};

int main() {
  Employee jack("Henry Samueli", 9.99, 100);
  Employee *jack_p = &jack;
  jack_p->doubleMySalary();
  (*jack_p).doubleMySalary();
  jack.doubleMySalary();
  cout << &jack << endl;
}
