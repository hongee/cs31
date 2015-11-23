#include <iostream>
#include <string>
using namespace std;

int main() {
  int units = 0;
  double price = 0.0, royalties = 0.0, nextUnitRate = 0.13;
  string title = "";
  string isPremium = "";

  //get inputs
  cout << "Units sent: ";
  cin >> units;
  cin.ignore(10000,'\n');
  cout << "Title: ";
  getline(cin, title);
  cout << "Base price: ";
  cin >> price;
  cin.ignore(10000,'\n');
  cout << "Premium item? (y/n): ";
  getline(cin, isPremium);
  cout << "---" << endl;

  //check for errors, if err, exit
  if(units < 0) {
    cout << "The number of units sent must be nonnegative." << endl;
    return 1;
  }

  if(title == "") {
    cout << "You must enter a title." << endl;
    return 1;
  }

  if(price < 0) {
    cout << "The base price must be nonnegative." << endl;
    return 1;
  }

  //almost messed up the logic here.
  if(isPremium != "y" && isPremium != "n") {
    cout << "You must enter y or n." << endl;
    return 1;
  } else if (isPremium == "y") {
    //set the next unit rate to the premium value if product is premium
    //save a few lines of code double checking for the premium-ness
    nextUnitRate = 0.16;
  }

  //calculate royalties
  if(units > 400) {
    royalties += (0.09 * price) * 400;
    if(units > 1200) {
      royalties += (nextUnitRate * price) * 800;
      royalties += (0.14 * price) * (units - 1200);
    } else {
      royalties += (nextUnitRate * price) * (units - 400);
    }
  } else {
    royalties = (0.09 * price) * units;
  }

  cout.setf(ios::fixed);
  cout.precision(2);
  cout << title << " earned $" << royalties << " in royalties." << endl;

  return 0;
}
