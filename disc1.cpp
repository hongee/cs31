#include <string>
#include <iostream>
using namespace std;

int main() {
  cout << "What is your name? ";
  string myName;
  getline(cin, myName);

  

  cout << "What is your quest? ";
  string myQuest;
  getline(cin, myQuest);

  cout << "Your name is " << myName << " and you want to " << myQuest << endl;

}
