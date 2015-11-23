#include <iostream>
using namespace std;

int main() {
  double workHours = 0;
  double hourlyRate = 0.0;
  double totalPay = 0.0;

  /*
  double
  - about 10 to the -308 to 10 to the 308
    about 15 significant digits

  int
  - -2 billion to 2 billion

  Not too important unless for very high performance ops

  */

  cout << "How many hours do you work?";
  cin >> workHours;
  cout << endl << "What's the hourly rate?";
  cin >> hourlyRate;

  cout.setf(ios::fixed);
  cout.precision(2);

  totalPay = hourlyRate * workHours;

  cout << "You'll earn " << totalPay << endl;

}
